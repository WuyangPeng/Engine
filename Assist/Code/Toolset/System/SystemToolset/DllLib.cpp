/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 22:21)

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
