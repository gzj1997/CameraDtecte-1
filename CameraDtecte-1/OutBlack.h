#pragma once
#include"imagetools.h"
#include<qdebug.h>
#include"toolresult.h"

class OutBlack :public imagetools
{
public:
	OutBlack();
	~OutBlack();
	virtual void draw();
	virtual void action();
	
	double row;
	double clonum;
	double radius;
	int h0;
	int h1;
private:
	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<imagetools>(*this);
		ar &row;
		ar &clonum;
		ar &radius;
		ar &h0;
		ar &h1;
		ar &radius;
	}
};