#include "OutBlack.h"

OutBlack::OutBlack()
{
	Toolresult = *new toolresult();
}

OutBlack::~OutBlack()
{

}

void OutBlack::draw()
{
	HTuple  hv_Radius, hv_Row, hv_Column;

	int n = imageregion.chartdata->n3;
	for (int i = 0; i <n; i++)
	{
		if (imageregion.chartdata->typelist[i] == "area")
		{
			h0 = imageregion.chartdata->minlist[i].toInt();
			h1 = imageregion.chartdata->maxlist[i].toInt();
		}
	}

	DrawCircle(window, &hv_Row, &hv_Column, &hv_Radius);
	row =  hv_Row[0].D();
	clonum = hv_Column.D();
	radius = hv_Radius.D();


}

void OutBlack::action()
{
	// Local iconic variables
	HObject  ho_Image, ho_Circle, ho_ImageReduced;
	HObject  ho_Region, ho_ConnectedRegions, ho_SelectedRegions;
	HObject  ho_RegionTrans, ho_Circle1;

	// Local control variables
	HTuple  hv_area1, hv_area2, hv_Row, hv_Column;
	HTuple  hv_Radius, hv_Row1, hv_Column1, hv_Radius1;
	ho_Image = image;
//	ReadImage(&ho_Image, "C:/Users/mxw/Desktop/Image__2019-01-25__13-41-09.bmp");
	hv_area1 = h0;
	hv_area2 = h1;
//	DrawCircle(window, &hv_Row, &hv_Column, &hv_Radius);
	hv_Row = row;
	hv_Column = clonum;
	hv_Radius = radius;
	GenCircle(&ho_Circle, hv_Row, hv_Column, hv_Radius);
	ReduceDomain(ho_Image, ho_Circle, &ho_ImageReduced);
	Threshold(ho_ImageReduced, &ho_Region, 0, 100);
	Connection(ho_Region, &ho_ConnectedRegions);
	SelectShapeStd(ho_ConnectedRegions, &ho_SelectedRegions, "max_area",70);
	/*SelectShapeStd(ho_ConnectedRegions, &ho_SelectedRegions, "area", "and", hv_area1,
		hv_area2);*/
	ShapeTrans(ho_SelectedRegions, &ho_RegionTrans, "outer_circle");
	SmallestCircle(ho_RegionTrans, &hv_Row1, &hv_Column1, &hv_Radius1);
	//GenCircle(&ho_Circle1, hv_Row1, hv_Column1, hv_Radius1);
	Toolresult.name[0] = "radius";
	try {
		Toolresult.data[0] = hv_Radius1[0].D();
	}
	catch(exception ex){
		qDebug()<<  hv_Radius1[0].D();

	}
}

void OutBlack::getsf()
{
}
