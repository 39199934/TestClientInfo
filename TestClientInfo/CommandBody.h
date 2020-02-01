#pragma once
#include "BodyProtocol.h"
#include <QJsonArray>
class CommandBody :
	public BodyProtocol
{
protected:

	virtual QJsonObject appendToSonsJson(QJsonObject* obj);
	virtual void appendToSonsValue(QJsonObject* obj);
public:
	QString commandType;
	QString commandName;
	QJsonArray commandDetail;
public:
	CommandBody();
	CommandBody(QString command_type,QString command_name,QJsonArray command_detail, QString sender = QString(), QString reciver = QString());

};

