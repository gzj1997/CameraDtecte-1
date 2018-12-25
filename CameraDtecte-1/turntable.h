#pragma once

#include<string>
#include<thread>
#include"DMC2210.h"
#include"PCI408.h"
#include"nut.h"
#include"Card.h"
#include<list>
#include<qxmlstream.h>
#include<qdir.h>
#include<ostream>
#include<qdebug.h>
#include"DataHelper.h"
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
	int callcamera[6];
	int precallcamera[6];
	int cameracallIO[6];
	cameranut* CameraNut[6];
	list<nut> *nutlist;
	
	list<int>*  allpos[6];

	static turntable * instance;
	void startrun();
	void stoprun();
	void run();
	void readconsole();

private:

};

