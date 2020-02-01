#include "CommandBody.h"
#include <QDebug>

QJsonObject CommandBody::appendToSonsJson(QJsonObject* obj)
{
	obj->insert("commandName", commandName);
	obj->insert("commandType", commandType);
	obj->insert("commandDetail", commandDetail);
	qDebug() << "in command body ,the detail is:" << commandDetail;
	return *obj;
}

void CommandBody::appendToSonsValue(QJsonObject* obj)
{
	this->commandName = obj->value("commandName").toString();
	this->commandType = obj->value("commandType").toString();
	this->commandDetail = obj->value("commandDetail").toArray();
}

CommandBody::CommandBody():
	BodyProtocol("command"),
	commandType("unformatted"),
	commandName("unknow"),
	commandDetail(QJsonArray())
{
	this->setDocument();
}

CommandBody::CommandBody(QString command_type, QString command_name, QJsonArray command_detail, QString sender, QString reciver):
	BodyProtocol("command",sender,reciver),
	commandType(command_type),
	commandName(command_name),
	commandDetail(command_detail)
{
	this->setDocument();
}
