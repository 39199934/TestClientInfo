#include "MyClient.h"

MyClient::MyClient(QObject *parent)
	: QTcpSocket(parent)
{
}

MyClient::~MyClient()
{
}
