#include "ServerInfo.h"
#include <iostream>
using namespace std;

ServerInfo::ServerInfo() :
	UserInfoProtocol()
{
	this->setDocument();
}

ServerInfo::ServerInfo(QString name, QString nick_name):
	UserInfoProtocol(name,nick_name)
{
	createUuid();
	//setUserInfoProtocol(name, nick_name);
	this->setDocument();

}

ServerInfo::~ServerInfo()
{
	cout << "in ~ServerInfo" << endl;
}

QJsonObject ServerInfo::appendToSonsJson(QJsonObject* obj)
{
	
	return *obj;
}

void ServerInfo::appendToSonsValue(QJsonObject* obj)
{
	return;
}

void ServerInfo::setServerInfo(QString name, QString nick_name)
{
	UserInfoProtocol::setUserInfoProtocol(name, nick_name);
	this->setDocument();
}


