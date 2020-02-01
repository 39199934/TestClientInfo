#pragma once
#include "BagProtocol.h"
#include "UserInfoProtocol.h"
class ServerInfo :
	public UserInfoProtocol
{
public:
	ServerInfo();
	ServerInfo(QString name, QString nick_name);
	~ServerInfo();
	void setServerInfo(QString name, QString nick_name);
	
protected:
	virtual QJsonObject appendToSonsJson(QJsonObject * obj) override;
	virtual void appendToSonsValue(QJsonObject* obj) override;

	

};

