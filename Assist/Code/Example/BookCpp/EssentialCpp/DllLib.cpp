///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 23:16)

#include "Example/BookCpp/EssentialCpp/EssentialCppExport.h"

#include "EssentialCpp.h" 

#ifndef BUILDING_ESSENTIAL_CPP_STATIC

    #include "DllLib.h"

#else  // !BUILDING_ESSENTIAL_CPP_STATIC

namespace EssentialCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ESSENTIAL_CPP_STATIC
