#include "GetSF.h"

GetSF::GetSF(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

GetSF::~GetSF()
{

}

void GetSF::isok()
{
	this->accept();
}


void GetSF::isquit()
{
	this->reject();
}

void GetSF::getname()
{
	sfname = ((QPushButton *)sender())->text().trimmed();
}
