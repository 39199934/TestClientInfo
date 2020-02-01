#pragma once

#include <QObject>
#include <QSettings>
#include "ServerInfo.h"

class ServerSetting : public QObject
{
	Q_OBJECT
private:
	
	QString iniFileName;

public:
	QString serverAddress;
	int serverPort;
	ServerInfo serverInfo;

	ServerSetting(const ServerSetting& newServer);
	ServerSetting(QObject *parent = nullptr);
	~ServerSetting();

	void loadSetting();
	void saveSetting();
};
