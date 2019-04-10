#pragma once

#include <QDialog>
#include "ui_SetAlgorithm.h"
#include"imagetools.h"
#include"GetSF.h"

#include<list>
#include<qdir.h>
#include<qfiledialog.h>
#include<qcombobox.h>
#include<qcheckbox.h>
#include<qmessagebox.h>
#include"PathHelper.h"
#include"sf1.h"
#include"sf2.h"
#include"OutBlack.h"
#include"outcircle.h"
#include"chartdata.h"
class SetAlgorithm : public QDialog
{
	Q_OBJECT

public:
	SetAlgorithm(QWidget *parent = Q_NULLPTR);
	~SetAlgorithm();
	
	list<imagetools *> *tools;
	chartdata *ct;
	imagetools * currettool;
	HObject CurrentImage;
	ImageRegion* imageregion;
	Para* para1;
	Hlong MainWndID;
	HTuple  hv_WindowID;
	QString CurrentCCD;
	int scrollnum;
	bool colortype;


	bool isondetect ;

	void display(HObject image);
	void intial();
private:
	Ui::SetAlgorithm ui;
	private slots:
	void sintial();
	void readhimage();
	void selectsuanfa();
	void sdetect();
	void savesuanfa();
	void readsuanfa();
	void showresult();
	void getrollnum(int kk );
	void gettab(QTableWidgetItem * kkk);
	void getresulttoshow(int x, int y);
	void savequit();
};
