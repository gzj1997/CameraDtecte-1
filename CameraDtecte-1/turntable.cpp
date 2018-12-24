#include"turntable.h"

turntable * turntable::instance = nullptr;
turntable::turntable()
{
	isrun = false;
	instance = this;
	nutlist = new list<nut>();
	for (int i = 0; i < 6; i++)
	{
		CameraNut[i] = new cameranut();
	}

}

turntable::~turntable()
{
}

void turntable::startrun()
{
	if (!isrun)
	{
		//isrun = true;
		run();
	//	std::thread thread3(std::bind(&turntable::run, this));
	}
	//d2210_write_SEVON_PIN(Card::Axis0, Card::ON);
	//d2210_set_profile(Card::Axis0, Card::minspeed, DateHelper::speed_1, Card::acc, Card::acc);
	//d2210_set_position(Card::Axis0, 200000);
	//d2210_set_encoder(Card::Axis0, 200000);
}

void turntable::stoprun()
{
	
	isrun = false;
	this_thread::sleep_for(std::chrono::milliseconds(20));
}

void turntable::run()
{
	int presignal =0;
	int csignal = d2210_read_inbit(Card::Axis0,0);
	int currentPos = d2210_get_encoder(Card::Axis0);

	while (isrun)
	{
		currentPos = d2210_get_encoder(Card::Axis0);
		csignal = d2210_read_inbit(Card::Axis0, 0);
		
		if (presignal ==1 && csignal == 0)
		{
			// timer
			nut* Cnut = new nut(csignal);

			nutlist->push_back(*Cnut);
		}
		//check camera
		//check result
		
		for (int i = 0; i < CameraCount+ ValveCount; i++)
		{
			list<nut>::iterator it;
			for (it = nutlist->begin(); it != nutlist->end(); it++)
			{
				if (currentPos - it->initialPos >position[i] && it->posNo == i)
				{
					if ( it->posNo< CameraCount )
					{
						if ( CameraNut[i]->onwrite = false  )
						{
							CameraNut[i]->onwrite = true;
							CameraNut[i]->initialPos = it->initialPos;

							d2210_write_outbit(Card::Axis0, IOs[i], Card::ON);
							this_thread::sleep_for(std::chrono::milliseconds(1));
							d2210_write_outbit(Card::Axis0, IOs[i], Card::OFF);
						}

					}
					else if(it->posNo >= CameraCount)
					{
						int k = it->gethole();

						if (k==Hole::thefirst &&  k == it->posNo - CameraCount )
						{

						}

					}
					it->posNo++;
					if (it->posNo >= CameraCount+ValveCount)
					{
						it = nutlist->erase(it);
					}

				}
			}
		}
		presignal = csignal;
	}
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
			if (reader.name() != "camera")
			{
				j = reader.attributes().value("Count").toInt();
			}
			if (reader.name() != "valve")
			{
				ValveCount = reader.attributes().value("Count").toInt();
			}
			if (reader.name() != "Out")
			{
				IOs[i] = reader.attributes().value("IO").toInt();
				i++;
			}
			if (reader.name() != "Position")
			{
				position[i] = reader.attributes().value("Pos").toInt();
				k++;
			}
		}
		reader.readNext();
	}
	file.close();
	if (k!= ValveCount || i!= k+ CameraCount || j!= CameraCount )
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


