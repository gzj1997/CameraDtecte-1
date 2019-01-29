#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CameraDtecte1.h"

#include"SetAlgorithm.h"
#include"SetCamera.h"
#include"SetMotion.h"
#include"SetProduct.h"
#include"CCamera.h"
#include"turntable.h"
#include"DMC2210.h"
#include"Card.h"
#include<qmessagebox.h>
#include<qdebug.h>
#include<qdir.h>
#include<qxmlstream.h>
#include<qstandarditemmodel.h>

class CameraDtecte1 : public QMainWindow
{
	Q_OBJECT

public:
	CameraDtecte1(QWidget *parent = Q_NULLPTR);
	~CameraDtecte1();
	list< CCamera *> *Cameras;
private:
	Ui::CameraDtecte1Class ui;

	QTimer *m_pTimer;

	turntable *TurnTable;
	
	QStandardItemModel  *model;
	QStringList header;
	QString CurrentCCD;

	Hlong MainWndID;
	// Local control variables 
	HTuple  hv_Width, hv_Height;
	//HTuple  hv_WindowID;

	HTuple hv_WindowID[6];
	HTuple hv_WindowID2[6];
	bool onrun;

	int cameracount;
	void intial();
	void LinkCamera();
	void GetProduct();
	void readcameraset();

	void testimage();
	void initialgrid();
	void updatagrid(QString ccd);
	void readcameratools();
	void readshowdata();
	//void updatecamera(QString ccd);
	void savegird();
private slots:
void imageProgress(ImageResult* image);
void imageProgress2(int image);
	void StartBtn();
	void StopBtn();
	void AlgorithmSet();
	void MotionSet();
	void CameraSet();
	void ProductSet();
	void tabchange(int num);
	void ReportForm();
	void NumToZero();
	void OntimeShowResult();
};
