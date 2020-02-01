#include "Message.h"
#include <iostream>
#include <Windows.h>
using namespace std;

Message::Message(QObject *parent)
	: QObject(parent),
	head(nullptr),
	body(nullptr)
{
	
}
Message::Message(const Message& newM):
	QObject(nullptr),
	head(newM.head),
	body(newM.body)
{

}

Message::Message(BodyProtocol* new_body, QObject* parent):
	QObject(parent),
	body(new_body)
{
	head = new MessageHead();
	head->setHeadSize(body->getSize());
	//head = &h;
}

Message::~Message()
{
	cout << "del message" << endl;
	if (head) {
		delete head;
	}
	if (body) {
		delete body;
	}
}

void Message::send(QTcpSocket* socket)
{
	socket->write(head->toBytes(),head->getSize());
	socket->waitForBytesWritten(3000);
	
	//Sleep(4000);
	socket->flush();
	socket->write(body->toBytes());
}
