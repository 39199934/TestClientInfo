#include "BodyProtocol.h"

BodyProtocol::BodyProtocol():
	BagProtocol(),
	sender(QString()),
	reciver(QString()),
	type("unformatted")
{
	//this->setDocument();
}

BodyProtocol::BodyProtocol(QString type):
	BagProtocol(),
	type(type),
	sender(QString()),
	reciver(QString())
{
	//this->setDocument();
}

BodyProtocol::BodyProtocol(QString type, QString sender, QString reciver):
	BagProtocol(),
	type(type),
	sender(sender),
	reciver(reciver)
{
	//this->setDocument();
}

BodyProtocol::~BodyProtocol()
{
}
/*
int BodyProtocol::getSize()
{
	return this->toBytes().size();
	
}*/

void BodyProtocol::setValue()
{
	auto obj = getBag().object();
	this->type = obj["type"].toString();
	this->sender = obj["sender"].toString();
	this->reciver = obj["reciver"].toString();
	this->appendToSonsValue(&obj);
}

void BodyProtocol::setDocument()
{
	auto obj = getBag().object();
	obj["type"] = this->type;
	obj["sender"] = this->sender;
	obj["reciver"] = this->reciver;
	this->appendToSonsJson(&obj);
	this->bag.setObject(obj);
}
