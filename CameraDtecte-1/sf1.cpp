#include"sf1.h"
sf1::sf1()
{
	Toolresult =* new toolresult();
}

sf1::~sf1()
{
}

void sf1::draw()
{
	qDebug() << "sf1  draw";
	int n= imageregion.chartdata->n3;
	for (int i = 0; i <n  ; i++)
	{
		if (imageregion.chartdata->typelist[i] == "area")
		{
			mianji = imageregion.chartdata->minlist[i].toInt();
		}
	}
}

void sf1::action()
{
	//qDebug() << "sf1  action";
	try {
		HalconCpp::HObject  ho_Image, ho_ImageMean, ho_RegionDynThresh;
		HalconCpp::HObject  ho_ConnectedRegions, ho_SelectedRegions, ho_SortedRegions;
		HalconCpp::HObject  ho_ObjectSelected;
		HalconCpp::HObject cir;
		// Local control variables
		HalconCpp::HTuple  hv_thr, hv_dth, hv_zxmj, hv_zxck, hv_r;
		HalconCpp::HTuple  hv_c, hv_area, hv_Area1, hv_Row1, hv_Column1, hv_a;
		HalconCpp::HTuple  hv_Number, hv_Area, hv_Row, hv_Column;
		ho_Image = image;
		if (!ho_Image.IsInitialized())
		{
			qDebug() << "no image";
			return;
		}

		hv_thr = imageregion.srcollnum;
		hv_dth = hv_thr;
		hv_zxmj = mianji;
		hv_zxck = mianji;

		hv_r = 0;
		hv_c = 0;
		hv_area = 0;
		MeanImage(ho_Image, &ho_ImageMean, hv_thr, hv_thr);
		DynThreshold(ho_Image, ho_ImageMean, &ho_RegionDynThresh, hv_dth, "dark");
		//dilation_circle (RegionDynThresh, RegionDilation, 1)
		Connection(ho_RegionDynThresh, &ho_ConnectedRegions);
		SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, ((HalconCpp::HTuple("area").Append("height")).Append("width")),
			"or", (hv_zxmj.TupleConcat(hv_zxck)).TupleConcat(hv_zxck), ((HalconCpp::HTuple(999999).Append(9999999)).Append(9999999)));
		CountObj(ho_SelectedRegions, &hv_Number);
		if (0 != (hv_Number == 0))
		{
			hv_r = 0;
			hv_c = 0;
			hv_area = 0;
		}
		else if (0 != (hv_Number == 1))
		{
			AreaCenter(ho_SelectedRegions, &hv_Area, &hv_Row, &hv_Column);
			hv_r = hv_Row;
			hv_c = hv_Column;
			hv_area = hv_Area;
			HalconCpp::GenCircle(&cir, hv_Area, hv_Row, 200);
		}
		else if (0 != (hv_Number > 1))
		{
			SortRegion(ho_SelectedRegions, &ho_SortedRegions, "upper_right", "false", "column");
			SelectObj(ho_SortedRegions, &ho_ObjectSelected, 1);
			AreaCenter(ho_ObjectSelected, &hv_Area, &hv_Row, &hv_Column);
			hv_r = hv_Row;
			hv_c = hv_Column;
			hv_area = hv_Area;
			//	HalconCpp::GenCircle(&cir, hv_Area, hv_Row, 200);
		}

		
		Toolresult.name[0] = "area";
		Toolresult.data[0] = hv_area[0].D();
	}
	catch (exception e) {

	}
	//if (hv_Number >0)
	//{
	//	AreaCenter(ho_SelectedRegions, &hv_Area1, &hv_Row1, &hv_Column1);
	//	//result = ho_SelectedRegions;
	//	for (int i = 0; i < (int)hv_Number; i++)
	//	{
	//		Result* aa = new Result();
	//		aa->x = (int)((const HalconCpp::HTuple&)hv_Row1)[i].D();
	//		aa->y = (int)((const HalconCpp::HTuple&)hv_Column1)[i].D();
	//		aa->area = (int)((const HalconCpp::HTuple&)hv_Area1)[i].D();
	//	//	showlist->result.push_back(*aa);
	//	}
	//}

}




