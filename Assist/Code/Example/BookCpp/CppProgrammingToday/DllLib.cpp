///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/13 23:17)

#include "Example/BookCpp/CppProgrammingToday/CppProgrammingTodayExport.h"

#include "CppProgrammingToday.h"

#ifndef BUILDING_CPP_PROGRAMMING_TODAY_STATIC

    #include "DllLib.h"

#else  // BUILDING_CPP_PROGRAMMING_TODAY_STATIC

namespace CppProgrammingToday
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CPP_PROGRAMMING_TODAY_STATIC
