#include "SetCamera.h"
SetCamera::SetCamera( QWidget *parent)
	: QDialog(parent)
{

	ui.setupUi(this);
	intail();
}


SetCamera::~SetCamera()
{
	delete currentcamera;
	delete cameras;
}

void SetCamera::intail()
{
	cameras = new list< CCamera *>();


	for (int i = 1; i <= 6; i++)
	{
		setradio(QString::number(i));
	}

	ui.comboBox->addItem(u8"软件");
	ui.comboBox->addItem(u8"硬件");
	readcamera();
	list<CCamera*>::iterator it;
	for (it = cameras->begin(); it != cameras->end(); it++)
	{
		(*it)->LinkCamera();
		QString num = QString::number((*it)->sort + 1);
		setradio(num, 1);
	}
	ui.radioButton_1->setChecked(true);
	setCCD(QString::number(1));
	//currentcamera = cameras->front();

	HObject himage1;
	QString str = QDir::currentPath() + "/Data/I1.bmp";
	HalconCpp::ReadImage(&himage1, str.toStdString().c_str());
	MainWndID = (Hlong)this->ui.label_picture->winId();
	OpenWindow(0, 0, 561, 291, MainWndID, "visible", "", &hv_WindowID);
}

void SetCamera::readcamera()
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
				connect(camera, &CCamera::sigCurrentImage, [=](ImageResult img) {
					
					DispObj(img.Imagepos->image, hv_WindowID);
				});
				if (!camera->CheckCamera())
				{
					QMessageBox::warning(this, "warning", QString::fromStdString(camera->devicename) + u8"未连接", QMessageBox::Ok, QMessageBox::NoButton);
				}
				cameras->push_back(camera);
				i++;
			}
		}
		reader.readNext();
	}
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

void SetCamera::setradio(QString num, int  mode )
{
	QString name = "radioButton_" + num;
	qDebug() << name;
	QRadioButton *tempButton = this->findChild< QRadioButton*>(name);
	switch (mode)
	{
	case 0: tempButton->setDisabled(true); break;
	case 1: tempButton->setDisabled(false); break;
	default:
		break;
	}
}

void SetCamera::setCCD(QString num)
{
	int n = num.toInt();
	list<CCamera*>::iterator it;
    
	for (it = cameras->begin(); it != cameras->end(); it++)
	{
		if (n == (*it)->sort+1)
		{
			
			ui.lineEdit_name->setText(  QString::fromStdString((*it)->devicename));
			ui.lineEdit_expose->setText(QString::number((*it)->exposuretime));
			ui.lineEdit_gain->setText(QString::number((*it)->gain));
			ui.lineEdit_pixie->setText(QString::number((*it)->pixel));
			currentcamera = (*it);
		}
	}
}

void SetCamera::onshot()
{
	//currentcamera->LinkCamera();
	//currentcamera->Start();

}
void SetCamera::conshot()
{
	currentcamera->LinkCamera();
	currentcamera->Start();
}
void SetCamera::stop()
{
	currentcamera->Stop();
	currentcamera->Close();
}
void SetCamera::saveset()
{
	int g = ui.lineEdit_gain->text().toInt();
	int p = ui.lineEdit_pixie->text().toInt();
	double e = ui.lineEdit_expose->text().toDouble();
	DateHelper::setcamera(QString::fromStdString( currentcamera->logicname), g, p, e);
}
void SetCamera::changegain()
{
	currentcamera->setgain(ui.lineEdit_gain->text().toInt());
}
void SetCamera::changepixel()
{
	currentcamera->setpixel(ui.lineEdit_pixie->text().toInt());
}
void SetCamera::changeexpose()
{
	currentcamera->setExposureTime(ui.lineEdit_expose->text().toDouble());
}
void SetCamera::getCCD(bool ison )
{
	if (ison)
	{
		QString num = ((QRadioButton*)sender())->text().right(1);
		setCCD(num);
	}
	qDebug() << ison;
}