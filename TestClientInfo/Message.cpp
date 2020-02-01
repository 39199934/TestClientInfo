#include "Message.h"
#include <iostream>
using namespace std;

Message::Message(QObject *parent)
	: QObject(parent),
	head(nullptr),
	body(nullptr)
{
	
}
Message::Message(const Message& newM):
	QObject(nullptr),
	head(newM.head),
	body(newM.body)
{

}

Message::Message(BodyProtocol* new_body, QObject* parent):
	QObject(parent),
	body(new_body)
{
	head = new MessageHead();
	head->setHeadSize(body->getSize());
	//head = &h;
}

Message::~Message()
{
	cout << "del message" << endl;
	if (head) {
		delete head;
	}
	if (body) {
		delete body;
	}
}
