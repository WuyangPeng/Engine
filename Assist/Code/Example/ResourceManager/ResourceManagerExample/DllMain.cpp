///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 18:15)

#include "Example/ResourceManager/ResourceManagerExample/ResourceManagerExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/ResourceManager/ResourceManagerExample/ResourceManagerExampleFwd.h"

#ifndef BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(ResourceManagerExample);

#else  // !BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(ResourceManagerExample);

#endif  // !BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC
