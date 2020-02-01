#include "ServerSetting.h"

ServerSetting::ServerSetting(QObject *parent)
	: QObject(parent),
	serverAddress("127.0.0.1"),
	serverPort(5666),
	iniFileName("ChatServer.ini"),
	serverInfo(ServerInfo("server","ro server"))
{
	getSetting();
}

ServerSetting::~ServerSetting()
{
	saveSetting();
}

void ServerSetting::getSetting()
{
	QSettings set(iniFileName, QSettings::IniFormat);
	this->serverAddress = set.value("address", serverAddress).toString();
	this->serverPort = set.value("port", serverPort).toInt();
	auto bytes = set.value("info", QByteArray()).toByteArray();
	this->serverInfo.fromBytes(bytes);
	
	return ;
}

void ServerSetting::saveSetting()
{
	QSettings set(iniFileName, QSettings::IniFormat);
	set.setValue("address", serverAddress);
	set.setValue("port", serverPort);
	set.setValue("info", serverInfo.toBytes());
	

}
