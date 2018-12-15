#pragma once
#include"HalconCpp.h"
#include"imageregion.h"
using namespace HalconCpp;

class imagetools
{
public:
	imagetools();

	virtual ~imagetools();

	ImageRegion imageregion;
	HalconCpp::HObject  image;
	HTuple result;
	virtual void action() = 0;
	virtual void draw() = 0;
private:
	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & imageregion;
	}

};


