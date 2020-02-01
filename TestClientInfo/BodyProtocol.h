#pragma once
#include "BagProtocol.h"
class BodyProtocol :
	public BagProtocol
{

public:
	BodyProtocol();
	BodyProtocol(QString type);
	BodyProtocol(QString type, QString sender, QString reciver);
	virtual ~BodyProtocol();
	//int getSize();
	
	//QString uuid;
protected:
	virtual void setValue();////��Ҫ�̳У����ڴ�doc��ת��Ϊ�����е�value���� �ڻ����е���
	virtual void setDocument();///��Ҫ�̳У����ڴ�value��ת��Ϊ�����е�doc����


	virtual QJsonObject appendToSonsJson(QJsonObject* obj) =0;
	virtual void appendToSonsValue(QJsonObject* obj)=0;
private:
	QString sender;
	QString reciver;
	QString type;
};

