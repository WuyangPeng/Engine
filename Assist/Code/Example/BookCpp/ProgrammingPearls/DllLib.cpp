///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#include "Example/BookCpp/ProgrammingPearls/ProgrammingPearlsExport.h"

#include "ProgrammingPearls.h"

#ifndef BUILDING_PROGRAMMING_PEARLS_STATIC

    #include "DllLib.h"

#else  // BUILDING_PROGRAMMING_PEARLS_STATIC

namespace ProgrammingPearls
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_PROGRAMMING_PEARLS_STATIC
