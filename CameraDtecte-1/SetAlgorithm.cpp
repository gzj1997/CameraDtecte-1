#include "SetAlgorithm.h"

SetAlgorithm::SetAlgorithm(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	HObject himage1;
	QString str = QDir::currentPath() + "/Data/I1.bmp";
	HalconCpp::ReadImage(&himage1, str.toStdString().c_str());
	MainWndID = (Hlong)this->ui.label->winId();
	OpenWindow(0, 0, 561, 291, MainWndID, "visible", "", &hv_WindowID);

	intial();
}

SetAlgorithm::~SetAlgorithm()
{

}

void SetAlgorithm::display(HObject image)
{
	DispObj(image, hv_WindowID);
}

void SetAlgorithm::intial()
{
	tools = new list<imagetools *>();
	para = new Para();
	imageregion = new ImageRegion();

	//2
	QTableWidgetItem *aItem;
	aItem = new QTableWidgetItem(QString("字符内容"));

	//ui.tableWidget->resizeColumnsToContents();//根据内容自动改变列的大小
	//ui.tableWidget->resizeRowsToContents();//根据内容自动改变行的大小
	ui.tableWidget->setColumnCount(3);//设置列数为10
	ui.tableWidget->setRowCount(1);//设置行数为10

	ui.tableWidget->setColumnWidth(0, 90);
	ui.tableWidget->setColumnWidth(1, 86);
	ui.tableWidget->setColumnWidth(2, 86);

	for (size_t i = 0; i < 3; i++)
	{
		ui.tableWidget->setColumnWidth(i, 100);
	}
	QStringList header;
	header << "type" << "min" << "max";
	ui.tableWidget->setHorizontalHeaderLabels(header);
	QComboBox *comBox = new QComboBox();
	comBox->addItem("area");
	comBox->addItem("height");
	comBox->addItem("width");
	ui.tableWidget->setCellWidget(0, 0, comBox);
	ui.tableWidget->setShowGrid(true);
	
	//3

	ui.horizontalSlider->setMinimum(0);
	ui.horizontalSlider->setMaximum(127);
	ui.radioButton->setChecked(true);

	// 4


}

void SetAlgorithm::readhimage()
{
	QString title = u8"选择图片";
	QString filter = "image(*.jpg *.png *bmp)";
	QString imagename = QFileDialog::getOpenFileName(this,
		title, PathHelper::currentproductpath, filter);
	HalconCpp::ReadImage(&CurrentImage, (HalconCpp::HTuple)(imagename.toStdString().c_str()));
	HalconCpp::DispObj(CurrentImage, hv_WindowID);
}

void SetAlgorithm::selectsuanfa()
{
	GetSF *Gs = new GetSF();
	Qt::WindowFlags flags = Gs->windowFlags();
	Gs->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
	imagetools * currettool;
	int ret = Gs->exec();
	bool isgood = true;
	if (ret == QDialog::Accepted)
	{
		if (Gs->sfname =="sf1")
		{
			currettool = new sf1();
		}
		else 
		{
			isgood = false;
		}
		if (isgood)
		{
			currettool->draw();

			currettool->action();



			tools->push_back(currettool);
		}
	}
	
}

void SetAlgorithm::sdetect()
{
	list<imagetools *>::iterator it;
	for (it = tools->begin() ; it != tools->end(); it++)
	{
		(*it)->image = CurrentImage;
		(*it)->action();
		//(*it)->result;
	}
}

void SetAlgorithm::getrollnum(int kk)
{
	if ((ui.radioButton)->isChecked())
	{
		scrollnum = kk;
	}
	else if (ui.radioButton_2->isChecked())
	{
		scrollnum = kk;
		scrollnum += 128;
	}
	ui.label_2->setText(QStringLiteral("值：") + QString::number(scrollnum));
}

void SetAlgorithm::gettab(QTableWidgetItem * kkk)
{
	ui.label_2->setText(kkk->text());
	int rowNum = kkk->row();
	// use d to delete a row
	if (rowNum != 0 && (kkk->text().trimmed() == "d" || kkk->text().trimmed() == "D"))
	{
		ui.tableWidget->removeRow(rowNum);
		return;
	}
	//if last line then create a new row
	if (rowNum == ui.tableWidget->rowCount() - 1)
	{
		ui.tableWidget->setRowCount(rowNum + 2);

		QComboBox *comBox = new QComboBox();
		comBox->addItem("area");
		comBox->addItem("height");
		comBox->addItem("width");
		ui.tableWidget->setCellWidget(rowNum + 1, 0, comBox);
	}
}

void SetAlgorithm::sintial()
{
	tools->clear();
}
