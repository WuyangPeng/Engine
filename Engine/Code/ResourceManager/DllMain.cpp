/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 20:14)

#include "ResourceManager/ResourceManagerExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "ResourceManager/ResourceManagerFwd.h"

#ifndef BUILDING_RESOURCE_MANAGER_STATIC

DLL_MAIN_FUNCTION(ResourceManager);

#else  // !BUILDING_RESOURCE_MANAGER_STATIC

CORE_TOOLS_MUTEX_INIT(ResourceManager);

#endif  // !BUILDING_RESOURCE_MANAGER_STATIC