#include "SetAlgorithm.h"
list<imagetools *> *tools;
BOOST_CLASS_EXPORT(sf1)
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
	currettool = nullptr;
	para1 = new Para();
	imageregion = new ImageRegion();
	ct = new chartdata();
	isondetect = false;
	//2
	//QTableWidgetItem *aItem;
	//aItem = new QTableWidgetItem(QString("字符内容"));

	//ui.tableWidget->resizeColumnsToContents();//根据内容自动改变列的大小
	//ui.tableWidget->resizeRowsToContents();//根据内容自动改变行的大小
	ui.tableWidget->setColumnCount(3);//设置列数为10
	ui.tableWidget->setRowCount(1);//设置行数为10

	//ui.tableWidget->setColumnWidth(0, 90);
	//ui.tableWidget->setColumnWidth(1, 86);
	//ui.tableWidget->setColumnWidth(2, 86);

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

	//5
	//ui.tableWidget->resizeColumnsToContents();//根据内容自动改变列的大小
	//ui.tableWidget->resizeRowsToContents();//根据内容自动改变行的大小
	ui.tableWidget_2->setColumnCount(3);//设置列数为10
	ui.tableWidget_2->setRowCount(0);//设置行数为10

	for (size_t i = 0; i < 3; i++)
	{
		ui.tableWidget_2->setColumnWidth(i, 100);
	}
	QStringList header2;
	header2 << "type" << "result" << "check";
	ui.tableWidget_2->setHorizontalHeaderLabels(header2);
//	ui.tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
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
		qDebug() << "no image";
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
			imageregion->chartdata = ct->cloner();

			currettool->image = CurrentImage;
			currettool->imageregion = *(imageregion->cloner());
			// get para and draw
			currettool->draw();

			currettool->action();

			toolresult *tr = currettool->Toolresult.cloner();
			ui.tableWidget_2->clearContents();
			for (int i = 0; !tr->name[i].empty(); i++)
			{
				ui.tableWidget_2->setRowCount(i+1);
				ui.tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(tr->name[i])));
				ui.tableWidget_2->setItem(i, 1, new QTableWidgetItem(QString::number(tr->data[i])));
				QTableWidgetItem *item = new QTableWidgetItem();
				item->setCheckState(Qt::Unchecked);
				ui.tableWidget_2->setItem(i, 2, item);
			}
			tools->push_back(currettool);
		}
	}
	isondetect = false;
}

void SetAlgorithm::sdetect()
{
	currettool = nullptr;
	ui.tableWidget_2->clearContents();
	list<imagetools *>::iterator it;
	for (it = tools->begin() ; it != tools->end(); it++)
	{
		(*it)->image = CurrentImage;
		(*it)->action();
		toolresult *tr = (*it)->Toolresult.cloner();
		for (int i = 0; !tr->name[i].empty(); i++)
		{
			ui.tableWidget_2->setRowCount(i + 1);
			ui.tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(tr->name[i])));
			ui.tableWidget_2->setItem(i, 1, new QTableWidgetItem(QString::number(tr->data[i])));
			QTableWidgetItem *item = new QTableWidgetItem();
			if (tr->isshow[i])
			{
				item->setCheckState(Qt::Checked);
			}
			else
			{
				item->setCheckState(Qt::Unchecked);
			}
			ui.tableWidget_2->setItem(i, 2, item);
		}
		//(*it)->result;
	}
}

void SetAlgorithm::savesuanfa()
{
	//tools->clear();
	//imagetools * t = new sf1();
	//((sf1*)t)->mianji = 122;
	//tools->push_back(t);
	QString pt = PathHelper::currentproductpath +"/"+CurrentCCD +".txt";
	std::ofstream file(pt.toStdString());
	boost::archive::text_oarchive oa(file);
	oa << tools;
}

void SetAlgorithm::readsuanfa()
{
	tools->clear();
	QString pt = PathHelper::currentproductpath + "/" + CurrentCCD + ".txt";
//	std::ifstream ifs("filename", std::ios::binary);
	std::ifstream file(pt.toStdString());
	boost::archive::text_iarchive ia(file);
	ia >> tools;

}

void SetAlgorithm::showresult()
{
	ui.tableWidget_2->clearContents();
	currettool = tools->front();
	toolresult *tr = currettool->Toolresult.cloner();
	for (int i = 0; !tr->name[i].empty(); i++)
	{
		ui.tableWidget_2->setRowCount(i + 1);
		ui.tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(tr->name[i])));
		ui.tableWidget_2->setItem(i, 1, new QTableWidgetItem(QString::number(tr->data[i])));
		QTableWidgetItem *item = new QTableWidgetItem();
		if (tr->isshow[i])
		{
			item->setCheckState(Qt::Checked);
		}
		else
		{
			item->setCheckState(Qt::Unchecked);
		}
		ui.tableWidget_2->setItem(i, 2, item);
	}
}

void SetAlgorithm::getrollnum(int kk)
{
    colortype = (ui.radioButton)->isChecked();
	scrollnum = kk;
	ui.label_2->setText("num:" + QString::number(scrollnum));
	ct->checktype(ui.tableWidget->rowCount() - 1);
	imageregion->image = CurrentImage;
	imageregion->color = colortype;
	imageregion->srcollnum = scrollnum;
	imageregion->chartdata = ct;
	imageregion->draw();
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

void SetAlgorithm::getresulttoshow(int x, int y)
{
	if (y != 2 )
	{
		return;
	}

	bool ck = ui.tableWidget_2->item(x, y)->checkState() == Qt::Checked;
	if (currettool != nullptr)
	{
		currettool->Toolresult.isshow[x] = ck;
	}
	else
	{
		int num=0;
		list<imagetools *>::iterator it;
		for (it = tools->begin(); it != tools->end(); it++)
		{
			for (int i = 0; !(*it)->Toolresult.name[i].empty(); i++)
			{
				if (num == x)
				{
					(*it)->Toolresult.isshow[x] = ck;
				}
				num++;
			}
		}
	}
	
	qDebug() << x << y;
}

void SetAlgorithm::savequit()
{
	savesuanfa();
	this->accept();
}

void SetAlgorithm::sintial()
{
	tools->clear();
}
