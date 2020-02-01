#pragma once
#include "BodyProtocol.h"
class TextBody :
	public BodyProtocol
{
protected:

	virtual QJsonObject appendToSonsJson(QJsonObject* obj) ;
	virtual void appendToSonsValue(QJsonObject* obj);
public:
	QString text;
public:
	TextBody();
	TextBody(QString textMessage,QString sender= QString(),QString reciver = QString());
	
};

