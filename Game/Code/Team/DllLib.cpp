///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 17:10)

#include "Team/TeamExport.h"

#include "Team/Team.h"

#ifndef BUILDING_TEAM_STATIC

    #include "DllLib.h"

#else  // !BUILDING_TEAM_STATIC

namespace Team
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_TEAM_STATIC
