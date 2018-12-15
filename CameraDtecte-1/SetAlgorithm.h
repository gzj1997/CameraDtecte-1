#pragma once

#include <QDialog>
#include "ui_SetAlgorithm.h"
#include"imagetools.h"
#include<list>
#include<qdir.h>
#include<qfiledialog.h>
#include<qcombobox.h>
#include"PathHelper.h"
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
	 

	void display(HObject image);
	void intial();
private:
	Ui::SetAlgorithm ui;
	private slots:
	void sintial();
	void readhimage();
	void sdetect();
	void getrollnum();
	void gettab(QTableWidgetItem * kkk);
};
