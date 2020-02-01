#include "UserInfoProtocol.h"

UserInfoProtocol::UserInfoProtocol():
	BagProtocol()
{
	/*this->name = QString();
	this->nickName = QString();
	this->uuid = QString();*/
	setUserInfoProtocol(QString(), QString());
	
}

UserInfoProtocol::UserInfoProtocol(QString name, QString nick_name, QString user_uuid) :
	BagProtocol()
{
	setUserInfoProtocol(name, nick_name, user_uuid);

}

UserInfoProtocol::~UserInfoProtocol()
{
}

void UserInfoProtocol::setUserInfoProtocol(QString name, QString nick_name, QString user_uuid)
{
	if (!user_uuid.isEmpty()) {
		this->uuid = user_uuid;
	}

	
	this->name = name;
	this->nickName = nick_name;
	
	//setDocument();
	
}

void UserInfoProtocol::setValue()
{
	auto obj = getBag().object();
	this->name = obj.value("name").toString();
	this->nickName = obj.value("nickName").toString();
	this->uuid = obj.value("uuid").toString();
	this->appendToSonsValue(&obj);

}

void UserInfoProtocol::setDocument()
{
	QJsonObject obj;
	obj.insert("name", name);
	obj.insert("nickName", nickName);
	obj.insert("uuid", uuid);
	this->appendToSonsJson(&obj);
	fromJson(obj);

}
/*
void UserInfoProtocol::fromBytes(QByteArray bytes)
{
	BagProtocol::fromBytes(bytes);
	this->setValue();
}*/

void UserInfoProtocol::createUuid()
{
	this->uuid = BagProtocol::createUuid();
	auto obj = getBag().object();
	obj["uuid"] = this->uuid;
	fromJson(obj);

}
