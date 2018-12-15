#include "SetProduct.h"

SetProduct::SetProduct(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	intial();
}

SetProduct::~SetProduct()
{

}
void SetProduct::newproduct()
{
	ui.widget_2->hide();
	ui.widget->show();
//	PathHelper::newproduct(ui.lineEdit->text().trimmed());
}
void SetProduct::intial()
{
	ui.widget_2->hide();
	ui.widget->hide();
	ui.widget_2->show();


	//QPalette bgpal = palette();
	//bgpal.setColor(QPalette::Background,Qt::green);
	////bgpal.setColor (QPalette::Background, Qt::transparent);
	//bgpal.setColor(QPalette::Foreground, QColor(255, 255, 255, 255)); 
	//setPalette(bgpal);

	this->setStyleSheet("QWidget{ border - top - left - radius:15px; border - top - right - radius:5px; }");
	//ui.widget_2->setPalette(bgpal);
	
	getnames();
}
void SetProduct::getnames()
{
	vector<QString> folder;
	PathHelper::GetAllFileFolder(folder);
	ui.label_3->setText(PathHelper::currentproductname);
	ui.comboBox->clear();
	
	for each (QString var in folder)
	{
		ui.comboBox->addItem(var);
	}
}
void SetProduct::savenewproduct()
{
	if (PathHelper::newproduct(ui.lineEdit->text().trimmed()))
	{
		this->accept();
	}
}
void SetProduct::selectproduct()
{
	ui.widget->hide();
	ui.widget_2->show();
}

void SetProduct::saveselectproduct()
{
	PathHelper::selectproduct(ui.comboBox->currentText() );
	this->accept();
}

void SetProduct::deleteproduct()
{

	if (! PathHelper::DelDir(ui.comboBox->currentText()))
	{
		QMessageBox::warning(this, "warning", u8"É¾³ý´íÎó", QMessageBox::Ok, QMessageBox::NoButton);
	}
	getnames();
}
