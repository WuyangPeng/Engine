///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 21:29)

#include "Example/BookCpp/BeginningCpp17/BeginningCpp17Export.h"

#include "BeginningCpp17.h"

#ifndef BUILDING_BEGINNING_CPP_17_STATIC

    #include "DllLib.h"

#else  // BUILDING_BEGINNING_CPP_17_STATIC

namespace BeginningCpp17
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BEGINNING_CPP_17_STATIC
