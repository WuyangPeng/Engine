///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 15:58)

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
