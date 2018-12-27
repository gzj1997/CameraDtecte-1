#include "CCamera.h"

CCamera::CCamera(QObject *parent)
	: QObject(parent)
{
	intial();
}

CCamera::~CCamera()
{
}

void CCamera::intial()
{

	imagelist = new queue<HObject>();
	tools = new list<imagetools*>();
	good =* new list<int>();
	bad =* new list<int>();
	tresult = new list< toolresult>();
	imageresults = new list<ImageResult>();
	imagePoS = new list< imagepos>();
	qDebug() << "SBaslerCameraControl: PylonInitialize initSome";
	Pylon::PylonInitialize();
	CTlFactory &TlFactory = CTlFactory::GetInstance();
	TlInfoList_t lstInfo;
	int n = TlFactory.EnumerateTls(lstInfo);

	TlInfoList_t::const_iterator it;
	for (it = lstInfo.begin(); it != lstInfo.end(); ++it) {
		qDebug() << "FriendlyName: " << it->GetFriendlyName() << "FullName: " << it->GetFullName();
		qDebug() << "VendorName: " << it->GetVendorName() << "DeviceClass: " << it->GetDeviceClass();
	}

	qDebug() << "SBasler Camera Count: " << n;

}
void CCamera::LinkCamera()
{
	if (isopen)
	{
		return;
	}
	try
	{
		CDeviceInfo cinfo;
		cinfo.SetFriendlyName(devicename.c_str());
		CTlFactory& tlFactory = CTlFactory::GetInstance();
		instantcamera.Attach(tlFactory.CreateDevice(cinfo));
		instantcamera.Open();
		isopen = true;
		getFeatureTriggerSourceType();
		setFeatureTriggerModeType(false);
	}
	catch (const std::exception&)
	{
		isopen = false;
	}
	
}

void CCamera::GetImage()
{
	try {
		// This smart pointer will receive the grab result data.
		CGrabResultPtr ptrGrabResult;


		while (instantcamera.IsGrabbing() && isoncatch)
		{
			try
			{
				// Wait for an image and then retrieve it. A timeout of 5000 ms is used.
				instantcamera.RetrieveResult(5000, ptrGrabResult, TimeoutHandling_ThrowException);

				// Image grabbed successfully?
				if (ptrGrabResult->GrabSucceeded())
				{
					HObject * newimage = new HObject();
					// Access the image data.
					qDebug() << "SizeX: " << ptrGrabResult->GetWidth() << endl;
					qDebug() << "SizeY: " << ptrGrabResult->GetHeight() << endl;

					CopyToImage(ptrGrabResult, newimage);

					//	delete newimage;
					//imagelist->push(*newimage);
				//	turntable::instance->CameraNut[sort]->onwrite = false;
					//posmin 有问题可能会卡
					posmin =  turntable::instance->CameraNut[sort]->initialPos;
					imagepos* ip = new imagepos(posmin, *newimage);
					imagePoS->push_back(*ip);
				}
				else
				{
					qDebug() << "Error: " << ptrGrabResult->GetErrorCode() << " " << ptrGrabResult->GetErrorDescription() << endl;

				}
			}
			catch (exception e) {
				qDebug() << e.what();
			}
		}
	}
	catch (exception e) {
		qDebug() << e.what();
	}
}


void CCamera::CopyToImage(CGrabResultPtr pInBuffer, HObject * OutImage)
{
	try {
		uchar *pImageBuffer = (uchar *)pInBuffer->GetBuffer();
		//qDebug() << "Gray value of first pixel: " << (uint32_t)pImageBuffer[0] << endl << endl;
		GenImage1(OutImage, "byte", (Hlong)pInBuffer->GetWidth(), (Hlong)pInBuffer->GetHeight(), (Hlong)pImageBuffer);
	}
	catch (exception e) {

	}
	  
}

void CCamera::disposeimage()
{
	while (isoncatch)
	{
		while (!imagePoS->empty())
		{

			imagePos = imagePoS->front();
			
			if (!imagePos.image.IsInitialized())
			{
				qDebug() << "no image ";
				break;
			}

			/*Himage = imagelist->front();
			imagelist->pop();

			if (!Himage.IsInitialized())
			{
				qDebug() << "no image ";
				break;
			}*/
			tresult = new list< toolresult>();
			list<imagetools*>::iterator it;
			
			for ( it = tools->begin(); it != tools->end(); it++)
			{
				(*it)->image = Himage;
				(*it)->action();
				tresult->push_back((*(*it)->Toolresult.cloner()));
			}

			
			imageresult = new ImageResult(sort);
			imageresult->tresult = tresult;
			imageresult->Imagepos = &imagePos;
			
			imagePoS->pop_front();
		//	imageresults->push_back(*imageresult);
				emit sigCurrentImage(*imageresult);
		//	imageresults->pop_front();
		}
		this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void CCamera::gettools()
{
	tools->clear();
	QString pt = PathHelper::currentproductpath + "/" + QString::fromStdString(logicname) + ".txt";
	//	std::ifstream ifs("filename", std::ios::binary);
	std::ifstream file(pt.toStdString());
	boost::archive::text_iarchive ia(file);
	ia >> tools;
}


void CCamera::Start()
{
	try {

		isoncatch = true;

		qDebug() << "SBaslerCameraControl StartAcquire" << m_currentMode;
		if (m_currentMode == "Freerun") {
			instantcamera.StartGrabbing(GrabStrategy_LatestImageOnly, GrabLoop_ProvidedByInstantCamera);
		}
		else if (m_currentMode == "Software") {
			instantcamera.StartGrabbing(GrabStrategy_LatestImageOnly);
			std::thread thread3(std::bind(&CCamera::GetImage, this));
			tthread = &thread3;
			tthread->detach();
		}
		else if (m_currentMode == "Line1") {
			instantcamera.StartGrabbing(GrabStrategy_OneByOne);
			std::thread thread1(std::bind(&CCamera::GetImage, this));
			tthread = &thread1;
			tthread->detach();
			//GetImage();
		}
		else if (m_currentMode == "Line2") {
			instantcamera.StartGrabbing(GrabStrategy_OneByOne);
		}

		std::thread thread2(&CCamera::disposeimage, this);
		thread2.detach();

	}
	catch (GenICam::GenericException &e) {
		//        OutputDebugString(L"StartAcquire error:");
		qDebug() << "StartAcquire Error:" << QString(e.GetDescription());
		return;
	}
}

void CCamera::Stop()
{

	isoncatch = false;
	//wait for camera grap
	this_thread::sleep_for(std::chrono::milliseconds(20));
	try {
		if (instantcamera.IsGrabbing()) {
			instantcamera.StopGrabbing();
		}
	}
	catch (GenICam::GenericException &e) {
		//        OutputDebugString(LPCWSTR(e.GetDescription()));
		qDebug() << "StopAcquire Error:" << QString(e.GetDescription());
	}
	
}

void CCamera::Close()
{
	
	qDebug() << "SBaslerCameraControl deleteAll: Close";
	if (! isopen)
	{
		return;
	}
	try {
		if (instantcamera.IsOpen()) {
		//	instantcamera.DetachDevice();
			instantcamera.Close();
		}
	}
	catch (GenICam::GenericException &e) {
		//        OutputDebugString(LPCWSTR(e.GetDescription()));
		qDebug() << "CloseCamera Error:" << QString(e.GetDescription());
	}
//	Pylon::PylonInitialize();
//	Pylon::PylonTerminate();
}

bool CCamera::CheckCamera()
{
	bool islink = false;
	try
	{
		// Get the transport layer factory.
		CTlFactory& tlFactory = CTlFactory::GetInstance();
		// Get all attached devices and exit application if no device is found.
		DeviceInfoList_t devices;

		if (tlFactory.EnumerateDevices(devices) == 0)
		{
			throw RUNTIME_EXCEPTION("No camera present.");
		}
		DeviceInfoList_t::const_iterator it;
		for (it = devices.begin(); it != devices.end(); ++it) {
			//		qDebug() << it->GetFriendlyName().c_str();
			if (it->GetFriendlyName().c_str() == devicename)
			{

				//	deviceinfo = devices.begin();
				islink = true;
			}
		}
	}
	catch (const GenericException &e)
	{

	}
	return islink;
}



void CCamera::setcameraset(CCamera_Type index, double tmpValue)
{
	INodeMap &cameraNodeMap = instantcamera.GetNodeMap();
	switch (index) {
	case Type_Basler_Freerun: {
		CEnumerationPtr  ptrTriggerSel = cameraNodeMap.GetNode("TriggerSelector");
		ptrTriggerSel->FromString("FrameStart");
		CEnumerationPtr  ptrTrigger = cameraNodeMap.GetNode("TriggerMode");
#ifdef Real_Freerun
		ptrTrigger->SetIntValue(0);
#else //Software
		ptrTrigger->SetIntValue(1);
		CEnumerationPtr  ptrTriggerSource = cameraNodeMap.GetNode("TriggerSource");
		ptrTriggerSource->FromString("Software");
#endif
	} break;
	case Type_Basler_Line1: {
		CEnumerationPtr  ptrTriggerSel = cameraNodeMap.GetNode("TriggerSelector");
		ptrTriggerSel->FromString("FrameStart");
		CEnumerationPtr  ptrTrigger = cameraNodeMap.GetNode("TriggerMode");
		ptrTrigger->SetIntValue(1);
		CEnumerationPtr  ptrTriggerSource = cameraNodeMap.GetNode("TriggerSource");
		ptrTriggerSource->FromString("Line1");
	} break;
	case Type_Basler_ExposureTimeAbs: {
		const CFloatPtr exposureTime = cameraNodeMap.GetNode("ExposureTimeAbs");
		exposureTime->SetValue(tmpValue);
	} break;
	case Type_Basler_GainRaw: {
		const CIntegerPtr cameraGen = cameraNodeMap.GetNode("GainRaw");
		cameraGen->SetValue(tmpValue);
	} break;
	case Type_Basler_AcquisitionFrameRateAbs: {
		const CBooleanPtr frameRate = cameraNodeMap.GetNode("AcquisitionFrameRateEnable");
		frameRate->SetValue(TRUE);
		const CFloatPtr frameRateABS = cameraNodeMap.GetNode("AcquisitionFrameRateAbs");
		frameRateABS->SetValue(tmpValue);
	} break;
	case Type_Basler_Width: {
		const CIntegerPtr widthPic = cameraNodeMap.GetNode("Width");
		widthPic->SetValue(tmpValue);
	} break;
	case Type_Basler_Height: {
		const CIntegerPtr heightPic = cameraNodeMap.GetNode("Height");
		heightPic->SetValue(tmpValue);
	} break;
	case Type_Basler_LineSource: {
		CEnumerationPtr  ptrLineSource = cameraNodeMap.GetNode("LineSource");
		ptrLineSource->SetIntValue(2);
	} break;
	default:
		break;
	}
}

double CCamera::getcameraset(CCamera_Type index)
{
	INodeMap &cameraNodeMap = instantcamera.GetNodeMap();
	switch (index) {
	case Type_Basler_ExposureTimeAbs: {
		const CFloatPtr exposureTime = cameraNodeMap.GetNode("ExposureTimeAbs");
		return exposureTime->GetValue();
	} break;
	case Type_Basler_GainRaw: {
		const CIntegerPtr cameraGen = cameraNodeMap.GetNode("GainRaw");
		return cameraGen->GetValue();
	} break;
	case Type_Basler_AcquisitionFrameRateAbs: {
		const CBooleanPtr frameRate = cameraNodeMap.GetNode("AcquisitionFrameRateEnable");
		frameRate->SetValue(TRUE);
		const CFloatPtr frameRateABS = cameraNodeMap.GetNode("AcquisitionFrameRateAbs");
		return frameRateABS->GetValue();
	} break;
	case Type_Basler_Width: {
		const CIntegerPtr widthPic = cameraNodeMap.GetNode("Width");
		return widthPic->GetValue();
	} break;
	case Type_Basler_Height: {
		const CIntegerPtr heightPic = cameraNodeMap.GetNode("Height");
		return heightPic->GetValue();
	} break;
	default:
		return -1;
		break;
	}
}

void CCamera::setExposureTime(double time)
{
	setcameraset(Type_Basler_ExposureTimeAbs, time);
}

int CCamera::getExposureTime()
{
	return  getcameraset(Type_Basler_ExposureTimeAbs);
}

void CCamera::setpixel(int p)
{
	pixel = p;
}

int CCamera::getpixel()
{
	return pixel;
}

void CCamera::setgain(int gain)
{
	setcameraset(Type_Basler_GainRaw, gain);
}

int CCamera::getgain()
{
	return getcameraset(Type_Basler_GainRaw);
}

void CCamera::setFeatureTriggerSourceType(QString type)
{
	if (isoncatch) {
		Stop();
	}
	if (type == "Freerun") {
		setcameraset(Type_Basler_Freerun);
	}
	else if (type == "Line1") {
		setcameraset(Type_Basler_Line1);
	}
}

QString CCamera::getFeatureTriggerSourceType()
{
	INodeMap &cameraNodeMap = instantcamera.GetNodeMap();
	CEnumerationPtr  ptrTriggerSel = cameraNodeMap.GetNode("TriggerSelector");
	ptrTriggerSel->FromString("FrameStart");
	CEnumerationPtr  ptrTrigger = cameraNodeMap.GetNode("TriggerMode");
	ptrTrigger->SetIntValue(1);
	CEnumerationPtr  ptrTriggerSource = cameraNodeMap.GetNode("TriggerSource");

	String_t str = ptrTriggerSource->ToString();
	m_currentMode = QString::fromLocal8Bit(str.c_str());
	return m_currentMode;
}

void CCamera::setFeatureTriggerModeType(bool on)
{
	INodeMap &cameraNodeMap = instantcamera.GetNodeMap();
	CEnumerationPtr  ptrTriggerSel = cameraNodeMap.GetNode("TriggerSelector");
	ptrTriggerSel->FromString("FrameStart");
	CEnumerationPtr  ptrTrigger = cameraNodeMap.GetNode("TriggerMode");
	ptrTrigger->SetIntValue(on ? 1 : 0);
}

bool CCamera::getFeatureTriggerModeType()
{
	return false;
}


