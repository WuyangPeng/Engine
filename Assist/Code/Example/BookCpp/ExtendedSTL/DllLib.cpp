///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/02/28 19:36)

#include "Example/BookCpp/ExtendedSTL/ExtendedSTLExport.h"

#include "ExtendedSTL.h"

#ifndef BUILDING_EXTENDED_STL_STATIC

    #include "DllLib.h"

#else  // BUILDING_EXTENDED_STL_STATIC

namespace ExtendedSTL
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_EXTENDED_STL_STATIC
