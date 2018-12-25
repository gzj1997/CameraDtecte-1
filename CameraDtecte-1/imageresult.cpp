#include "imageresult.h"

ImageResult::ImageResult()
{
	Imagepos = nullptr;
	tresult = nullptr;

}


ImageResult::~ImageResult()
{
}

imagepos::imagepos()
{
}

imagepos::imagepos(int p, HObject himage):pos(p),image(himage)
{
}

imagepos::~imagepos()
{
}
