///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/10 13:56)

#include "Toolset/ResourceManager/ResourceManagerToolset/ResourceManagerToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/ResourceManager/ResourceManagerToolset/ResourceManagerToolsetFwd.h"

#ifndef BUILDING_RESOURCE_MANAGER_STATIC

DLL_MAIN_FUNCTION(ResourceManager);

#else  // !BUILDING_RESOURCE_MANAGER_STATIC

CORE_TOOLS_MUTEX_INIT(ResourceManager);

#endif  // !BUILDING_RESOURCE_MANAGER_STATIC
