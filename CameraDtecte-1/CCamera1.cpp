#include"CCamera1.h"


CCamera1::CCamera1()
{
	intial();
}

CCamera1::~CCamera1()
{
}

void CCamera1::LinkCamera()
{
	CDeviceInfo cinfo;
	cinfo.SetFriendlyName(devicename.c_str());
	CTlFactory& tlFactory = CTlFactory::GetInstance();
	instantcamera.Attach(tlFactory.CreateDevice(cinfo));
	instantcamera.Open();

	getFeatureTriggerSourceType();
	setFeatureTriggerModeType(false );
}

void CCamera1::GetImage()
{
	try {
		// This smart pointer will receive the grab result data.
		CGrabResultPtr ptrGrabResult;
	

		while (instantcamera.IsGrabbing()&& isoncatch)
		{
			// Wait for an image and then retrieve it. A timeout of 5000 ms is used.
			instantcamera.RetrieveResult(5000, ptrGrabResult, TimeoutHandling_ThrowException);

			// Image grabbed successfully?
			if (ptrGrabResult->GrabSucceeded())
			{
				HObject newimage;
				// Access the image data.
				qDebug() << "SizeX: " << ptrGrabResult->GetWidth() << endl;
				qDebug() << "SizeY: " << ptrGrabResult->GetHeight() << endl;
				
				CopyToImage(ptrGrabResult, newimage);
				imagelist->push(newimage);
			}
			else
			{
				qDebug() << "Error: " << ptrGrabResult->GetErrorCode() << " " << ptrGrabResult->GetErrorDescription() << endl;
			}
		}
	}
	catch(exception e){
		qDebug() << e.what();
	}
}
void CCamera1::CopyToImage(CGrabResultPtr pInBuffer, HObject & OutImage)
{
	const uint8_t *pImageBuffer = (uint8_t *)pInBuffer->GetBuffer();
//	qDebug() << "Gray value of first pixel: " << (uint32_t)pImageBuffer[0] << endl << endl;
	GenImage1(&OutImage, "byte", (Hlong)pInBuffer->GetWidth(), (Hlong)pInBuffer->GetHeight(), *pImageBuffer);

}

void CCamera1::disposeimage()
{
	while (true)
	{
		while (!imagelist->empty())
		{
			Himage = imagelist->front();
			imagelist->pop();
			if (!Himage.IsInitialized())
			{
				qDebug() << "no image ";
				break;
			}

		//	emit sigCurrentImage(Himage);

		}
		this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}


void CCamera1::Start()
{
	try {
		
		isoncatch = true;
		qDebug() << "SBaslerCameraControl StartAcquire" << m_currentMode;
		if (m_currentMode == "Freerun") {
			instantcamera.StartGrabbing(GrabStrategy_LatestImageOnly, GrabLoop_ProvidedByInstantCamera);
		}
		else if (m_currentMode == "Software") {
			instantcamera.StartGrabbing(GrabStrategy_LatestImageOnly);
			GetImage();
		}
		else if (m_currentMode == "Line1") {
			instantcamera.StartGrabbing(GrabStrategy_OneByOne);
			std::thread thread1(std::bind(&CCamera1::GetImage, this));
			tthread = &thread1;
			tthread->detach();
			//GetImage();
		}
		else if (m_currentMode == "Line2") {
			instantcamera.StartGrabbing(GrabStrategy_OneByOne);
		}

		std::thread thread2(&CCamera1::disposeimage,this);
		thread2.detach();

	}
	catch (GenICam::GenericException &e) {
		//        OutputDebugString(L"StartAcquire error:");
		qDebug() << "StartAcquire Error:" << QString(e.GetDescription());
		return ;
	}
}

void CCamera1::Stop()
{
	isoncatch = false;
	//wait for camera grap
	this_thread::sleep_for(std::chrono::milliseconds(10));
	instantcamera.StopGrabbing();

}

void CCamera1::Close()
{
	instantcamera.Close();
}

bool CCamera1::CheckCamera()
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
				if ( it->GetFriendlyName().c_str() == devicename)
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



void CCamera1::setExposureTime(double time)
{
}

int CCamera1::getExposureTime()
{
	return 0;
}

void CCamera1::setFeatureTriggerSourceType(QString type)
{
	////Í£Ö¹²É¼¯
	//if (m_isOpenAcquire) {
	//	StopAcquire();
	//}
	//if (type == "Freerun") {
	//	SetCamera(Type_Basler_Freerun);
	//}
	//else if (type == "Line1") {
	//	SetCamera(Type_Basler_Line1);
	//}
}

QString CCamera1::getFeatureTriggerSourceType()
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

void CCamera1::setFeatureTriggerModeType(bool on)
{
	INodeMap &cameraNodeMap = instantcamera.GetNodeMap();
	CEnumerationPtr  ptrTriggerSel = cameraNodeMap.GetNode("TriggerSelector");
	ptrTriggerSel->FromString("FrameStart");
	CEnumerationPtr  ptrTrigger = cameraNodeMap.GetNode("TriggerMode");
	ptrTrigger->SetIntValue(on ? 1 : 0);
}

bool CCamera1::getFeatureTriggerModeType()
{
	return false;
}

void CCamera1::intial()
{

	imagelist = new queue<HObject>();
	tools = new list<imagetools*>();


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
	//clock_t start, ends;

	//ends = clock();
	//qDebug() << start - ends;
}
