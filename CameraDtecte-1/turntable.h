#pragma once

#include<string>
#include<thread>
#include"DMC2210.h"
#include"nut.h"
#include"Card.h"
#include<list>
#include<qxmlstream.h>
#include<qdir.h>
#include<ostream>
#include<qdebug.h>
using namespace std;
class turntable
{
public:
	turntable();
	~turntable();

	bool isrun;
	int CameraCount;
	int ValveCount;
	int IOs[6];
	int position[6];
	cameranut* CameraNut[6];
	list<nut> *nutlist;

	static turntable * instance;
	void startrun();
	void stoprun();
	void run();
	void readconsole();

private:

};

