///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#include "Example/BookCpp/ModernCppDesign/ModernCppDesignExport.h"

#include "ModernCppDesign.h"

#ifndef BUILDING_MODERN_CPP_DESIGN_STATIC

    #include "DllLib.h"

#else  // BUILDING_MODERN_CPP_DESIGN_STATIC

namespace ModernCppDesign
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MODERN_CPP_DESIGN_STATIC
