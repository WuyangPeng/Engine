// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.3 (2019/10/02 15:17)

#include "LibExample/Freetype/FreetypeLibExample/FreetypeLibExampleExport.h"

#include "LibExample/Freetype/FreetypeLibExample/FreetypeLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_FREETYPE_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_FREETYPE_LIB_EXAMPLE_STATIC

	namespace FreetypeLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_FREETYPE_LIB_EXAMPLE_STATIC
