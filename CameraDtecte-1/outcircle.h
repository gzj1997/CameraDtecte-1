#pragma once
#include"imagetools.h"
class outcircle:public imagetools
{
public:
	outcircle();
	~outcircle();
	virtual void draw();
	virtual void  action();

private:
	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<imagetools>(*this);
	}

};

