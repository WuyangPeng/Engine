///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 17:09)

#include "Arena/ArenaExport.h"

#include "Arena/Arena.h"

#ifndef BUILDING_ARENA_STATIC

    #include "DllLib.h"

#else  // !BUILDING_ARENA_STATIC

namespace Arena
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ARENA_STATIC
