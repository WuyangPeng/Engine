// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.0.0.0 (2019/09/23 10:11)

#include "Toolset/Example/ExampleToolset/ExampleToolsetExport.h"

#include "Toolset/Example/ExampleToolset/ExampleToolset.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_EXAMPLE_STATIC

	namespace ExampleToolset
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_EXAMPLE_STATIC
