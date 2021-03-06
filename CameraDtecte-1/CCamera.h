#pragma once

#include <QObject>

#include"HalconCpp.h"
#include"pylon\PylonIncludes.h"
#include"imagetools.h"
#include"turntable.h"
#include"imageresult.h"
#include"PathHelper.h"
#include<string.h>
#include<list>
#include<queue>
#include<qdebug.h>
#include <time.h>
#include<qtimer.h>
#include<thread>
#include<qthread.h>
#include <QObject>
#include <QtWidgets/QMainWindow>
#include<qobjectdefs.h>
#include <mutex>
using namespace GenApi;
using namespace HalconCpp;
using namespace Pylon;
using namespace std;

class CCamera : public QThread
{
	Q_OBJECT
signals :
		void sigCurrentImage(ImageResult* img);
signals:
		void sigCurrentImage2(HObject img);
signals:
		void sigCurrentImage3(int img);
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

	list< toolresult> *tresult;
	list< imagepos> * imagePoS;
	imagepos  imagePos;
	mutex mut;


	list<ImageResult> *imageresults;
	ImageResult * imageresult;
	string logicname;
	string devicename;

	int sort;
	int gain;
	int exposuretime;
	int pixel;
	bool tiggerMode;

	QString m_currentMode;
	bool isopen = false;

	bool isoncatch = false;
	 bool isgrap = false;
	std::thread * tthread;

	int posmin =0;
	int prepos =-1;
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
	void run();
	//void run();
	void gettools();
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

	void Allcameraset();

	void GrapImage();
	private slots:

	void onTimerGrabImage();


};
