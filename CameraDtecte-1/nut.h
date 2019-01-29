#pragma once
#include<qdebug.h>
#include<list>
#include<queue>
#include <mutex>
#include<qlist.h>
using namespace std;
class nut
{
public:
	nut(int pos );
	~nut();
	// 唯一标识
	int initialPos;
	// 图片处理个数
	int state;
	// 零件位置
	int posNo;
	//出料口
	int outnum;
//	QList<double>* result;
	QStringList result;
	// 相机个数
	int cnum;
	int gethole();
private:

};

class cameranut
{
public:
	cameranut();
	~cameranut();
//	list<int> *initialPos;
	QList<int> *initialPos;

	mutex mut2;
	bool onwrite;
	
private:

};
enum Hole
{
	thefirst = 1,
	thesecond = 2,
	thethrid
};


