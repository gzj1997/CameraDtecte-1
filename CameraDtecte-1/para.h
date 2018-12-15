#pragma once
#pragma once
#include<string.h>
#include<qwindow.h>
#include<iostream>
#include<list>
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 
#include <boost/serialization/string.hpp> 
#include <boost/serialization/export.hpp> 
#include<boost\serialization\list.hpp>
#include <iostream> 
#include <sstream> 
#include <string> 
using namespace std;

class Result
{
public:
	int x;
	int y;
	int area;

};

class ShowList {
public:
	int num;
	list<Result> result;
};

class Para
{
public:
	int  thr;
	int  dth;
	int area_min, area_max;
	int width_min, width_max;

	Para* cloner() {

		Para *a = new  Para();
		*a = *this;
		//a->thr = this->thr;
		//a->dth = this->thr;
		//a->area_max = this->area_max;
		//a->area_min = this->area_min;
		//a->width_max = this->width_max;
		//a->width_min = this->width_min;
		return a;
	}
private:
	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & thr;
		ar & dth;
		ar & width_min;
		ar & width_max;
		ar & area_min;
		ar & area_max;

	}

};