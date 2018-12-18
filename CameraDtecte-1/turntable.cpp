#include"turntable.h"

turntable::turntable()
{
	isrun = false;
	nutlist = new list<nut>();
}

turntable::~turntable()
{
}

void turntable::startrun()
{
	if (!isrun)
	{
		isrun = true;
		std::thread thread3(std::bind(&turntable::run, this));
	}
	
}

void turntable::stoprun()
{
	isrun = false;
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
						if ( CameraNut[i].onwrite = false  )
						{
							CameraNut[i].onwrite = true;
							CameraNut[i].initialPos = it->initialPos;

							d2210_write_outbit(Card::Axis0, IOs[i], Card::ON);
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
}


