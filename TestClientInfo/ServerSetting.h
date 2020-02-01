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

	ServerSetting(QObject *parent = nullptr);
	~ServerSetting();

	void getSetting();
	void saveSetting();
};
