///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 17:11)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "Toolset/System/SystemToolset/SystemToolset.h"

#ifndef BUILDING_SYSTEM_TOOLSET_STATIC

    #include "DllLib.h"

#else  // BUILDING_SYSTEM_TOOLSET_STATIC

namespace SystemToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SYSTEM_TOOLSET_STATIC
