///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/25 21:00)

#include "ResourceManager/ResourceManagerExport.h"

#include "ResourceManager/ResourceManager.h"

#ifndef BUILDING_RESOURCE_MANAGER_STATIC

    #include "DllLib.h"

#else  // BUILDING_RESOURCE_MANAGER_STATIC

namespace ResourceManager
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_RESOURCE_MANAGER_STATIC
