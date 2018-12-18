#pragma once
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
	int gethole();
private:

};

class cameranut
{
public:
	cameranut();
	~cameranut();
	int initialPos;
	bool onwrite;
	
private:

};
enum Hole
{
	thefirst = 1,
	thesecond = 2
};


