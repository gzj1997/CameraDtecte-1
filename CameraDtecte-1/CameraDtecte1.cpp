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

	onrun = false;
	int card = PCI408_card_init();
	 if (card== 0)
	 {
	//	 QMessageBox::warning(this, "warning", u8"运动控制卡未连接", QMessageBox::Ok, QMessageBox::NoButton);
	//	 this->close();
	 }
	 else if ( card > 8 )
	 {
		 //	 QMessageBox::warning(this, "warning", u8"运动控制卡连接错误", QMessageBox::Ok, QMessageBox::NoButton);
		 //	 this->close();
	 }

	 ui.tabWidget->setCurrentIndex(0);
	 CurrentCCD = "CCD1";

	 HObject himage1;
	 QString str = QDir::currentPath() + "/Data/I1.bmp";
	 HalconCpp::ReadImage(&himage1, str.toStdString().c_str());

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

	 for (int i = 0; i < 6; i++)
	 {
		 DispObj(himage1, hv_WindowID[i]);
	 }
	 initialgrid();
	 readcameraset();
	

	 ProductSet();

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
	//Cameras->clear();
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
				qDebug() << reader.name() << reader.attributes().value("PhotoWidth").toInt();

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
void CameraDtecte1::imageProgress(ImageResult* ir)
{
	qDebug() << "ssssss";
	try {
		DispObj(ir->Imagepos->image, hv_WindowID[ir->CCD]);

		//ui.lineEdit_4->setText("233333333");
		if (kk % 1000 == 1)
		{
			QString str = QDir::currentPath() + "/Data/I1.bmp";
			//	HalconCpp::WriteImage(image, "bmp", 0, str.toStdString().c_str());
		}
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
				list< toolresult >::iterator it;
				for (it = ir->tresult->begin(); it != ir->tresult->end(); it++)
				{
					bool isg = true;
					int j = 0;
					for (; !it->name[j].empty(); j++)
					{
						double min, max;
						try {
							min = model->data(model->index( rnum+j, 2)).toDouble();
							max = model->data(model->index(rnum+j, 3)).toDouble();
						}
						catch (exception e) {
							min = 0;
							max = 0;
						}
						model->setData(model->index(rnum + j, 4), it->data[j]);
						QModelIndex ind2 = model->index(rnum + j, 5);

						if (min<=it->data[j] && max>=it->data[j])
						{
							model->setData(ind2, "OK");
							//model->item(rnum + i, 5)->setForeground(QBrush(QColor(0, 255, 0)));
						}
						else
						{
							model->setData(ind2, "NG");
							//	model->item(rnum + i, 5)->setForeground(QBrush(QColor(255, 0, 0)));
							isg = false;
						}
						
						it->isgood = isg;
						if (!isg)
						{
							allresult1 = 0;
						}

					}
					rnum+= j;
				}
				ir->allresult = allresult1;
				break;
			}
		}
		kk++;

		//checkdata
		list<nut>::iterator it;
		for (it = turntable::instance->nutlist->begin(); it != turntable::instance->nutlist->end(); it++)
		{
			if (it->initialPos == ir->Imagepos->pos &&it->state== ir->CCD)
			{
				if (ir->allresult ==0 )
				{
					it->outnum = 0;
				}
				else {
					it->outnum = 1;
				}
				it->state++;
			}
		}
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

int cll = 7;

void CameraDtecte1::initialgrid()
{
	
	model = new QStandardItemModel(2, cll, this);

	
	header << "CCD" << QString::fromLocal8Bit("检测项") << QString::fromLocal8Bit("上限")
		<< QString::fromLocal8Bit("下限") << QString::fromLocal8Bit("测量") << "OKorNG" << QString::fromLocal8Bit("良率");
	for (int i = 0; i < cll; i++)
	{
		model->setHeaderData(i, Qt::Horizontal, header[i]);
	}
	ui.tableView->setModel(model);

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
	for (int i = 0; i < row; i++)
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
		kk = row;
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
	while (!reader.atEnd()) {
		reader.readNext();
		//qDebug() << reader.name()<< reader.tokenType();
		if (reader.isStartElement()) {
			int kk=0;
			if (reader.name() == "config")
			{
				kk++;
				//model->setRowCount(kk);
				int i = 0;
				QList<QStandardItem*> itemlist;
				QStandardItem *item;
				while (reader.readNextStartElement()) {
					if (reader.name() == header[i])
					{
						item=  new QStandardItem(reader.readElementText());
						itemlist << item;
						i++;
					}
				}
				model->insertRow(model->rowCount(), itemlist);
				// qDebug() << reader.readElementText();
			}
		}
	}
	file.close();
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
	ui.lineEdit_12->setText(QString::number(image));
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
	list<CCamera*>::iterator it;
	for (it = Cameras->begin(); it != Cameras->end(); it++)
	{
		(*it)->Stop();
		(*it)->Close();
	}
	//Cameras->front()->Stop();
	//Cameras->front()->Close();
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
	if (Cameras->front()->imagePos.image.IsInitialized())
	{
		SA->display(Cameras->front()->imagePos.image);
	}
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
		SC = new SetCamera( this);
	}
	else 
	{
		QMessageBox::warning(this, "warning",  u8"相机未连接", QMessageBox::Ok, QMessageBox::NoButton);
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
