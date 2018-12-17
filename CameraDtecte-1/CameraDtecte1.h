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

#include<qmessagebox.h>
#include<qdebug.h>
#include<qdir.h>
#include<qxmlstream.h>

class CameraDtecte1 : public QMainWindow
{
	Q_OBJECT

public:
	CameraDtecte1(QWidget *parent = Q_NULLPTR);
	~CameraDtecte1();
	list< CCamera *> *Cameras;
private:
	Ui::CameraDtecte1Class ui;

   
	turntable *TurnTable;
	
	string CurrentCCD;

	Hlong MainWndID;
	// Local control variables 
	HTuple  hv_Width, hv_Height;
	HTuple  hv_WindowID;

	void intial();
	void LinkCamera();
	void GetProduct();
	void readcameraset();
	void imageProgress(HObject image);
private slots:
	void StartBtn();
	void StopBtn();
	void AlgorithmSet();
	void MotionSet();
	void CameraSet();
	void ProductSet();

};
