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
	virtual void setValue() override;////��Ҫ�̳У����ڴ�doc��ת��Ϊ�����е�value����
	virtual void setDocument() override;///��Ҫ�̳У����ڴ�value��ת��Ϊ�����е�doc����
	

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

