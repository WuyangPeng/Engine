///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 13:29)

#include "TimeRefresh/TimeRefreshExport.h"

#include "TimeRefresh/TimeRefresh.h"

#ifndef BUILDING_TIME_REFRESH_STATIC

    #include "DllLib.h"

#else  // !BUILDING_TIME_REFRESH_STATIC

namespace TimeRefresh
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_TIME_REFRESH_STATIC
