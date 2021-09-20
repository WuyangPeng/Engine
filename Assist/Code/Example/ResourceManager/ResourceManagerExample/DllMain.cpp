// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/26 0:50)

#include "Example/ResourceManager/ResourceManagerExample/ResourceManagerExampleExport.h"

#include "Example/ResourceManager/ResourceManagerExample/ResourceManagerExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(ResourceManagerExample);

#else // !BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(ResourceManagerExample);

#endif // !BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC
