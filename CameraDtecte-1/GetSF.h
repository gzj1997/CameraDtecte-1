#pragma once

#include <QDialog>
#include "ui_GetSF.h"
#include<qpushbutton.h>
#include<string>
#include<qstring.h>
using namespace std;

class GetSF : public QDialog
{
	Q_OBJECT

public:
	GetSF(QWidget *parent = Q_NULLPTR);
	~GetSF();

	QString sfname;
private:
	Ui::GetSF ui;

	private slots:

	void isok();
	void isquit();
	void getname();
};
