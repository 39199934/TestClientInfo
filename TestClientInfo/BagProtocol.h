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

	virtual void setValue() = 0;////��Ҫ�̳У����ڴ�doc��ת��Ϊ�����е�value���� �ڻ����е���
	virtual void setDocument() = 0;///��Ҫ�̳У����ڴ�value��ת��Ϊ�����е�doc����


	virtual QJsonObject appendToSonsJson(QJsonObject* obj) = 0; //��������̳У������ڸ����е��ã���Ӹ��Ի�������
	virtual void appendToSonsValue(QJsonObject* obj) = 0; //��������̳У������ڸ����е��ã���Ӹ��Ի�������
private:

public:


	BagProtocol();
	BagProtocol(QJsonDocument doc);
	virtual ~BagProtocol();


	virtual QByteArray toBytes();
	
	
	QJsonDocument getBag();


	virtual void fromBytes(QByteArray bytes) ;//��Ҫ�̳У����ڴ�QByteArray ת��Ϊ�����е����ݺ�BAG
	void fromJson(QJsonDocument doc);
	void fromJson(QJsonObject obj);

	static QString createUuid();

	bool saveToFile(QString fileName, QIODevice::OpenModeFlag flag = QIODevice::OpenModeFlag::WriteOnly);
	void loadFromFile(QString fileName);
	
};

