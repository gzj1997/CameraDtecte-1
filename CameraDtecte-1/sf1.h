#pragma once
#include"imagetools.h"
#include<qdebug.h>
#include"toolresult.h"
class sf1:public imagetools
{
public:
	sf1();
	~sf1();

	int mianji;
	virtual void draw();
	virtual void  action();


private:
	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<imagetools>(*this);
		ar &mianji;
	}
};
