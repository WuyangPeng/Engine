///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/28 22:19)

#include "Example/BookOperatingSystem/DistributedSystems/DistributedSystemsExport.h"

#include "DistributedSystems.h"

#ifndef BUILDING_DISTRIBUTED_SYSTEMS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_DISTRIBUTED_SYSTEMS_STATIC

namespace DistributedSystems
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_DISTRIBUTED_SYSTEMS_STATIC
