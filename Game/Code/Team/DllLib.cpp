///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:49)

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
