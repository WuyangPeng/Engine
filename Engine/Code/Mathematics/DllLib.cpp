// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 14:24)

// ��ѧ�⣨Mathematics����װ���������ѧ���ܡ�
// ��ѧ��λ������ĵ����㣬ֻ������������е�CoreTools�⣬
// ��ʹ��boost��stlsoft���߿⡣��ѧ���װ�����Դ�����صļ��㡣

// ��ѧ���������ģ�飺
// 1.	Macro���꣩
// 2.	Base��������	
// 3.	Algebra��������
// 4.	Objects2D��2D����
// 5.	Objects3D��3D����
// 6.	Rational����������
// 7.	NumericalAnalysis����ֵ������
// 8.	Query����ѯ��
// 9.	Approximation�����ƣ� 
// 10.	Distance�����룩
// 11.	Intersection���ཻ��
// 12.	ComputationalGeometry�����㼸�Σ�	
// 13.	Containment��������	
// 14.	CurvesSurfacesVolumes���������������
// 15.	Interpolation����ֵ��	
// 16.	Meshes������
// 17.	Miscellaneous�����

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

