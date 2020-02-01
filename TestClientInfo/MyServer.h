#pragma once

#include <QTcpServer>
#include "ServerSetting.h"

class MyServer : public QTcpServer
{
	Q_OBJECT

private:
	ServerSetting setting;

public:
	MyServer(QObject *parent);
	~MyServer();

	void start();
	void stop();
};
