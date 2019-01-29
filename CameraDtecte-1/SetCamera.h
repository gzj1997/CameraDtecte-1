#pragma once

#include <QDialog>
#include<CCamera.h>
#include "ui_SetCamera.h"
#include<CCamera.h>
#include<qdir.h>
#include<qdom.h>
#include<qxmlstream.h>
#include<qmessagebox.h>
#include"DataHelper.h"

using namespace std;
class SetCamera : public QDialog
{
	Q_OBJECT

public:
	SetCamera(QWidget *parent = Q_NULLPTR);
//	SetCamera(list< CCamera *> * Cameras,QWidget *parent = Q_NULLPTR);
	~SetCamera();

	list< CCamera *> * cameras;

	CCamera * currentcamera;
	Hlong MainWndID;
	// Local control variables 
	HTuple  hv_WindowID;

	void intail();
	void readcamera();
	void setradio(QString num,int  mode =0);
	void setCCD(QString num);
//	CCamera * findcamera(int k);
private:
	Ui::SetCamera ui;
private	slots:
void getCCD(bool ison);
void onshot();
void conshot();
void stop();
void saveset();
void changegain();
void changepixel();
void changeexpose();
void changemode(int mmd);
};
