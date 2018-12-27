#include"nut.h"

nut::nut(int pos):initialPos(pos)
{
	//the fiste state
	state = 0;
	posNo = 0;
	
}

nut::~nut()
{
}

int nut::gethole()
{
	if (state != cnum) {
		return 1;
	}
	else
	{
		return 1;
	}
}

cameranut::cameranut()
{
	initialPos = 0;
	onwrite = false;
}

cameranut::~cameranut()
{
}
