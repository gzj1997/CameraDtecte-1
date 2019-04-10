#pragma once
#include<string>
#include<Windows.h>
#include<qdir.h>
using namespace std;
class PathHelper
{
public:
	PathHelper();
	~PathHelper();
	static int Permission;
	static QString pastproductname;
	static QString pastproductpath;

	static QString currentproductname;
	static QString currentproductpath;

	static QString datapath;
	static QString productPath;
	static void setproduct();


	static bool newproduct(QString ProductName);
	static bool selectproduct(QString ProductName);
	static bool createDirectory(QString folder);
	//É¾³ýÎÄ¼þ¼Ð
	static bool DelDir(const QString name);


	static void GetAllFileFolder(std::vector<QString> &folder);
	

private:
	static void intial();

};

