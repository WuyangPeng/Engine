///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 10:18)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "Toolset/System/SystemToolset/SystemToolset.h"

#ifndef BUILDING_SYSTEM_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_SYSTEM_TOOLSET_STATIC

namespace SystemToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SYSTEM_TOOLSET_STATIC
