///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 16:37)

#include "Toolset/Script/ScriptToolset/ScriptToolsetExport.h"

#include "Toolset/Script/ScriptToolset/ScriptToolset.h"

#ifndef BUILDING_SCRIPT_STATIC

    #include "DllLib.h"

#else  // BUILDING_SCRIPT_STATIC

namespace ScriptToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SCRIPT_STATIC
