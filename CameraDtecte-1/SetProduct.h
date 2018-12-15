#pragma once

#include <QDialog>
#include "ui_SetProduct.h"
#include"PathHelper.h"
#include<qmessagebox.h>
class SetProduct : public QDialog
{
	Q_OBJECT

public:
	SetProduct(QWidget *parent = Q_NULLPTR);
	~SetProduct();

private:
	Ui::SetProduct ui;

	void intial();
	void getnames();
	private slots:

	void newproduct();
	void savenewproduct();
	void selectproduct();
	void saveselectproduct();
	void deleteproduct();
};
