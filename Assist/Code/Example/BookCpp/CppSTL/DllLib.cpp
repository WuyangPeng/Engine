///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/27 12:43)

#include "Example/BookCpp/CppSTL/CppSTLExport.h"

#include "CppSTL.h"

#ifndef BUILDING_CPP_STL_STATIC

    #include "DllLib.h"

#else  // BUILDING_CPP_STL_STATIC

namespace CppSTL
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CPP_STL_STATIC
