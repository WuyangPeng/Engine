///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.1.0 (2021/01/21 23:03)

#include "Example/BookCpp/AdvancedCpp/AdvancedCppExport.h"

#include "AdvancedCpp.h"

#ifndef BUILDING_ADVANCED_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_ADVANCED_CPP_STATIC

namespace AdvancedCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ADVANCED_CPP_STATIC
