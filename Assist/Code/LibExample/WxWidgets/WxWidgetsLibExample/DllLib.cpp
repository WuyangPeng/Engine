// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.3 (2019/10/02 15:02)

#include "LibExample/WxWidgets/WxWidgetsLibExample/WxWidgetsLibExampleExport.h"

#include "LibExample/WxWidgets/WxWidgetsLibExample/WxWidgetsLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_WX_WIDGETS_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_WX_WIDGETS_LIB_EXAMPLE_STATIC

	namespace WxWidgetsLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_WX_WIDGETS_LIB_EXAMPLE_STATIC
