#pragma once
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


