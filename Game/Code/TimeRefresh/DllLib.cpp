///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/15 14:40)

#include "TimeRefresh/TimeRefreshExport.h"

#include "TimeRefresh/TimeRefresh.h"

#ifndef BUILDING_ACTIVITY_STATIC

    #include "DllLib.h"

#else  // !BUILDING_ACTIVITY_STATIC

namespace TimeRefresh
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ACTIVITY_STATIC
