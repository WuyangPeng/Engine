// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.3 (2019/09/30 23:03)

#include "LibExample/ACE/ACELibExample/ACELibExampleExport.h"

#include "LibExample/ACE/ACELibExample/ACELibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_ACE_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_ACE_LIB_EXAMPLE_STATIC

	namespace ACELibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_ACE_LIB_EXAMPLE_STATIC
