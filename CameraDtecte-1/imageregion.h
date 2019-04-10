#pragma once
#pragma once
#include"HalconCpp.h"
#include"para.h"
#include"chartdata.h"
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 
#include <boost/serialization/string.hpp> 
#include <boost/serialization/export.hpp> 
#include <boost/serialization/list.hpp> 
#include <iostream> 
#include <sstream> 
#include <string> 
#include<qwidget.h>
using namespace HalconCpp;

class ImageRegion
{
public:
	ImageRegion();
	ImageRegion(HalconCpp::HObject image, Para* pa);
	~ImageRegion();

	//Para pa;

	chartdata *chartdata;
	HalconCpp::HObject image;
	HalconCpp::HObject region;
	QWidget * parent;
	int srcollnum;
	bool color;

	void draw();

	ImageRegion * cloner() {
		ImageRegion *a = new ImageRegion();
		*a = *this;
		return a;
	}
private:
	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		//ar & pa;
		ar &color;
		ar &srcollnum;
	}
};


