// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/23 23:18)

#include "Example/Network/NetworkExample/NetworkExampleExport.h"

#include "Example/Network/NetworkExample/NetworkExample.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_NETWORK_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_NETWORK_EXAMPLE_STATIC

	namespace NetworkExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_NETWORK_EXAMPLE_STATIC
