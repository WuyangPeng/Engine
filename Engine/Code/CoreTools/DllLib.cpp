/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/27 22:11)

#include "CoreToolsExport.h"

#include "CoreTools.h"

#ifndef BUILDING_CORE_TOOLS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_CORE_TOOLS_STATIC

namespace CoreTools
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // BUILDING_CORE_TOOLS_STATIC