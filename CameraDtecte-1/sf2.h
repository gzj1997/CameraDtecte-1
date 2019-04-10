#pragma once
#include"toolresult.h"
#include"imagetools.h"
#include<PathHelper.h>

class sf2 :public imagetools
{
public:
	sf2();
	~sf2();
	virtual void draw();
	virtual void  action();
	virtual void getsf();
	
	double circlex;
	double circley;
	double circleradius;

	double aream;
	double rowm;
	double columnm;

	double n1;
	double n2;
	double n3;
	double n4;
	
	HTuple  hv_Rowy1, hv_Columny1, hv_Radiusy1, hv_ModelID, hv_DxfStatus;
	HTuple  hv_Aream, hv_Rowm, hv_Columnm;
	HObject  ho_ObjectSelectedm;
	HObject  ho_Contours2;
private:
	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<imagetools>(*this);
		ar & circlex;
		ar & circley;
		ar & circleradius;
		ar & aream;
		ar & rowm;
		ar & columnm;
		ar & n1;
		ar & n2;
		ar & n3;
		ar & n4;
	}
};

