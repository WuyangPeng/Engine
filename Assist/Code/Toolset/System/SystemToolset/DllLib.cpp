///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/05 15:01)

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