///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 11:08)

#include "Example/ResourceManager/ResourceManagerExample/ResourceManagerExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/ResourceManager/ResourceManagerExample/ResourceManagerExampleFwd.h"

#ifndef BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(ResourceManagerExample);

#else  // !BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(ResourceManagerExample);

#endif  // !BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC
