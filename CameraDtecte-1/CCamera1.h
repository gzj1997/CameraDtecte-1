#pragma once
#ifndef CCamera1_H
#define CCamera1_H
#include"HalconCpp.h"
#include"pylon\PylonIncludes.h"

#include"imagetools.h"

#include<string.h>
#include<list>
#include<queue>
#include<qdebug.h>
#include <time.h>
#include<qtimer.h>
#include<thread>
#include <QObject>
#include <QtWidgets/QMainWindow>
#include <QMetaType>
#include<qobjectdefs.h>
using namespace GenApi;
using namespace HalconCpp;
using namespace Pylon;
using namespace std;
class CCamera1 
{
signals :
//	void sigCurrentImage(HObject img);
public:
	explicit CCamera1();
	~CCamera1();

	HTuple Hresult;
	HObject Himage;
	queue<HObject> *imagelist;
	
	CInstantCamera instantcamera;
	CDeviceInfo  deviceinfo;
	

	list<imagetools*> *tools;
	string logicname;
	string devicename;
	int sort;
	int gain;
	int exposuretime;
	QString m_currentMode;
	bool isopen =false;

	bool isoncatch =false ;
	std::thread * tthread;

	void LinkCamera();
	void GetImage();
	void intial();
	void Start();
	void Stop();
	void Close();
	bool CheckCamera();
	void CopyToImage(CGrabResultPtr pInBuffer, HObject &OutImage);
	void disposeimage();

	void setExposureTime(double time); // 设置曝光时间
	int getExposureTime(); // 获取曝光时间
	//int getExposureTimeMin(); // 最小曝光时间
	//int getExposureTimeMax(); // 最大曝光时间

	void setFeatureTriggerSourceType(QString type); // 设置种类
	QString getFeatureTriggerSourceType(); // 获取种类：软触发、外触发等等

	void setFeatureTriggerModeType(bool on); // 设置模式触发
	bool getFeatureTriggerModeType(); // 获取模式触发
	
private:


};

#endif // CCamera1_H