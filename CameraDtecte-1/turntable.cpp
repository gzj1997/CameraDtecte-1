#include"turntable.h"

turntable * turntable::instance = nullptr;
turntable::turntable()
{
	isrun = false;
	instance = this;
	nutlist = new list<nut>();
	//SaveResult = new QList<double>();
	SaveToOne = true;
	for (int i = 0; i < 6; i++)
	{
		CameraNut[i] = new cameranut();
		allpos[i] = new list<int>();
		IOs[i] = 0;
		position[i] = 0;
		callcamera[i] = 0;
		precallcamera[i] = 0;

	}
	cameracallIO[0] = 2;
	cameracallIO[1] = 34;
	cameracallIO[2] = 30;//31
	cameracallIO[3] = 3;//21
	cameracallIO[4] = 4;//32
}

turntable::~turntable()
{
}

void turntable::startrun()
{
	PCI408_write_SEVON_PIN(Card::Axis0, Card::ON);
	PCI408_set_profile(Card::Axis0, Card::minspeed, DateHelper::speed_1, Card::acc, Card::acc);
	PCI408_set_position(Card::Axis0, 200000);
	PCI408_set_encoder(Card::Axis0, 200000);
	if (!isrun)
	{
		isrun = true;
		run();
	//	std::thread thread3(std::bind(&turntable::run, this));
	}
	
}

void turntable::stoprun()
{
	PCI408_decel_stop(Card::Axis0, Card::acc);

	isrun = false;
	this_thread::sleep_for(std::chrono::milliseconds(20));
}


int badkkk = 0;
void turntable::run()
{
	int presignal =0;
	int csignal = PCI408_read_inbit(Card::Axis0,0);
	int currentPos = PCI408_get_encoder(Card::Axis0);
	int jcqbz;
	PCI408_counter_config(0, 3);

	PCI408_config_latch_mode(Card::card0, 0);

	PCI408_reset_latch_flag(Card::card0);
	PCI408_vmove(Card::Axis0,1, DateHelper::speed_1);

	for (int i = 0; i < CameraCount+ValveCount; i++)
	{
		PCI408_compare_clear_points_Extern(Card::card0, i + 1);
	}

	while (isrun)
	{

	   

		currentPos = PCI408_get_encoder(Card::Axis0);
	//	qDebug() << currentPos;
		jcqbz = PCI408_get_latch_flag(Card::Axis0);//¶ÁÈ¡Ëø´æÆ÷×´Ì¬
		if ((jcqbz & 0xf00) > 0)
		{
			PCI408_reset_latch_flag(Card::Axis0);
			csignal = PCI408_get_latch_value(Card::Axis0);
		}
		
		for (int i = 0; i < CameraCount; i++)
		{
			callcamera[i] = PCI408_read_inbit(Card::card0, cameracallIO[i]);

			if (callcamera[i] ==0 && precallcamera[i] ==1)
			{
				AllNum::imagenumn++;
				SYSTEMTIME sys;
				GetLocalTime(&sys);
				qDebug() << sys.wHour << sys.wMinute << sys.wSecond << sys.wMilliseconds;
			//	if (! allpos[i]->empty())
				{
					int min_abs = 60000;
					int min_position = 0;
					int ks = 0;
					//if (!allpos[i]->empty())
					{
						list<int>::iterator it;
						for (it = allpos[i]->begin(); it != allpos[i]->end(); it++)
						{
							/*if (true)
							{

							}*/
							ks= *it + position[i] - currentPos;
							int pp = abs(ks);
							if (pp< min_abs )
							{
								min_abs = pp;
								min_position = *it;
							}
						}
					}
				

					if (min_abs< 5000)
					{
					
						CameraNut[i]->mut2.lock();
				
						CameraNut[i]->initialPos->append(min_position);

						CameraNut[i]->mut2.unlock();
				
					}
					{
						list<int>::iterator it2;
						for (it2 = allpos[i]->begin(); it2 != allpos[i]->end();)
						{

							if (min_position == *it2)
							{
								it2 = allpos[i]->erase(it2);
							}
							else {

								it2++;
							}

						}
					}
				}

			}
			
			precallcamera[i] = callcamera[i];


		}
		for (int i = 0; i < CameraCount; i++)
		{
			if (!allpos[i]->empty())
			{
				list<int>::iterator it;
				int min = 0;
				for (it = allpos[i]->begin(); it != allpos[i]->end(); )
				{
					min = (*it) + position[i] - currentPos +5000;
					if (min < 0)
					{
						it = allpos[i]->erase(it);
					}
					else {

						it++;
					}
				}
			}
			
		}
	

		// new nut and set position
		if (presignal !=csignal )
		{
			// timer
			nut* Cnut = new nut(csignal);
			Cnut->cnum = CameraCount;
			AllNum::NutCount++;
			qDebug() << "nut* Cnut "<< csignal;
			mut1.lock();
			nutlist->push_back(*Cnut);
			mut1.unlock();
			delete Cnut;
			for (int i = 0; i < CameraCount; i++)
			{
				PCI408_compare_config_Extern(Card::card0 , (ushort)(i + 1), 1, Card::Axis0, 1);
				PCI408_compare_set_pulsetimes_Extern(0, (ushort)(i + 1), 20);
				PCI408_compare_add_point_Extern(Card::card0, (ushort)(i + 1), position[i] + (int)csignal, 1, 9, IOs[i]);
				allpos[i]->push_back(csignal);
			}
		}
		//check camera
		//check result
		mut1.lock();
		if (!nutlist->empty())
		{
			list<nut>::iterator it;
			for (it = nutlist->begin(); it != nutlist->end(); )
			{
				if (currentPos - it->initialPos  > position[CameraCount] - 1000)
				{
					int a = it->gethole();
					AllNum::NutTEST++;

					if (AllNum::NutTEST %10000 ==9999)
					{
						SaveToOne = false;
						std::thread thread_3(std::bind(&turntable::saveonetxt, this));
						thread_3.detach();
					}

					if (SaveToOne)
					{
						if (SaveResult2.size()>0)
						{
							SaveResult << SaveResult2;
							SaveResult2.clear();
						}
						SaveResult << it->result;
						
					}
					else 
					{
						SaveResult2 << it->result;
					}

					 it->result.clear();

					
					switch (a)
					{
					case 1:
						//pn.mnum++;
						//Console.WriteLine("cipin" + pn.mnum);
						qDebug() << "11111";
						//	AllNum::Goodcount++;
						PCI408_compare_config_Extern(Card::card0, (ushort)(CameraCount + 1), 1, Card::Axis0, 1);
						PCI408_compare_set_pulsetimes_Extern(0, (ushort)(CameraCount + 1), 10);
						PCI408_compare_add_point_Extern(Card::card0, (ushort)(CameraCount + 1), position[CameraCount] + it->initialPos, 1, 9, IOs[CameraCount]);
						break;
						//case "3":
						//pn.nnum++;
						//Console.WriteLine("Î´Ê¶±ð" + pn.nnum);
						//PCI408.PCI408_compare_config_Extern(Card.cardNo, (ushort)(cameraCount + 1), 1, Card.zhouhao, 1);
						//PCI408.PCI408_compare_set_pulsetimes_Extern(0, (ushort)(cameraCount + 1), 20);
						//PCI408.PCI408_compare_add_point_Extern(Card.cardNo, (ushort)(cameraCount + 1), PosArray[cameraCount] + (int)nutc.initialPos, 1, 9, IOs[cameraCount]);
						//break;
					case 2:
						//pn.goodNum++;
						//	fwjs2 = fwjs1;
						AllNum::Goodcount++;
						PCI408_compare_config_Extern(Card::card0, (ushort)(CameraCount + 2), 1, Card::Axis0, 1);
						PCI408_compare_set_pulsetimes_Extern(0, (ushort)(CameraCount + 2), 10);
						PCI408_compare_add_point_Extern(Card::card0, (ushort)(CameraCount + 2), position[CameraCount + 1] + it->initialPos, 1, 9, IOs[CameraCount + 1]);
						qDebug() << "2222";
						//PCI408.PCI408_compare_config_Extern(Card.cardNo, (ushort)(cameraCount + 2), 1, Card.zhouhao, 1);
						//PCI408.PCI408_compare_set_pulsetimes_Extern(0, (ushort)(cameraCount + 2), 10);
						//PCI408.PCI408_compare_add_point_Extern(Card.cardNo, (ushort)(cameraCount + 2), PosArray[cameraCount + 1] + (int)nutc.initialPos, 1, 9, IOs[cameraCount + 1]);
						break;

					default:break;
					}

					it = nutlist->erase(it);
				}
				else {
					it++;
				}
			}

		}
		mut1.unlock();

	
		presignal = csignal;
	}
	std::thread thread_3(std::bind(&turntable::saveonetxt, this));
	thread_3.detach();
	//PCI408_decel_stop()
}

void turntable::readconsole()
{
	QString dpath = QDir::currentPath() + "/Data/Position.xml";
	QFile file(dpath);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		qDebug() << "Error: Cannot read file " << qPrintable(dpath)
			<< ": " << qPrintable(file.errorString());
			
	}
	QXmlStreamReader reader(&file);
	reader.readNext();
	int i = 0;
	int k = 0;
	int j = 0;
	while (!reader.atEnd()) {
		if (reader.isStartElement()) {
			if (reader.name() == "camera")
			{
				j = reader.attributes().value("Count").toInt();
			}
			if (reader.name() == "valve")
			{
				ValveCount = reader.attributes().value("Count").toInt();
			}
			if (reader.name() == "Out")
			{
				IOs[i] = reader.attributes().value("IO").toInt();
				i++;
			}
			if (reader.name() == "Position")
			{
				position[k] = reader.attributes().value("Pos").toInt();
				k++;
			}
		}
		reader.readNext();
	}
	file.close();
	if (k!= i || i!= ValveCount + CameraCount || j!= CameraCount )
	{
		qDebug() << "position xml is wrong";
	}
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

void turntable::saveonetxt()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	QString str = QString::number(sys.wDay)+"-" + QString::number(sys.wHour) + "-" + QString::number(sys.wMinute) + "-" + QString::number(sys.wSecond)+".txt";
	QString path =  PathHelper::currentproductpath +"/" +str;
	QFile file(path);
	file.open(QIODevice::ReadWrite | QIODevice::Append);
	QTextStream out(&file);
	out << ResultName.join("");
	out << SaveResult.join(" ");

	file.close();
	SaveResult.clear();
	SaveToOne = true;
}


