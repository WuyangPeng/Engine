///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:26)

#include "Status/StatusExport.h"

#include "Status/Status.h"

#ifndef BUILDING_STATUS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_STATUS_STATIC

namespace Status
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_STATUS_STATIC
