///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#include "Example/BookCpp/APIDesignForCpp/APIDesignForCppExport.h"

#include "APIDesignForCpp.h"

#ifndef BUILDING_API_DESIGN_FOR_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_API_DESIGN_FOR_CPP_STATIC

namespace APIDesignForCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_API_DESIGN_FOR_CPP_STATIC
