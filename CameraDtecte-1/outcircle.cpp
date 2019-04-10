#include "outcircle.h"

outcircle::outcircle()
{
	Toolresult = *new toolresult();
}

outcircle::~outcircle()
{
}

void outcircle::draw()
{

}

void outcircle::action()
{
	// Local iconic variables
	HObject  ho_Image, ho_Region, ho_ConnectedRegions;
	HObject  ho_SelectedRegions, ho_RegionTrans, ho_Circle;

	// Local control variables
	HTuple  hv_Row, hv_Column, hv_Radius;

	ReadImage(&ho_Image, "fabrik");
	Threshold(ho_Image, &ho_Region, 0,imageregion.srcollnum);
	Connection(ho_Region, &ho_ConnectedRegions);
	SelectShapeStd(ho_ConnectedRegions, &ho_SelectedRegions, "max_area", 70);
	ShapeTrans(ho_SelectedRegions, &ho_RegionTrans, "outer_circle");
	SmallestCircle(ho_RegionTrans, &hv_Row, &hv_Column, &hv_Radius);
	GenCircle(&ho_Circle, hv_Row, hv_Column, hv_Radius);

	Toolresult.name[0] = "radius";
	Toolresult.data[0] = hv_Radius[0].D();
}

void outcircle::getsf()
{
}
