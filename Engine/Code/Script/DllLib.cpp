///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/26 14:30)

#include "Script/ScriptExport.h"

#include "Script/Script.h"

#ifndef BUILDING_SCRIPT_STATIC

    #include "DllLib.h"

#else  // BUILDING_SCRIPT_STATIC

namespace Script
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SCRIPT_STATIC