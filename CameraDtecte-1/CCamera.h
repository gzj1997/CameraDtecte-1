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
		Type_Basler_Freerun, //����������ڴ���
		Type_Basler_Line1, //����������ⴥ��
		Type_Basler_ExposureTimeAbs, //����������ع�ʱ��
		Type_Basler_GainRaw, //�������������
		Type_Basler_AcquisitionFrameRateAbs, //���������Ƶ��
		Type_Basler_Width, //ͼƬ�Ŀ��
		Type_Basler_Height, //ͼƬ�ĸ߶�
		Type_Basler_LineSource, //�ƵĴ����ź�
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

	list<ImageResult> *imageresults;
	ImageResult * imageresult;
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
	void run();
	//void run();
	void gettools();
	//camera set
	void setcameraset(CCamera_Type index, double tmpValue= 0.0);
	double getcameraset(CCamera_Type index);
	void setExposureTime(double time); // �����ع�ʱ��
	int getExposureTime(); // ��ȡ�ع�ʱ��
	void setpixel(int p);
	int getpixel();
	void setgain( int gain);
	int getgain();
	void setFeatureTriggerSourceType(QString type); // ��������
	QString getFeatureTriggerSourceType(); // ��ȡ���ࣺ�������ⴥ���ȵ�

	void setFeatureTriggerModeType(bool on); // ����ģʽ����
	bool getFeatureTriggerModeType(); // ��ȡģʽ����

private:


};
