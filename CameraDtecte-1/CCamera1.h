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

	void setExposureTime(double time); // �����ع�ʱ��
	int getExposureTime(); // ��ȡ�ع�ʱ��
	//int getExposureTimeMin(); // ��С�ع�ʱ��
	//int getExposureTimeMax(); // ����ع�ʱ��

	void setFeatureTriggerSourceType(QString type); // ��������
	QString getFeatureTriggerSourceType(); // ��ȡ���ࣺ�������ⴥ���ȵ�

	void setFeatureTriggerModeType(bool on); // ����ģʽ����
	bool getFeatureTriggerModeType(); // ��ȡģʽ����
	
private:


};

#endif // CCamera1_H