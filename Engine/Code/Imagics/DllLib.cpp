// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/30 11:16)

// 图像分析库（Imagics）位于引擎的第四层，只允许调用引擎中的CoreTools和Mathematics库，
// 并使用boost、stlsoft和其他数据库相关的工具库。
// 包含2D和3D图像分析处理的基本例程，如从2D图像析取各级曲线，或从3D图像中析取各级表面。

// 图像分析库包含以下模块：
// 1.   Macro（宏）
// 2.	BinaryOperations（运算符） 
// 3.	Extraction（提取） 
// 4.	Filters（过滤器） 
// 5.	Images（图片） 
// 6.	RasterDrawing（光栅图） 
// 7.	Segmenters（线段） 
// 8.	OpenCV（OpenCV）

#include "Imagics/ImagicsExport.h"

#include "Imagics/Imagics.h"

#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"

#ifndef BUILDING_IMAGICS_STATIC

	#include "DllLib.h"

#else // BUILDING_IMAGICS_STATIC

	namespace Imagics
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_IMAGICS_STATIC