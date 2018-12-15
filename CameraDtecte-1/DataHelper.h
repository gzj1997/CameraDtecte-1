#pragma once

#include<qdir.h>
#include<qstring.h>
#include<string>
#include<ostream>
#include<string.h>
#include <iostream>
#include<qxmlstream.h>
#include<qdebug.h>
#include<qdom.h>
using namespace std;

class DateHelper
{
public:

	DateHelper();
	~DateHelper(); 

	static int speed_1;

	static QString CCD;
	static int pixel;
	static double expose;
	static int gain;

	static void setconsole();
	static void readSpeed();
	static void savecamera();
	static void setcamera(QString name,int g,int p,double e );
private:

};

