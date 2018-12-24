#pragma once
#include<qstring.h>
#define MAX_LISTNUM  5
class chartdata
{
public:
	chartdata();
	~chartdata();
	QString typelist[MAX_LISTNUM];
	QString minlist[MAX_LISTNUM];
	QString maxlist[MAX_LISTNUM];

	int n1, n2, n3;

	void getdata(int x, int y, QString data);
	void gettype(int y, QString type);
	double checktype(int num);
	chartdata * cloner() {
		chartdata *a = new chartdata();
		*a = *this;
		return a;
	}

private:

};

