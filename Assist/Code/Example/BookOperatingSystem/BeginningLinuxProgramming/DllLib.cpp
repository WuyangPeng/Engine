///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/21 20:53)

#include "Example/BookOperatingSystem/BeginningLinuxProgramming/BeginningLinuxProgrammingExport.h"

#include "BeginningLinuxProgramming.h"

#ifndef BUILDING_BEGINNING_LINUX_PROGRAMMING_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BEGINNING_LINUX_PROGRAMMING_STATIC

namespace BeginningLinuxProgramming
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BEGINNING_LINUX_PROGRAMMING_STATIC
