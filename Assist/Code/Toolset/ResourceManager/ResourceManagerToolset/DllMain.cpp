///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:33)

#include "Toolset/ResourceManager/ResourceManagerToolset/ResourceManagerToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/ResourceManager/ResourceManagerToolset/ResourceManagerToolsetFwd.h"

#ifndef BUILDING_RESOURCE_MANAGER_STATIC

DLL_MAIN_FUNCTION(ResourceManager);

#else  // !BUILDING_RESOURCE_MANAGER_STATIC

CORE_TOOLS_MUTEX_INIT(ResourceManager);

#endif  // !BUILDING_RESOURCE_MANAGER_STATIC
