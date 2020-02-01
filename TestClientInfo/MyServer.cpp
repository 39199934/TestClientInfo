#include "MyServer.h"

MyServer::MyServer(QObject *parent)
	: QTcpServer(parent),
	setting(ServerSetting())
{
	setting.loadSetting();

}

MyServer::~MyServer()
{
}

void MyServer::start()
{
	this->listen(QHostAddress::Any, setting.serverPort);
}

void MyServer::stop()
{
	this->close();
}
