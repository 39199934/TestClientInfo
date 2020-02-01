#include "MessageHead.h"

MessageHead::MessageHead():
	BagProtocol(),
	version("1.0"),
	size(0),
	uuid(BagProtocol::createUuid())
{
	this->setDocument();
}

MessageHead::MessageHead(QString v, int s):
	BagProtocol(),
	version(v),
	size(s),
	uuid(BagProtocol::createUuid())
{
	this->setDocument();
}

void MessageHead::setHeadSize(int s)
{
	this->size = s;
	this->setDocument();
}

void MessageHead::setHead(QString v, int s)
{
	this->version = v;
	this->size = s;
	this->setDocument();
}

void MessageHead::setValue()
{
	auto obj = getBag().object();
	this->uuid = obj.value("uuid").toString();
	this->version = obj.value("version").toString();
	this->size = obj.value("size").toInt();
	this->appendToSonsValue(&obj);

}

void MessageHead::setDocument()
{
	auto obj = getBag().object();
	obj["version"] = this->version;
	obj["size"] = this->size;
	obj["uuid"] = this->uuid;
	appendToSonsJson(&obj);
	this->bag.setObject(obj);
}

QJsonObject MessageHead::appendToSonsJson(QJsonObject* obj)
{
	return *obj;
}

void MessageHead::appendToSonsValue(QJsonObject* obj)
{
	return;
}
