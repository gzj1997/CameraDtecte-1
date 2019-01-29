#include "CameraDtecte1.h"

CameraDtecte1::CameraDtecte1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	intial();
}
CameraDtecte1::~CameraDtecte1()
{
//	Cameras->front()->Close();
	list<CCamera*>::iterator it;
	for (it = Cameras->begin(); it != Cameras->end(); it++)
	{
		(*it)->Close();		
	}
	savegird();
	Pylon::PylonTerminate();
}
void CameraDtecte1::intial()
{
	Cameras =new list< CCamera *>();
	TurnTable = new turntable();

	DateHelper Dh = *new DateHelper();
	AllNum *allnum = new AllNum();
	onrun = false;
	int card = PCI408_card_init();
	 if (card== 0)
	 {
		 QMessageBox::warning(this, "warning", u8"运动控制卡未连接", QMessageBox::Ok, QMessageBox::NoButton);
		 this->close();
	 }
	 else if ( card > 8 )
	 {
		 QMessageBox::warning(this, "warning", u8"运动控制卡连接错误", QMessageBox::Ok, QMessageBox::NoButton);
		 this->close();
	 }


	 ui.tabWidget->setCurrentIndex(0);
	 CurrentCCD = "CCD1";

	 HObject himage1[6];
	 for (int  i = 0; i < 4; i++)
	  {
		 QString str = QDir::currentPath() + "/Data/I" + QString::number(i+1) + ".bmp";
		 HalconCpp::ReadImage(&himage1[i], str.toStdString().c_str());
	 }
	

	 MainWndID = (Hlong)this->ui.label->winId();
	 OpenWindow(0, 0, 611, 441, MainWndID, "visible", "", &hv_WindowID[0]);
	 MainWndID = (Hlong)this->ui.label_2->winId();
	 OpenWindow(0, 0, 611, 441, MainWndID, "visible", "", &hv_WindowID[1]);
	 MainWndID = (Hlong)this->ui.label_7->winId();
	 OpenWindow(0, 0, 611, 441, MainWndID, "visible", "", &hv_WindowID[2]);
	 MainWndID = (Hlong)this->ui.label_9->winId();
	 OpenWindow(0, 0, 611, 441, MainWndID, "visible", "", &hv_WindowID[3]);
	 MainWndID = (Hlong)this->ui.label_10->winId();
	 OpenWindow(0, 0, 611, 441, MainWndID, "visible", "", &hv_WindowID[4]);
	 MainWndID = (Hlong)this->ui.label_11->winId();
	 OpenWindow(0, 0, 611, 441, MainWndID, "visible", "", &hv_WindowID[5]);

	 MainWndID = (Hlong)this->ui.label_12->winId();
	 OpenWindow(0, 0, 171, 201, MainWndID, "visible", "", &hv_WindowID2[0]);
	 MainWndID = (Hlong)this->ui.label_13->winId();
	 OpenWindow(0, 0, 171, 201, MainWndID, "visible", "", &hv_WindowID2[1]);
	 MainWndID = (Hlong)this->ui.label_14->winId();
	 OpenWindow(0, 0, 171, 201, MainWndID, "visible", "", &hv_WindowID2[2]);
	 MainWndID = (Hlong)this->ui.label_15->winId();
	 OpenWindow(0, 0, 171,201, MainWndID, "visible", "", &hv_WindowID2[3]);
	 MainWndID = (Hlong)this->ui.label_16->winId();
	 OpenWindow(0, 0, 171, 201, MainWndID, "visible", "", &hv_WindowID2[4]);
	 MainWndID = (Hlong)this->ui.label_17->winId();
	 OpenWindow(0, 0, 171, 201, MainWndID, "visible", "", &hv_WindowID2[5]);

	 for (int i = 0; i < 4; i++)
	 {
		
		 HTuple x, y;
		 GetImageSize(himage1[i],&x,&y);
		 SetPart(hv_WindowID[i], 0, 0, y, x);
		 DispObj(himage1[i], hv_WindowID[i]);
	 }
	 for (int i = 0; i < 4; i++)
	 {

		 HTuple x, y;
		 GetImageSize(himage1[i], &x, &y);
		 SetPart(hv_WindowID2[i], 0, 0, y, x);
		 DispObj(himage1[i], hv_WindowID2[i]);
	 }


	
	 initialgrid();
	 readcameraset();
	 Dh.readSpeed();
	 TurnTable->readconsole();

	 ProductSet();

	 m_pTimer = new QTimer(this);
	 //设置时间间隔
	 m_pTimer->setInterval(1000);
	 //设置时间的精确度,默认的
	 m_pTimer->setTimerType(Qt::CoarseTimer);
	 //连接timeout()信号到适当的槽函数，并调用start()，然后在恒定的时间间隔会发射timeout()信号。
	 connect(m_pTimer, SIGNAL(timeout()), this, SLOT(OntimeShowResult()));
	 m_pTimer->start();
	 move(5,10);
	 this->show();
}

void CameraDtecte1::LinkCamera()
{
	list<CCamera*>::iterator it;
	for (it = Cameras->begin() ; it != Cameras->end(); it++)
	{
		(*it)->LinkCamera();
	}

}
void CameraDtecte1::GetProduct()
{

}
void CameraDtecte1::readcameraset()
{

	QString dpath = QDir::currentPath() + "/Data/CameraSettings.xml";
	QFile file(dpath);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		std::cerr << "Error: Cannot read file " << qPrintable(dpath)
			<< ": " << qPrintable(file.errorString())
			<< std::endl;
	}
	QXmlStreamReader reader(&file);
	reader.readNext();
	int i = 0;
	Cameras->clear();
	while (!reader.atEnd()) {
		if (reader.isStartElement()) {
			qDebug() << reader.name();
			if (reader.name() != "CCD")
			{
				CCamera *camera = new CCamera(this);
				camera->sort = i;
				camera->logicname = reader.name().toString().toStdString();
				camera->devicename = reader.attributes().value("name").toString().toStdString();
				camera->gain = reader.attributes().value("Gain").toInt();
				camera->exposuretime = reader.attributes().value("ExposureTime").toInt();
				camera->pixel = reader.attributes().value("pixel").toInt();
				//qDebug() << reader.name() << reader.attributes().value("PhotoWidth").toInt();

				//connect(camera, &CCamera::sigCurrentImage,this,&CameraDtecte1::imageProgress);
				//connect(camera, &CCamera::sigCurrentImage, [=](ImageResult img) {
				//	imageProgress(img);
				//	//DispObj(img, hv_WindowID);
				//});
				connect(camera, SIGNAL(sigCurrentImage(ImageResult*)), this, SLOT(imageProgress(ImageResult*)));
			//	connect(camera, SIGNAL(sigCurrentImage3(int)), this, SLOT(imageProgress2(int)));
				bool kk = camera->CheckCamera();
				if (!kk )
				{
						 QMessageBox::warning(this, "warning", QString::fromStdString(camera->devicename) + u8"未连接", QMessageBox::Ok, QMessageBox::NoButton);
				}
				Cameras->push_back(camera);
					i++;
				
			}
		}
		
		reader.readNext();
	}
	cameracount = i;
	TurnTable->CameraCount = i;
	file.close();
	if (reader.hasError()) {
		std::cerr << "Error: Failed to parse file "
			<< qPrintable(dpath) << ": "
			<< qPrintable(reader.errorString()) << std::endl;
	}
	else if (file.error() != QFile::NoError) {
		std::cerr << "Error: Cannot read file " << qPrintable(dpath)
			<< ": " << qPrintable(file.errorString())
			<< std::endl;
	}
}

int kk = 0;
int  kkk = 0;
void CameraDtecte1::imageProgress(ImageResult* ir)
{
	//qDebug() << "show image";
	try {
		if (!ir->Imagepos->image.IsInitialized())
		{
			qDebug() << "falseimage";
			return;
		}
	//	if (kkk%3 ==1)
		{
			DispObj(ir->Imagepos->image, hv_WindowID[ir->CCD]);
			DispObj(ir->Imagepos->image, hv_WindowID2[ir->CCD]);
		}
		kkk++;
	
		int row = model->rowCount();
		QString ccd = "CCD" + QString::number(ir->CCD + 1);

		int rnum2 = 0;
		for (int i = 0; i < row; i++)
		{
			QModelIndex ind = model->index(i, 0);
			//需要保持同一个ccd的值在一起
			if (model->data(ind).toString() == ccd)
			{
				int rnum = i;
				int allresult1 = 1;
				
				if (!ir->tresult->empty())
				{


					list< toolresult >::iterator it;
					for (it = ir->tresult->begin(); it != ir->tresult->end(); it++)
					{
						bool isg = true;
						int j = 0;
						for (; !it->name[j].empty(); j++)
						{

							double min, max;
							double goodper;
							double goodnum,allnum;
							try {
								min = model->data(model->index(rnum + j, 2)).toDouble();
								max = model->data(model->index(rnum + j, 3)).toDouble();
							}
							catch (exception e) {
								min = 0;
								max = 0;
							}
							model->setData(model->index(rnum + j, 4), it->data[j]);
							QModelIndex ind5 = model->index(rnum + j, 5);
							QModelIndex ind7 = model->index(rnum + j, 7);
							QModelIndex ind8 = model->index(rnum + j, 8);
							goodnum = model->data(ind7).toDouble();
							allnum = model->data(ind8).toDouble();
							
							allnum++;
							model->setData(ind8, allnum);
							
							if (min <= it->data[j] && max >= it->data[j])
							{
								model->setData(ind5, "OK");
								model->item(rnum + j, 5)->setForeground(QBrush(QColor(0, 255, 0)));
								goodnum++;
								model->setData(ind7, goodnum);
							}
							else
							{
								model->setData(ind5, "NG");
							    model->item(rnum + j, 5)->setForeground(QBrush(QColor(255, 0, 0)));
								isg = false;
							}
							goodper = goodnum / allnum;
							model->setData(model->index(rnum + j, 6), goodper);
							it->isgood = isg;
							if (!isg)
							{
								allresult1 = 0;
							}

						}
						rnum += j;
					}

				}
				ir->allresult = allresult1;

				break;
			}
		}
		kk++;
		turntable::instance->mut1.lock();
		if (!turntable::instance->nutlist->empty())
		{
			//checkdata
			list<nut>::iterator it;
			for (it = turntable::instance->nutlist->begin(); it != turntable::instance->nutlist->end(); it++)
			{
			//	if (it->initialPos == ir->Imagepos->pos &&it->state == ir->CCD)
				if (it->initialPos == ir->Imagepos->pos)
				{

					if (ir->allresult == 0 || it->outnum == 0)
					{
						qDebug() << "error reslut ";
						it->outnum = 0;
					}
					else 
					{

						it->outnum = 1;
					}
					it->state++;
					if (!ir->tresult->empty())
					{
						list< toolresult>::iterator itt;
						for (itt = ir->tresult->begin(); itt != ir->tresult->end(); itt++)
						{
							int m = 0;
							
							for (; !itt->name[m].empty(); m++)
							{
								it->result << QString::number(itt->data[m]);
							}
						}
					}

				}
			}
		}

		turntable::instance->mut1.unlock();
		if (!ir->tresult->empty())
		{
			list< toolresult>::iterator itt;
			for (itt = ir->tresult->begin(); itt != ir->tresult->end(); itt++)
			{
				(itt)->~toolresult();
			}
		}
		ir->tresult->clear();
		delete ir->tresult;
		delete ir->Imagepos;
		delete ir;

	}
	catch (exception e) {

	}


}

void CameraDtecte1::testimage()
{
	ImageResult * ir;
	while (onrun) {

		list<CCamera*>::iterator it;
		for (it = Cameras->begin(); it != Cameras->end(); it++)
		{
			if (! (*it)->imageresults->empty())
			{

				ir = & (*it)->imageresults->front();

				DispObj(ir->Imagepos->image, hv_WindowID[(*it)->sort]);

			}
		}
	}
}

int cll = 9;

void CameraDtecte1::initialgrid()
{
	
	model = new QStandardItemModel(2, cll, this);

	
	header << "CCD" << QString::fromLocal8Bit("检测项") << QString::fromLocal8Bit("下限") << QString::fromLocal8Bit("上限")
		<< QString::fromLocal8Bit("测量") << "OKorNG" << QString::fromLocal8Bit("良率")<< QString::fromLocal8Bit("良品")<<QString::fromLocal8Bit("总数");
	for (int i = 0; i < cll; i++)
	{
		model->setHeaderData(i, Qt::Horizontal, header[i]);
	}
	ui.tableView->setModel(model);
	ui.tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
	for (int i = 0; i < cll; i++)
	{
		ui.tableView->setColumnWidth(i, 88);
		
	}
	for (int i = 0; i < cll; i++)
	{
		//设置字符颜色
		model->setItem(0, i, new QStandardItem("2009441676"));
		model->item(0, i)->setForeground(QBrush(QColor(255, 0, 0)));
	}
	QList<QStandardItem*> itemlist;
	QStandardItem *item;
	item = new QStandardItem(CurrentCCD);
	itemlist << item;
	item = new QStandardItem("111");
	itemlist << item;
	model->insertRow(0,itemlist);
	qDebug() << itemlist;
	QModelIndex ind = model->index(0,2);
	model->setData(ind, "qq");
	qDebug() << model->data(ind).toString()<<"QModelIndex";
	//model->removeRow(1);
	//model->removeRow(1);
	//savegird();
	model->setRowCount(0);
}

void CameraDtecte1::updatagrid(QString ccd)
{
	// 修改值
	// 删除ccd
	int row = model->rowCount();
	int kk;
	bool isccd =true;
	for (int i = 0; i < model->rowCount(); i++)
	{	
		QModelIndex ind = model->index(i,0);
		if (model->data(ind).toString() == ccd)
		{
			if (isccd)
			{
				kk = i;
				isccd =false;
			}
			
			model->removeRow(i);
			i--;
		}
	}
	if (isccd)
	{
		kk = model->rowCount();
	}
	//添加新的
	list< CCamera *>::iterator it;
	for (it = Cameras->begin(); it != Cameras->end(); it++)
	{
		if ((*it)->logicname == CurrentCCD.toStdString())
		{
			toolresult *tr;
			list<imagetools*>::iterator iter;
			for (iter = (*it)->tools->begin()  ; iter != (*it)->tools->end(); iter++)
			{
				tr = &(*iter)->Toolresult;
				for (int j = 0; !tr->name[j].empty(); j++)
				{
					QList<QStandardItem*> itemlist;
					QStandardItem *item;
					item = new QStandardItem(CurrentCCD);
					itemlist << item;
					item = new QStandardItem(QString::fromStdString( tr->name[j]));
					itemlist << item;
					model->insertRow(kk, itemlist);
					kk++;
				}
				
			}
		}

	};

	//保存值
	savegird();
}

void CameraDtecte1::readcameratools()
{
	list< CCamera *>::iterator it;
	for (it = Cameras->begin(); it != Cameras->end(); it++)
	{
		(*it)->gettools();
	}
}

void CameraDtecte1::readshowdata()
{
	QString dpath = PathHelper::currentproductpath + "/Product.xml";
	//QString dpath = QDir::currentPath() + "/Product.xml";

	QFile file(dpath);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		qDebug() << "Error: Cannot read file " << qPrintable(dpath)
			<< ": " << qPrintable(file.errorString());
	}
	QXmlStreamReader reader(&file);
	int kk = 0;
	while (!reader.atEnd()) {
		reader.readNext();
		//qDebug() << reader.name()<< reader.tokenType();
		if (reader.isStartElement()) {
			
			if (reader.name() == "config")
			{
				
				//model->setRowCount(kk);
				int i = 0;
				QList<QStandardItem*> itemlist;
				QStandardItem *item;
				while (reader.readNextStartElement()) {
					if (reader.name() == header[i])
					{
						QString sdata = reader.readElementText();
						if (i == 1)
						{
							turntable::instance->ResultName << sdata<<" ";
						}
						if (sdata.isEmpty()|| i>5)
						{
							sdata = QString::number(0);

						}
						item=  new QStandardItem(sdata);
						itemlist << item;
						i++;
					}
				}
				model->insertRow(model->rowCount(), itemlist);
				kk++;
				// qDebug() << reader.readElementText();
			}
		}
	}
	file.close();
	turntable::instance->ResultName << "\n" << " ";
	qDebug() << turntable::instance->ResultName;
	turntable::instance->ONETXT = kk * 1000;
	if (reader.hasError()) {
		qDebug() << "Error: Failed to parse file "
			<< qPrintable(dpath) << ": "
			<< qPrintable(reader.errorString());
	}
	else if (file.error() != QFile::NoError) {
		qDebug() << "Error: Cannot read file " << qPrintable(dpath)
			<< ": " << qPrintable(file.errorString());
	}

}




void CameraDtecte1::savegird()
{
	QString dpath = PathHelper::currentproductpath + "/Product.xml";
	//QString dpath = QDir::currentPath()+ "/Product.xml";
	QFile file(dpath);
	file.open(QIODevice::WriteOnly);
	//QXmlStreamWriter xmlWriter(&file);
	QXmlStreamWriter writer(&file);
	writer.setAutoFormatting(true);//自动化格式
	//	writer.writeStartDocument("1.0", true); //开始文档（xml声明）
	writer.writeStartElement("root");//开始根元素
	int row = model->rowCount();
	for (int j = 0; j < row; j++)
	{

		writer.writeStartElement("config");//开始子元素
		writer.writeAttribute("id", "iddd");
		for (int i = 0; i < header.size(); i++)
		{
			QModelIndex ind = model->index(j, i);
			writer.writeTextElement(header.at(i), model->data(ind).toString());
		}
		writer.writeEndElement();//结束子元素
	}

	writer.writeEndElement();//结束根元素
	writer.writeEndDocument();//结束文档

	file.close();
}



bool isfirstrun = true;
void CameraDtecte1::imageProgress2(int image)
{
	//ui.lineEdit_12->setText(QString::number(image));
}

void CameraDtecte1::StartBtn()
{
	ui.toolButton_3->setDisabled(true);

	onrun = true;
	LinkCamera();

//	Cameras->front()->Start();
	list<CCamera*>::iterator it;
	for (it = Cameras->begin(); it != Cameras->end(); it++)
	{
		//qDebug() << (*it)->getFeatureTriggerModeType()<<"mode";
		(*it)->Start();
	}
	if (isfirstrun)
	{
		PCI408_set_encoder(Card::Axis0, 0);
		
		isfirstrun = false;
		
	}

	std::thread thread5(std::bind(&turntable::startrun, TurnTable));
	thread5.detach();
	/*std::thread thread6(std::bind(&CameraDtecte1::testimage , this));
	thread6.detach();*/
	//TurnTable->startrun();

}

void CameraDtecte1::StopBtn()
{
	onrun = false;
	ui.toolButton_3->setDisabled(false);
//	this_thread::sleep_for(std::chrono::milliseconds(100));
	TurnTable->stoprun();
	list<CCamera*>::iterator it;
	for (it = Cameras->begin(); it != Cameras->end(); it++)
	{
		(*it)->Stop();
	//	(*it)->Close();
	}

}

void CameraDtecte1::AlgorithmSet()
{
	if (! ui.toolButton_3->isEnabled())
	{
		qDebug() << "AlgorithmSet";
		return ;
	}
	SetAlgorithm *SA = new SetAlgorithm(this); 
	SA->CurrentCCD = CurrentCCD;

	list< CCamera *>::iterator it;
	for (it = Cameras->begin(); it != Cameras->end(); it++)
	{
		if ((*it)->logicname == CurrentCCD.toStdString())
		{
			if ((*it)->imagePos.image.IsInitialized())
			{
				SA->display((*it)->imagePos.image);
			}
		}

	};
	int ret = SA->exec();

	if (ret == QDialog::Accepted)
	{

		
		list< CCamera *>::iterator it;
		for (it = Cameras->begin(); it != Cameras->end(); it++)
		{
			if ((*it)->logicname ==  CurrentCCD.toStdString())
			{
				(*it)->gettools();
			}

		};
		updatagrid(CurrentCCD);
		this->show();

		SA->close();
	}
	else if (ret == QDialog::Rejected)
	{
		SA->close();
		qDebug() << "reject";
	}

	delete SA;

}

void CameraDtecte1::MotionSet()
{
	Pylon::PylonTerminate();
	SetMotion *SM = new SetMotion(this);

	int ret = SM->exec();

	if (ret == QDialog::Accepted)
	{
		this->show();

		SM->close();
	}
	else if (ret == QDialog::Rejected)
	{
		qDebug() << "reject";
	}

	delete SM;
}

void CameraDtecte1::CameraSet()
{
	
	SetCamera *SC;
	if (!Cameras->empty())
	{
		//destory device

		list<CCamera*>::iterator it;
		for (it = Cameras->begin(); it != Cameras->end(); it++)
		{
			(*it)->Close();
		}

		SC = new SetCamera( this);
	}
	else 
	{
		QMessageBox::warning(this, "warning",  u8"相机未连接", QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	int ret = SC->exec();

	if (ret == QDialog::Accepted)
	{
		this->show();

		SC->close();
	}
	else if (ret == QDialog::Rejected)
	{
		qDebug() << "reject";
	}

	delete SC;
}

void CameraDtecte1::ProductSet()
{
	SetProduct *SP = new SetProduct(this);
	int ret = SP->exec();

	if (ret == QDialog::Accepted)
	{
		try {

			 readcameratools();
			//model->clear();
		    readshowdata();
		
		}
		catch (exception e) {
			QMessageBox::warning(this, "warning", e.what(), QMessageBox::Ok, QMessageBox::NoButton);
		}
		this->show();
		ui.lineEdit_13->setText(PathHelper::currentproductname);
		SP->close();
		
	}
	else if (ret == QDialog::Rejected)
	{
		qDebug() << "reject";
	}
	delete SP;
}

void CameraDtecte1::tabchange(int num)
{
	qDebug() << num;
	CurrentCCD = ui.tabWidget->tabText(num);
}
void CameraDtecte1::ReportForm()
{
	QString path = PathHelper::currentproductpath + "/reprot.txt";
	QFile file(path);
	file.open(QIODevice::ReadWrite | QIODevice::Append);
	QTextStream out(&file);
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	QString str = QString::number(sys.wDay) + "-" + QString::number(sys.wHour) + "-" + QString::number(sys.wMinute) + "-" + QString::number(sys.wSecond) ;
	
	
	out << str<<"\n";
	out << QString::fromLocal8Bit("名称:") <<"  "<< PathHelper::currentproductname;
	out << QString::fromLocal8Bit("总数:") <<"  ";
	out << ui.lineEdit_14->text() << "\n";
	out << QString::fromLocal8Bit("良率:") << "  ";
	out << ui.lineEdit_16->text() << "\n";
	out << QString::fromLocal8Bit("良品数:") << "  ";
	out << ui.lineEdit_17->text() << "\n";
	int row = model->rowCount();
	for (int j = 0; j < row; j++)
	{

		for (int i = 0; i < header.size(); i++)
		{
			QModelIndex ind = model->index(j, i);
			if (i == 2)
			{
				out << QString::fromLocal8Bit("测量:") << model->data(ind).toString() << "  ";
			}
			if (i== 6 )
			{
				out << QString::fromLocal8Bit("良率:") << model->data(ind).toDouble() << "  ";
			}
			if (i== 7)
			{
				out << QString::fromLocal8Bit("良品数:") << model->data(ind).toDouble() << "  ";
			}
			if (i == 8)
			{
				out << QString::fromLocal8Bit("总数:") << model->data(ind).toDouble() << "  ";
			}
		}
		out << "\n";
	}
	file.close();
}
int prenum = 0;
int newNUM = 0;
void CameraDtecte1::NumToZero()
{
	prenum = 0;
	AllNum::reset();
	int row = model->rowCount();
	for (int j = 0; j < row; j++)
	{

		for (int i = 0; i < header.size(); i++)
		{
			QModelIndex ind = model->index(j, i);
			if (i == 6 || i == 7|| i == 8)
			{
				model->setData(ind, 0);
			}
		}
	}

}


int emg_kk = 0;

void CameraDtecte1::OntimeShowResult()
{
	int a = AllNum::NutCount;
	int b = AllNum::Goodcount;
	double k1 = AllNum::NutTEST;
	double d;
	if (0==k1)
	{
		d = 0;
	}
	else 
	{
		d = b / k1;
	}
	int c = (a - prenum)*60;
	ui.lineEdit_14->setText(QString::number(a));
	ui.lineEdit_15->setText(QString::number(c));
	ui.lineEdit_16->setText(QString::number(d));
	ui.lineEdit_17->setText(QString::number(b));
	if (c == 0)
	{
		newNUM++;
	}
	else 
	{
		newNUM = 0;
	}
	if (newNUM > 120)
	{
		newNUM = 0;
		StopBtn();
	}
	prenum = a;

	int EMG_state = PCI408_read_inbit(Card::card0, 24);

	if (EMG_state ==1  )
	{
		if ( ui.toolButton_3->isEnabled() && emg_kk == 1 )
		{
			StartBtn();
			emg_kk = 0;
		}
	}
	if(EMG_state == 0 && !ui.toolButton_3->isEnabled())
	{
		StopBtn();
		emg_kk = 1;
	}
}