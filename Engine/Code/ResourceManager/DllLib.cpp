/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 20:14)

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
