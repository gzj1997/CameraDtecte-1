#pragma once
#pragma once
#include"HalconCpp.h"
#include"para.h"
#include"chartdata.h"
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
	int srcollnum;
	bool color;

	void	draw();

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


