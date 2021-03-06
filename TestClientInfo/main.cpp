#include <QtCore/QCoreApplication>
#include "ClientInfo.h"
#include "ServerInfo.h"
#include "MessageHead.h"
#include <iostream>
#include <QDebug>
#include "TextBody.h"
#include "Message.h"
#include "CommandBody.h"
#include "ServerSetting.h"
#include "MyServer.h"
#include "MyClient.h"
using namespace std;

void viewDoc(BagProtocol * user) {
	auto str = user->getBag().toJson().toStdString();
	//printf(str.c_str);
	cout << user->getBag().toJson().toStdString() << endl;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QJsonArray ar;
	ClientInfo c1("ro", "hshs", "12345");
	qDebug() << c1.getBag().object();
	ar.insert(0, c1.getBag().object());
	ar.insert(1, c1.getBag().object());

	qDebug() <<"command detail:"<< ar;
	CommandBody cm("request", "login", ar, "client", "server");
	//cm.saveToFile("test");
	//viewDoc(&cm);
	//viewDoc(&c1);
	CommandBody cm2;
	//cm2.loadFromFile("test");
	//viewDoc(&cm2);
	//MyServer* server = new MyServer(nullptr);
	auto msg = Message(&cm, nullptr);
	MyClient* c = new MyClient(nullptr);
	c->connectToHost("127.0.0.1", 5666);
	msg.send(c);
	///c->close();


	
	return a.exec();
}
//