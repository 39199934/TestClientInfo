#include "ClientInfo.h"

ClientInfo::ClientInfo():
	UserInfoProtocol(),
	password(QString())
{
	//this->password = QString();
	this->setDocument();
}

ClientInfo::ClientInfo(QString name, QString nick_name, QString pass_word):
	UserInfoProtocol(name,nick_name),
	password(pass_word)
{
	
	//setUserInfoProtocol(name, nick_name, pass_word);
	this->setDocument();
	createUuid();
}

QJsonObject ClientInfo::appendToSonsJson(QJsonObject* obj)
{
	obj->insert("password", this->password);
	return *obj;
}

void ClientInfo::appendToSonsValue(QJsonObject* obj)
{
	this->password = obj->value("password").toString();
}

void ClientInfo::setClientInfo(QString name, QString nick_name, QString pass_word)
{
	UserInfoProtocol::setUserInfoProtocol(name, nick_name);
	this->password = pass_word;
	this->setDocument();
}
