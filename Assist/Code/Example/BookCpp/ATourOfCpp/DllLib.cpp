///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 21:29)

#include "Example/BookCpp/ATourOfCpp/ATourOfCppExport.h"

#include "ATourOfCpp.h"

#ifndef BUILDING_A_TOUR_OF_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_A_TOUR_OF_CPP_STATIC

namespace ATourOfCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_A_TOUR_OF_CPP_STATIC
