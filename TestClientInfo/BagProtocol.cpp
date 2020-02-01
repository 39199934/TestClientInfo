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

bool BagProtocol::saveToFile(QString fileName,QIODevice::OpenModeFlag flag )
{
	auto bytes = this->toBytes();
	
	QFile  fp(fileName);
	fp.open(flag);
	fp.write(bytes);
	fp.close();

	return true;
}

void BagProtocol::loadFromFile(QString fileName)
{
	

	QFile  fp(fileName);
	fp.open(QIODevice::OpenModeFlag::ReadOnly);
	auto bytes = fp.read(fp.size());
	this->fromBytes(bytes);
	fp.close();

	return;
}


QJsonDocument BagProtocol::getBag()
{
	return this->bag;
}

int BagProtocol::getSize()
{
	return this->toBytes().size();
	
}

void BagProtocol::fromBytes(QByteArray bytes)
{
	bag = QJsonDocument::fromJson(bytes);
	this->setValue();
}
