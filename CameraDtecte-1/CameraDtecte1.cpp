#include "CameraDtecte1.h"

CameraDtecte1::CameraDtecte1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	intial();
}
CameraDtecte1::~CameraDtecte1()
{
	Cameras->front()->Close();
	Pylon::PylonTerminate();
	
}
void CameraDtecte1::intial()
{
	Cameras =new list< CCamera *>();
	TurnTable = new turntable();
	 int card = d2210_board_init();
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

	 HObject himage1;
	 QString str = QDir::currentPath() + "/Data/I1.bmp";
	 HalconCpp::ReadImage(&himage1, str.toStdString().c_str());
	 MainWndID = (Hlong)this->ui.label->winId();
	 OpenWindow(0, 0, 561, 291, MainWndID, "visible", "", &hv_WindowID);
	 HTuple win2;
	 OpenWindow(0, 0, 561, 291, (Hlong)this->ui.label_2->winId(), "visible", "", &win2);
	 DispObj(himage1, hv_WindowID);
	 DispObj(himage1, win2);
	 readcameraset();

	 move(50,50);
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
				connect(camera, &CCamera::sigCurrentImage, [=](HObject img) {
					imageProgress(img);
					//DispObj(img, hv_WindowID);
				});
				if (! camera->CheckCamera())
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
void CameraDtecte1::imageProgress(HObject image)
{
	qDebug() << "ssssss";
	DispObj(image,hv_WindowID);
	if (kk % 100 ==1)
	{
		QString str = QDir::currentPath() + "/Data/I1.bmp";
	//	HalconCpp::WriteImage(image, "bmp", 0, str.toStdString().c_str());
	}
	kk++;
}


bool isfirstrun = true;
void CameraDtecte1::StartBtn()
{
	ui.toolButton_3->setDisabled(true);

		LinkCamera();

	Cameras->front()->Start();
	if (isfirstrun)
	{
		d2210_set_encoder(Card::Axis0, 0);
	}
	TurnTable->startrun();

}

void CameraDtecte1::StopBtn()
{
	ui.toolButton_3->setDisabled(false);
	Cameras->front()->Stop();
	Cameras->front()->Close();
}

void CameraDtecte1::AlgorithmSet()
{
	SetAlgorithm *SA = new SetAlgorithm(this); 

	if (Cameras->front()->Himage.IsInitialized())
	{
		SA->display(Cameras->front()->Himage);
	}
	int ret = SA->exec();

	if (ret == QDialog::Accepted)
	{
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
		this->show();

		SP->close();
	}
	else if (ret == QDialog::Rejected)
	{
		qDebug() << "reject";
	}

	delete SP;
}
