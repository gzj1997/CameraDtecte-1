#include "toolresult.h"
#include<qdebug.h>
toolresult::toolresult()
{
	for (int i = 0; i < MAX_LISTNUM1; i++)
	{
		name[i] = "";
		data[i] = 0;
		isshow[i] = false;
	}
}

toolresult::~toolresult()
{
	//qDebug() << "~toolresult";
}
