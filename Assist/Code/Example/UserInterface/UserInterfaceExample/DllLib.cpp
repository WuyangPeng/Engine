// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/27 14:00)

#include "Example/UserInterface/UserInterfaceExample/UserInterfaceExampleExport.h"

#include "Example/UserInterface/UserInterfaceExample/UserInterfaceExample.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_USER_INTERFACE_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_USER_INTERFACE_EXAMPLE_STATIC

	namespace UserInterfaceExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_USER_INTERFACE_EXAMPLE_STATIC
