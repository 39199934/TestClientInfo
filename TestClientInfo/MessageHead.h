#pragma once
#include "BagProtocol.h"
class MessageHead :
	public BagProtocol
{
private:
	QString version;
	int size;
	QString uuid;
	//QString type;
public:
	MessageHead();
	MessageHead(QString v, int s);
	void setHeadSize(int s);
	void setHead(QString v, int s);
	
protected:
	virtual void setValue();////��Ҫ�̳У����ڴ�doc��ת��Ϊ�����е�value���� �ڻ����е���
	virtual void setDocument() ;///��Ҫ�̳У����ڴ�value��ת��Ϊ�����е�doc����


	virtual QJsonObject appendToSonsJson(QJsonObject* obj);
	virtual void appendToSonsValue(QJsonObject* obj);
};

