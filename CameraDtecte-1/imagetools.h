#pragma once
#include"HalconCpp.h"
#include"imageregion.h"
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 
#include <boost/serialization/string.hpp> 
#include <boost/serialization/export.hpp> 
#include <boost/serialization/list.hpp> 
#include<sstream>
#include<iostream>
#include <fstream> 
#include"toolresult.h"
using namespace std;
using namespace HalconCpp;

class imagetools
{
public:
	imagetools();

	virtual ~imagetools();

	toolresult Toolresult;
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
		ar & Toolresult;
	}
};


