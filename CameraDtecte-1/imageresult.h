#pragma once
#include"HalconCpp.h"
#include"toolresult.h"
using namespace HalconCpp;

class imagepos
{
public:
	imagepos();
	imagepos(int p, HObject himage);
	~imagepos();
	int pos;

	HObject image;



private:

};


class ImageResult
{
public:
	ImageResult(int i);
	~ImageResult();

	int CCD;
	int allresult;
	imagepos *Imagepos;
	list< toolresult > *tresult;

private:

};

