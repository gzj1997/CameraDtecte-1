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
	// Ψһ��ʶ
	int initialPos;
	// ͼƬ�������
	int state;
	// ���λ��
	int posNo;
	//���Ͽ�
	int outnum;
//	QList<double>* result;
	QStringList result;
	// �������
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


