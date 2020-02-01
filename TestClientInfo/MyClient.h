#pragma once

#include <QTcpSocket>

class MyClient : public QTcpSocket
{
	Q_OBJECT

public:
	MyClient(QObject *parent);
	~MyClient();
};
