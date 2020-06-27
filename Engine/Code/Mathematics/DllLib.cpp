// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/18 19:02)

// 数学库（Mathematics）封装了引擎的数学功能。
// 数学库位于引擎的第三层，只允许调用引擎中的CoreTools库，
// 并使用boost、stlsoft工具库。数学库封装了线性代数相关的计算。

// 数学库包含以下模块：
// 1.	Helper（帮助）
// 2.	Base（基础）	
// 3.	Algebra（代数）
// 4.	Objects2D（2D对象）
// 5.	Objects3D（3D对象）
// 6.	Rational（有理数）
// 7.	NumericalAnalysis（数值分析）
// 8.	Query（查询）
// 9.	Approximation（近似） 
// 10.	Distance（距离）
// 11.	Intersection（相交）
// 12.	ComputationalGeometry（计算几何）	
// 13.	Containment（包含）	
// 14.	CurvesSurfacesVolumes（曲线曲面体积）
// 15.	Interpolation（插值）	
// 16.	Meshes（网格）
// 17.	Miscellaneous（杂项）

#include "Mathematics/MathematicsExport.h"

#include "Mathematics/Mathematics.h"

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_MATHEMATICS_STATIC

	#include "DllLib.h"

#else // BUILDING_MATHEMATICS_STATIC

	namespace Mathematics
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_MATHEMATICS_STATIC

