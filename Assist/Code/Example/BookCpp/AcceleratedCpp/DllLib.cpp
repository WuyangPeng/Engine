///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 21:29)

#include "Example/BookCpp/AcceleratedCpp/AcceleratedCppExport.h"

#include "AcceleratedCpp.h"

#ifndef BUILDING_ACCELERATED_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_ACCELERATED_CPP_STATIC

namespace AcceleratedCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ACCELERATED_CPP_STATIC
