// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/30 11:16)

// ͼ������⣨Imagics��λ������ĵ��Ĳ㣬ֻ������������е�CoreTools��Mathematics�⣬
// ��ʹ��boost��stlsoft���������ݿ���صĹ��߿⡣
// ����2D��3Dͼ���������Ļ������̣����2Dͼ����ȡ�������ߣ����3Dͼ������ȡ�������档

// ͼ��������������ģ�飺
// 1.   Macro���꣩
// 2.	BinaryOperations��������� 
// 3.	Extraction����ȡ�� 
// 4.	Filters���������� 
// 5.	Images��ͼƬ�� 
// 6.	RasterDrawing����դͼ�� 
// 7.	Segmenters���߶Σ� 
// 8.	OpenCV��OpenCV��

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