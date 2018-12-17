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
	para1 = new Para();
	imageregion = new ImageRegion();
	ct = new chartdata();
	isondetect = false;
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
	ui.horizontalSlider->setMaximum(255);
	scrollnum = 0;
	colortype = false;
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
	//1
	ct->checktype(ui.tableWidget->rowCount() - 1);

	//2
	if (!CurrentImage.IsInitialized())
	{
		return;
	}
	if (!isondetect)
	{
		isondetect = true;
	}
	else
	{
		return;
	}
	imagetools * currettool;
	currettool->image = CurrentImage;
	currettool->imageregion = *(imageregion->cloner());

	//3

	GetSF *Gs = new GetSF();
	Qt::WindowFlags flags = Gs->windowFlags();
	Gs->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
	
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
			// get para and draw
			currettool->draw();

			currettool->action();
			tools->push_back(currettool);
		}
	}
	isondetect = false;
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

void SetAlgorithm::savesuanfa()
{

	std::ofstream ofs("store.dat");
	boost::archive::text_oarchive ar(ofs);
	ofs << tools;
}

void SetAlgorithm::readsuanfa()
{
	tools->clear();
	std::ifstream ifs("filename", std::ios::binary);
	boost::archive::text_iarchive ia(ifs);
	ia >> tools;
}

void SetAlgorithm::showresult()
{
}

void SetAlgorithm::getrollnum(int kk)
{
	if ((ui.radioButton)->isChecked())
	{
		 colortype = false;
	}
	scrollnum = kk;
	ui.label_2->setText(u8"值：" + QString::number(scrollnum));


	ct->checktype(ui.tableWidget->rowCount() - 1);

	imageregion->color = colortype;
	imageregion->srcollnum = scrollnum;
	imageregion->chartdata = ct;
}

void SetAlgorithm::gettab(QTableWidgetItem * kkk)
{
	ui.label_2->setText(kkk->text());
	int rowNum = kkk->row();
	int columnnum = kkk->column();
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

	ct->getdata(columnnum, rowNum, kkk->text());
	QWidget *widget = ui.tableWidget->cellWidget(rowNum, 0);
	QComboBox *combox = (QComboBox*)widget;
	ct->gettype(rowNum, combox->currentText());
}

void SetAlgorithm::sintial()
{
	tools->clear();
}
