#include"chartdata.h"

chartdata::chartdata()
{
	//n1 = 0;
	//n2 = 0;
	n3 = 0;
}

chartdata::~chartdata()
{
}

void chartdata::getdata(int x, int y, QString data)
{
	switch (x)
	{
	case 1:

		minlist[y] = data; break;
	case 2:

		maxlist[y] = data; break;
	default:
		break;
	}
}

void chartdata::gettype(int y, QString type)
{
	typelist[y] = type;
}

double chartdata::checktype(int num)
{
	int i;
	for ( i= 0; !typelist[i].isEmpty() && i<num ; i++)
	{
		if (minlist[i].isEmpty())
		{
			minlist[i] = QString::number(100);
		}
		if (maxlist[i].isEmpty())
		{
			maxlist[i] = QString::number(99999999);
		}
	}
	n3 = i;
	return 0;
}
