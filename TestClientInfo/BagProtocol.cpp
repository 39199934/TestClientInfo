#include "BagProtocol.h"

BagProtocol::BagProtocol():
	bag(QJsonDocument())
{
	//setBag(QJsonDocument());
	
}

BagProtocol::BagProtocol(QJsonDocument doc):
	bag(doc)
{
	//setBag(doc);
	
}

BagProtocol::~BagProtocol()
{
}

QByteArray BagProtocol::toBytes()
{
	return bag.toJson();
}

void BagProtocol::fromJson(QJsonDocument doc)
{
	this->bag = doc;
	this->setValue();
}

void BagProtocol::fromJson(QJsonObject obj)
{
	this->bag.setObject(obj);
	fromJson(this->bag);
}

QString BagProtocol::createUuid()
{
	auto uid = QUuid();
	auto str = uid.createUuid().toString(QUuid::StringFormat::WithoutBraces);
	return str;
}


QJsonDocument BagProtocol::getBag()
{
	return this->bag;
}

void BagProtocol::fromBytes(QByteArray bytes)
{
	bag = QJsonDocument::fromJson(bytes);
}
