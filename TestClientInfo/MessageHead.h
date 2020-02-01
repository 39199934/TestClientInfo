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
	virtual void setValue();////需要继承，用于从doc中转换为本类中的value数据 在基类中调用
	virtual void setDocument() ;///需要继承，用于从value中转换为本类中的doc数据


	virtual QJsonObject appendToSonsJson(QJsonObject* obj);
	virtual void appendToSonsValue(QJsonObject* obj);
};

