#pragma once

#include<string>
#include<thread>
#include"DMC2210.h"
#include"PCI408.h"
#include"nut.h"
#include"Card.h"
#include"AllNum.h"

#include<list>
#include<qxmlstream.h>
#include<qdir.h>
#include<ostream>
#include<qdebug.h>
#include"DataHelper.h"
#include"PathHelper.h"
#include<Windows.h>
#include <mutex>
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
	QStringList SaveResult;
	QStringList SaveResult2;
	QStringList ResultName;
	volatile bool SaveToOne = true;
	static turntable * instance;
	void startrun();
	void stoprun();
	void run();
	void readconsole();
	void saveonetxt();
	int ONETXT = 4*1000;
	mutex mut1;
private:

};

