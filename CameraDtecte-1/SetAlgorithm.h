#pragma once

#include <QDialog>
#include "ui_SetAlgorithm.h"
#include"imagetools.h"
#include"GetSF.h"

#include<list>
#include<qdir.h>
#include<qfiledialog.h>
#include<qcombobox.h>
#include"PathHelper.h"
#include"sf1.h"
class SetAlgorithm : public QDialog
{
	Q_OBJECT

public:
	SetAlgorithm(QWidget *parent = Q_NULLPTR);
	~SetAlgorithm();
	
	list<imagetools *> *tools;
	

	HObject CurrentImage;
	ImageRegion* imageregion;
	Para* para;
	Hlong MainWndID;
	HTuple  hv_WindowID;
	QString CurrentCCD;
	int scrollnum;

	void display(HObject image);
	void intial();
private:
	Ui::SetAlgorithm ui;
	private slots:
	void sintial();
	void readhimage();
	void selectsuanfa();
	void sdetect();
	void getrollnum(int kk );
	void gettab(QTableWidgetItem * kkk);
};
