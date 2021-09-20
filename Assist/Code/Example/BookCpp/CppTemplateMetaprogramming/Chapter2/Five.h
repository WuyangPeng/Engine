///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/07 23:38)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_FIVE_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_FIVE_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        struct Five  // integral constant wrapper for the value 5
        {
            static int const value = 5;
            typedef int value_type;
            /* ...more declarations... */
        };
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_FIVE_H
