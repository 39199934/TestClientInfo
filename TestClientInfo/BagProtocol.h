#pragma once
#include <QJsonDocument>
#include <QByteArray>
#include <QJsonObject>
#include <QUuid>
#include <QFile>
class BagProtocol
{

protected:
	QJsonDocument bag;
	//QString uuid;

	virtual void setValue() = 0;////需要继承，用于从doc中转换为本类中的value数据 在基类中调用
	virtual void setDocument() = 0;///需要继承，用于从value中转换为本类中的doc数据


	virtual QJsonObject appendToSonsJson(QJsonObject* obj) = 0; //用于子类继承，用于在父类中调用，添加个性化的数据
	virtual void appendToSonsValue(QJsonObject* obj) = 0; //用于子类继承，用于在父类中调用，添加个性化的数据
private:

public:


	BagProtocol();
	BagProtocol(QJsonDocument doc);
	virtual ~BagProtocol();


	virtual QByteArray toBytes();
	
	
	QJsonDocument getBag();

	int getSize();


	virtual void fromBytes(QByteArray bytes) ;//需要继承，用于从QByteArray 转换为本类中的数据和BAG
	void fromJson(QJsonDocument doc);
	void fromJson(QJsonObject obj);

	static QString createUuid();

	bool saveToFile(QString fileName, QIODevice::OpenModeFlag flag = QIODevice::OpenModeFlag::WriteOnly);
	void loadFromFile(QString fileName);
	
};

