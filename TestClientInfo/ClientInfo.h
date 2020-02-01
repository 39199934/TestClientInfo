#pragma once
#include "UserInfoProtocol.h"
class ClientInfo :
	public UserInfoProtocol
{
private:
	QString password;
public:
	ClientInfo();
	ClientInfo(QString name, QString nick_name,QString pass_word);

	void setClientInfo(QString name, QString nick_name, QString pass_word);
protected:
	
	virtual QJsonObject appendToSonsJson(QJsonObject* obj) override;
	virtual void appendToSonsValue(QJsonObject* obj) override;


	
};

