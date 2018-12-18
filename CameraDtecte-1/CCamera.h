#pragma once

#include <QObject>

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
#include<qobjectdefs.h>
using namespace GenApi;
using namespace HalconCpp;
using namespace Pylon;
using namespace std;

class CCamera : public QObject
{
	Q_OBJECT
signals :
		void sigCurrentImage(HObject img);
public:
	CCamera(QObject *parent);
	~CCamera();

	enum CCamera_Type {
		Type_Basler_Freerun, //设置相机的内触发
		Type_Basler_Line1, //设置相机的外触发
		Type_Basler_ExposureTimeAbs, //设置相机的曝光时间
		Type_Basler_GainRaw, //设置相机的增益
		Type_Basler_AcquisitionFrameRateAbs, //设置相机的频率
		Type_Basler_Width, //图片的宽度
		Type_Basler_Height, //图片的高度
		Type_Basler_LineSource, //灯的触发信号
	};
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
	int pixel;

	QString m_currentMode;
	bool isopen = false;

	bool isoncatch = false;
	std::thread * tthread;

	int posmin;

	list<int>good;
	list<int>bad;

	void LinkCamera();
	void GetImage();
	void intial();
	void Start();
	void Stop();
	void Close();
	bool CheckCamera();
	void CopyToImage(CGrabResultPtr pInBuffer, HObject* OutImage);
	void disposeimage();

	//camera set
	void setcameraset(CCamera_Type index, double tmpValue= 0.0);
	double getcameraset(CCamera_Type index);
	void setExposureTime(double time); // 设置曝光时间
	int getExposureTime(); // 获取曝光时间
	void setpixel(int p);
	int getpixel();
	void setgain( int gain);
	int getgain();
	void setFeatureTriggerSourceType(QString type); // 设置种类
	QString getFeatureTriggerSourceType(); // 获取种类：软触发、外触发等等

	void setFeatureTriggerModeType(bool on); // 设置模式触发
	bool getFeatureTriggerModeType(); // 获取模式触发

private:


};
