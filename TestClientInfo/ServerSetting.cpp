#include "ServerSetting.h"

ServerSetting::ServerSetting(const ServerSetting& newServer):
	QObject(newServer.parent()),
	iniFileName(newServer.iniFileName),
	serverAddress(newServer.serverAddress),
	serverPort(newServer.serverPort),
	serverInfo(newServer.serverInfo)
{
}

ServerSetting::ServerSetting(QObject *parent)
	: QObject(parent),
	serverAddress("127.0.0.1"),
	serverPort(5666),
	iniFileName("ChatServer.ini"),
	serverInfo(ServerInfo("server","ro server"))
{
	loadSetting();
}

ServerSetting::~ServerSetting()
{
	saveSetting();
}

void ServerSetting::loadSetting()
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
