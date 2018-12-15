#pragma once

#include <QDialog>
#include "ui_SetMotion.h"
#include"DMC2210.h"
#include"Card.h"
#include"DataHelper.h"
#include<qdebug.h>
#include<map>
#include<string>
#include<thread>
using namespace std;
class SetMotion : public QDialog
{
	Q_OBJECT

public:
	SetMotion(QWidget *parent = Q_NULLPTR);
	~SetMotion();

	QIcon iconred;
	QIcon icongreen;

	
	int currentEM;
	int distance;
	map<int, int> machinerylist;

	bool onrun = false;
private:
	Ui::SetMotion ui;
	void intial();
	void setmachinery(int num);
	void read_inbitatate();
	void read_inoutbitstate();
	void set_icon(QString name,int state);
	void run();
private slots:
	void changestate();
	void getmachinery(bool ok);
	void getspeed();
	void startmotion();
	void savequit();
};
