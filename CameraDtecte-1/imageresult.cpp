#include "imageresult.h"
#include<qdebug.h>
ImageResult::ImageResult(int i):CCD(i)
{
	Imagepos = nullptr;
	tresult = nullptr;

}


ImageResult::~ImageResult()
{
	//qDebug() << "~ImageResult";


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
