#include "sf2.h"

sf2::sf2()
{
	Toolresult = *new toolresult();
}

sf2::~sf2()
{
}

void sf2::draw()
{
	HObject  ho_Imagem, ho_Circley1, ho_ImageReducedm;
	HObject  ho_Borderm, ho_SmoothedContoursm;

	// Local control variables
	
	HTuple hv_Lengthm, hv_Indicesm;

	ho_Imagem = image;

	//*模板

	DrawCircle(window, &hv_Rowy1, &hv_Columny1, &hv_Radiusy1);
	GenCircle(&ho_Circley1, hv_Rowy1, hv_Columny1, hv_Radiusy1);
	ReduceDomain(ho_Imagem, ho_Circley1, &ho_ImageReducedm);

	CreateScaledShapeModel(ho_ImageReducedm, "auto", -1, 1, "auto", 0.95, 1.05, "auto",
		"point_reduction_high", "use_polarity", "auto", "auto", &hv_ModelID);
	
	WriteShapeModel(hv_ModelID, (PathHelper::currentproductpath + "yuanhuan.shm").toStdString().c_str());

	AreaCenter(ho_ImageReducedm, &hv_Aream, &hv_Rowm, &hv_Columnm);
	ThresholdSubPix(ho_ImageReducedm, &ho_Borderm, 128);
	SmoothContoursXld(ho_Borderm, &ho_SmoothedContoursm, 3);
	LengthXld(ho_SmoothedContoursm, &hv_Lengthm);
	TupleFind(hv_Lengthm, hv_Lengthm.TupleMax(), &hv_Indicesm);
	SelectObj(ho_SmoothedContoursm, &ho_ObjectSelectedm, hv_Indicesm + 1);

	WriteContourXldDxf(ho_ObjectSelectedm, (PathHelper::currentproductpath +"/1.dxf").toStdString().c_str());

	bool ok = false;
	n1 = 10;
	n1= QInputDialog::getDouble( imageregion.parent, QString::fromLocal8Bit("请输入数值"),
		QString::fromLocal8Bit("请输入取点间隔（参考值10"),10,0,50,1, &ok);
	n2 = 5;
	n2 = QInputDialog::getDouble(imageregion.parent, QString::fromLocal8Bit("请输入数值"),
		QString::fromLocal8Bit("请输入平滑数值（参考值5）"), 5, 0, 50, 1, &ok);
	n3 = 0.01;
	n3 = QInputDialog::getDouble(imageregion.parent, QString::fromLocal8Bit("请输入数值"),
		QString::fromLocal8Bit("请输入角度偏移（参考值0.01）"), 0.01, 0, 50, 3, &ok);
	n4 = 0.996;
	n4 = QInputDialog::getDouble(imageregion.parent, QString::fromLocal8Bit("请输入数值"),
		QString::fromLocal8Bit("请输入比例（参考值0.996）"), 0.996, 0, 50, 3, &ok);

	circlex = hv_Rowy1[0].D();
	circley = hv_Columny1[0].D();
	circleradius = hv_Radiusy1[0].D();

	aream = hv_Aream[0].D();
	rowm = hv_Rowm[0].D();
	columnm = hv_Columnm[0].D();


}

void sf2::action()
{

	// Local iconic variables
	HObject  ho_Imagem, ho_Circley1, ho_ImageReducedm;
	HObject  ho_Borderm, ho_SmoothedContoursm, ho_ObjectSelectedm;
	HObject  ho_Image, ho_Region, ho_ImageReduced, ho_Border;
	HObject  ho_SmoothedContours, ho_ObjectSelected, ho_Region3;
	HObject  ho_ConnectedRegions, ho_SelectedRegions, ho_RegionFillUp;
	HObject  ho_MBObjectXLD1, ho_Region1, ho_RegionDifference;
	HObject  ho_MBObjectXLD2, ho_Region4, ho_RegionDifference1;
	HObject  ho_MBObjectXLDx, ho_Region5, ho_RegionDifference2;
	HObject  ho_ContourAB, ho_RegionLines;

	// Local control variables
	HTuple  hv_Rowy1, hv_Columny1, hv_Radiusy1;
	HTuple  hv_Aream, hv_Rowm, hv_Columnm, hv_Lengthm, hv_Indicesm;
	HTuple  hv_Length, hv_Indices, hv_Row5, hv_Col1, hv_m, hv_m1;
	HTuple  hv_m2, hv_m3, hv_Distance, hv_k, hv_Row, hv_Column;
	HTuple  hv_Angle, hv_Scale, hv_Score, hv_HomMat2D1;
	HTuple  hv_HomMat2DScale1, hv_Area, hv_Row1, hv_Column1;
	HTuple  hv_HomMat2D2, hv_HomMat2DScale2, hv_Area1, hv_Row2;
	HTuple  hv_Column2, hv_HomMat2D, hv_Area2, hv_Row3, hv_Column3;
	HTuple  hv_Row1111, hv_Col1111, hv_WRowMOD, hv_WColMOD;
	HTuple  hv_Conut, hv_j, hv_I, hv_a, hv_b, hv_RowBegin1;
	HTuple  hv_ColBegin1, hv_RowEnd1, hv_ColEnd1, hv_Nr1, hv_Nc1;
	HTuple  hv_Dist1, hv_RowCenter, hv_ColCenter, hv_Length1;
	HTuple  hv_Phi, hv_OffsetLength, hv_RowBegin2, hv_ColBegin2;
	HTuple  hv_RowEnd2, hv_ColEnd2, hv_Row31, hv_Column31, hv_IsOverlapping;
	HTuple  hv_Row32, hv_Column32, hv_IsOverlapping1, hv_IsInside;
	HTuple  hv_distance1, hv_WindowHandle;

	ho_Image = image;

	hv_Rowy1 = circlex;
	hv_Columny1 = circley;
	hv_Radiusy1 = circleradius;

	hv_Aream = aream;
	hv_Rowm = rowm;
	hv_Columnm = columnm;


	////*模板
	//ReadImage(&ho_Imagem, "C:/Users/mxw/Desktop/Image__2019-01-25__13-41-09.bmp");

	//DrawCircle(3600, &hv_Rowy1, &hv_Columny1, &hv_Radiusy1);
	//GenCircle(&ho_Circley1, hv_Rowy1, hv_Columny1, hv_Radiusy1);
	//ReduceDomain(ho_Imagem, ho_Circley1, &ho_ImageReducedm);

	//CreateScaledShapeModel(ho_ImageReducedm, "auto", -1, 1, "auto", 0.95, 1.05, "auto",
	//	"point_reduction_high", "use_polarity", "auto", "auto", &hv_ModelID);
	//AreaCenter(ho_ImageReducedm, &hv_Aream, &hv_Rowm, &hv_Columnm);
	//ThresholdSubPix(ho_ImageReducedm, &ho_Borderm, 128);
	//SmoothContoursXld(ho_Borderm, &ho_SmoothedContoursm, 3);
	//LengthXld(ho_SmoothedContoursm, &hv_Lengthm);
	//TupleFind(hv_Lengthm, hv_Lengthm.TupleMax(), &hv_Indicesm);
	//SelectObj(ho_SmoothedContoursm, &ho_ObjectSelectedm, hv_Indicesm + 1);
	//WriteContourXldDxf(ho_ObjectSelectedm, "C:/Users/mxw/Desktop/2221.dxf");


	////待测
	//ReadImage(&ho_Image, "C:/Users/mxw/Desktop/Image__2019-01-25__13-41-09.bmp");
	//产品图像
	GenRegionPoints(&ho_Region, hv_Rowy1, hv_Columny1);
	GenCircle(&ho_Circley1, hv_Rowy1, hv_Columny1, hv_Radiusy1);//
	ReduceDomain(ho_Image, ho_Circley1, &ho_ImageReduced);
	ThresholdSubPix(ho_ImageReduced, &ho_Border, 128);
	SmoothContoursXld(ho_Border, &ho_SmoothedContours, 3);
	LengthXld(ho_SmoothedContours, &hv_Length);
	TupleFind(hv_Length, hv_Length.TupleMax(), &hv_Indices);
	SelectObj(ho_SmoothedContours, &ho_ObjectSelected, hv_Indices + 1);
	GetContourXld(ho_ObjectSelected, &hv_Row5, &hv_Col1);

	Threshold(ho_ImageReduced, &ho_Region3, 0, 128);
	Connection(ho_Region3, &ho_ConnectedRegions);
	SelectShapeStd(ho_ConnectedRegions, &ho_SelectedRegions, "max_area", 70);
	FillUp(ho_SelectedRegions, &ho_RegionFillUp);


	//invert_image (Image, ImageInvert)
	hv_m = 0;
	hv_m1 = 0;
	hv_m2 = 0;
	hv_m3 = 0;
	hv_Distance = HTuple();
	hv_k = 0;
	FindScaledShapeModel(ho_ImageReduced, hv_ModelID, -1, 1, 0.95, 1.05, 0.3, 1, 0.1,
		"least_squares_very_high", 0, 0.9, &hv_Row, &hv_Column, &hv_Angle, &hv_Scale,
		&hv_Score);
	if (0 != ((hv_Score.TupleLength()) == 1))
	{

		
		//A向
		VectorAngleToRigid(hv_Rowm, hv_Columnm, 0, hv_Row, hv_Column, hv_Angle - 0.01,
			&hv_HomMat2D1);
		HomMat2dScale(hv_HomMat2D1, 1, 1, hv_Column, hv_Row, &hv_HomMat2DScale1);
		AffineTransContourXld(ho_Contours2, &ho_MBObjectXLD1, hv_HomMat2DScale1);
		GenRegionContourXld(ho_MBObjectXLD1, &ho_Region1, "filled");
		Difference(ho_RegionFillUp, ho_Region1, &ho_RegionDifference);
		AreaCenter(ho_RegionDifference, &hv_Area, &hv_Row1, &hv_Column1);
		hv_m1 = hv_Area.TupleSum();
		//B向
		VectorAngleToRigid(hv_Rowm, hv_Columnm, 0, hv_Row, hv_Column, hv_Angle + 0.01,
			&hv_HomMat2D2);
		HomMat2dScale(hv_HomMat2D2, 1, 1, hv_Column, hv_Row, &hv_HomMat2DScale2);
		AffineTransContourXld(ho_Contours2, &ho_MBObjectXLD2, hv_HomMat2DScale2);
		GenRegionContourXld(ho_MBObjectXLD2, &ho_Region4, "filled");
		Difference(ho_RegionFillUp, ho_Region4, &ho_RegionDifference1);
		AreaCenter(ho_RegionDifference1, &hv_Area1, &hv_Row2, &hv_Column2);
		hv_m2 = hv_Area1.TupleSum();
		if (0 != (hv_m1<hv_m2))
		{
			hv_k = hv_Angle - 0.01;
		}
		else
		{
			hv_k = hv_Angle + 0.01;
		}
		VectorAngleToRigid(hv_Rowm, hv_Columnm, 0, hv_Row, hv_Column, hv_k, &hv_HomMat2D);
		HomMat2dScale(hv_HomMat2D, 1, 1, hv_Column, hv_Row, &hv_HomMat2DScale1);
		AffineTransContourXld(ho_Contours2, &ho_MBObjectXLDx, hv_HomMat2DScale1);
		GenRegionContourXld(ho_MBObjectXLDx, &ho_Region5, "filled");
		Union2(ho_Region, ho_Region5, &ho_Region);
		Difference(ho_RegionFillUp, ho_Region5, &ho_RegionDifference2);
		AreaCenter(ho_RegionDifference2, &hv_Area2, &hv_Row3, &hv_Column3);
		hv_m3 = hv_Area2.TupleSum();
		//*中心
		//gen_region_points (Region, Row, Column)

		GetContourXld(ho_MBObjectXLDx, &hv_Row1111, &hv_Col1111);

		//循环一周求间距

		GetContourXld(ho_ObjectSelected, &hv_WRowMOD, &hv_WColMOD);
		hv_Conut = hv_WRowMOD.TupleLength();


		hv_j = 2;
		{
			HTuple end_val87 = hv_Conut;
			HTuple step_val87 = hv_j;
			for (hv_I = 1; hv_I.Continue(end_val87, step_val87); hv_I += step_val87)
			{
				if (0 != (((hv_I + hv_j) - 1) >= hv_Conut))
				{
					break;
				}
				else
				{
					hv_a = hv_WRowMOD.TupleSelectRange(hv_I, (hv_I + hv_j) - 1);
					hv_b = hv_WColMOD.TupleSelectRange(hv_I, (hv_I + hv_j) - 1);
					double aa= hv_a[0].D();
					double aa1 = hv_a[1].D();
					double aa2 = hv_b[0].D();
					double aa3 = hv_b[1].D();
					GenContourNurbsXld(&ho_ContourAB, hv_a, hv_b, "auto", "auto", 3, 1, 5);
					FitLineContourXld(ho_ContourAB, "tukey", -1, 0, 5, 2, &hv_RowBegin1, &hv_ColBegin1,
						&hv_RowEnd1, &hv_ColEnd1, &hv_Nr1, &hv_Nc1, &hv_Dist1);

					//dev_set_color ('red')
					//disp_line (3600, RowBegin1, ColBegin1, RowEnd1, ColEnd1)
					LinePosition(hv_RowBegin1, hv_ColBegin1, hv_RowEnd1, hv_ColEnd1, &hv_RowCenter,
						&hv_ColCenter, &hv_Length1, &hv_Phi);
					hv_OffsetLength = 50;
					hv_RowBegin2 = hv_RowCenter - ((hv_Phi.TupleCos())*hv_OffsetLength);
					hv_ColBegin2 = hv_ColCenter - ((hv_Phi.TupleSin())*hv_OffsetLength);
					hv_RowEnd2 = hv_RowCenter + ((hv_Phi.TupleCos())*hv_OffsetLength);
					hv_ColEnd2 = hv_ColCenter + ((hv_Phi.TupleSin())*hv_OffsetLength);
					if (HDevWindowStack::IsOpen())
						SetColor(HDevWindowStack::GetActive(), "green");
					//DispLine(3600, hv_RowBegin2, hv_ColBegin2, hv_RowEnd2, hv_ColEnd2);

					//求轮廓交点间距
					//模板
					IntersectionSegmentContourXld(ho_ObjectSelected, hv_RowBegin2, hv_ColBegin2,
						hv_RowEnd2, hv_ColEnd2, &hv_Row31, &hv_Column31, &hv_IsOverlapping);

					//产品
					IntersectionSegmentContourXld(ho_MBObjectXLDx, hv_RowBegin2, hv_ColBegin2,
						hv_RowEnd2, hv_ColEnd2, &hv_Row32, &hv_Column32, &hv_IsOverlapping1);
					TestRegionPoint(ho_Region5, hv_Row31, hv_Column31, &hv_IsInside);

					if (0 != (HTuple((hv_Row32.TupleLength()) == (hv_Row31.TupleLength())).TupleAnd(hv_IsInside == 0)))
					{
						DistancePp(hv_Row32, hv_Column32, hv_Row31, hv_Column31, &hv_distance1);
						if (0 != (hv_distance1>1))
						{
							GenRegionLine(&ho_RegionLines, hv_Row32, hv_Column32, hv_Row31, hv_Column31);
							Union2(ho_Region, ho_RegionLines, &ho_Region);
						}

						hv_Distance = hv_Distance.TupleConcat(hv_distance1);
					}
				}
			}
		}
		
		if (0 != ((hv_Distance.TupleLength())>0))
		{
			hv_m = hv_Distance.TupleMax();
			HTuple x, y;
			GetImageSize(ho_Image, &x, &y);
			OpenWindow(0, 0,x , y, 0, "invisible", "", &hv_WindowHandle);
			SetDraw(hv_WindowHandle, "margin");
			SetColor(hv_WindowHandle, "red");
			SetLineWidth(hv_WindowHandle, 5);
			
			DispObj(ho_Image, hv_WindowHandle);
			DispObj(ho_Region, hv_WindowHandle);
			DumpWindowImage(&image, hv_WindowHandle);
			CloseWindow(hv_WindowHandle);
		}
		else
		{
			hv_m = 0;
		}
	}
	else
	{
		hv_m = 999;
	}

	Toolresult.name[0] = "area";
	Toolresult.data[0] = hv_m[0].D();
}

void sf2::getsf()
{
	ReadShapeModel((PathHelper::currentproductpath + "yuanhuan.shm").toStdString().c_str(), &hv_ModelID);
	ReadContourXldDxf(&ho_Contours2, (PathHelper::currentproductpath + "/1.dxf").toStdString().c_str(), HTuple(), HTuple(),
		&hv_DxfStatus);//
}
