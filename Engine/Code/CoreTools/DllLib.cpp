///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.2 (2023/02/05 14:43)

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