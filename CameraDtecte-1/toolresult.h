#pragma once
#include"para.h"
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
#include<fstream>
#include <string> 
#define MAX_LISTNUM1  6
class toolresult
{
public:
	string name[MAX_LISTNUM1];
	double data[MAX_LISTNUM1];
	bool isshow[MAX_LISTNUM1];
	bool isgood;
	toolresult();
	~toolresult();
	toolresult * cloner() {
		toolresult *a = new toolresult();
		*a = *this;
		return a;
	}

private:
	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & name;
		ar &data;
		ar &isshow;
	}
};

