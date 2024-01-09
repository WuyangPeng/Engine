/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 20:14)

#include "ResourceManager/ResourceManagerExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "ResourceManager/ResourceManagerFwd.h"

#ifndef BUILDING_RESOURCE_MANAGER_STATIC

DLL_MAIN_FUNCTION(ResourceManager);

#else  // !BUILDING_RESOURCE_MANAGER_STATIC

CORE_TOOLS_MUTEX_INIT(ResourceManager);

#endif  // !BUILDING_RESOURCE_MANAGER_STATIC