///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:53)

#ifndef MODERN_CPP_DESIGN_PREFACE_CTASSERT_H
#define MODERN_CPP_DESIGN_PREFACE_CTASSERT_H

#include "Example/BookCpp/ModernCppDesign/ModernCppDesignDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace ModernCppDesign
    {
        template <bool V>
        struct CTAssert;

        template <>
        struct CTAssert<true>
        {        
        };
    }
}

#endif  // MODERN_CPP_DESIGN_PREFACE_CTASSERT_H
