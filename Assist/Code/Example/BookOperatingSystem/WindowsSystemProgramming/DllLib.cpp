///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/12 16:54)

#include "Example/BookOperatingSystem/WindowsSystemProgramming/WindowsSystemProgrammingExport.h"

#include "WindowsSystemProgramming.h"

#ifndef BUILDING_WINDOWS_SYSTEM_PROGRAMMING_STATIC

    #include "DllLib.h"

#else  // !BUILDING_WINDOWS_SYSTEM_PROGRAMMING_STATIC

namespace WindowsSystemProgramming
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_WINDOWS_SYSTEM_PROGRAMMING_STATIC
