#include "TextBody.h"

QJsonObject TextBody::appendToSonsJson(QJsonObject* obj)
{
	obj->insert("text", text);
	return *obj;
}

void TextBody::appendToSonsValue(QJsonObject* obj)
{
	this->text = obj->value("text").toString();
}

TextBody::TextBody():
	BodyProtocol("text"),
	text(QString())
{
	this->setDocument();
}

TextBody::TextBody(QString textMessage, QString sender, QString reciver):
	BodyProtocol("text",sender,reciver),
	text(textMessage)
{
	this->setDocument();
}

