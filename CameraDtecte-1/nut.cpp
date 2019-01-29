#include"nut.h"

nut::nut(int pos):initialPos(pos)
{
	//the fiste state
	state = 0;
	//posNo = 0;
	outnum = 1;
}

nut::~nut()
{

}

int nut::gethole()
{
	result << "\n";
	if (state != cnum) {
		qDebug() << "this is for little image"<< state << initialPos;
		return 3;
	}
	else
	{
		if (outnum == 1)
		{
			return 2;
		}
		else {
			qDebug() << "return1";
			return 1;
		}
	}
}

cameranut::cameranut()
{
	//initialPos = new list<int>();
//	mut2 = new mutex();
	initialPos = new QList<int>();
	onwrite = false;
}

cameranut::~cameranut()
{
}
