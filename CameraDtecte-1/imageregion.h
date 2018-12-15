#pragma once
#pragma once
#include"HalconCpp.h"
#include"para.h"
using namespace HalconCpp;

class ImageRegion
{
public:
	ImageRegion();
	ImageRegion(HalconCpp::HObject image, Para* pa);
	~ImageRegion();

	Para pa;
	HalconCpp::HObject image;

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
		ar & pa;
	}
};


