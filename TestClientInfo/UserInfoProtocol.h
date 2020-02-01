#pragma once
#include <QtCore>
#include <QUUID>
#include "BagProtocol.h"
class UserInfoProtocol:
	public BagProtocol
{
private:
	QString name;
	QString nickName;
	QString uuid;
protected:
	virtual void setValue() override;////需要继承，用于从doc中转换为本类中的value数据
	virtual void setDocument() override;///需要继承，用于从value中转换为本类中的doc数据
	

	//virtual QJsonObject appendSonsJson(QJsonObject* obj) = 0;
	//virtual void appendSonsValue(QJsonObject* obj) = 0;
public:
	
	UserInfoProtocol();
	UserInfoProtocol(QString name, QString nick_name, QString user_uuid = QString());
	//virtual void fromBytes(QByteArray bytes) override;

	//virtual void fromBytes(QByteArray bytes) override;

	virtual ~UserInfoProtocol();
	void setUserInfoProtocol(QString name, QString nick_name,QString user_uuid = QString());
	//virtual void setValue() override;
	void createUuid();
	

};

