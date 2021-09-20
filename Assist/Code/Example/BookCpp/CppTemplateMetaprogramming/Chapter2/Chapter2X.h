///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/07 23:38)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_CHAPTER_2X_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_CHAPTER_2X_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        template <class T, class U>
        struct Chapter2X
        {
            int f(T* x)  // ����
            {
                U y[10]{};  // ����
                return 10;
            }
        };
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_CHAPTER_2X_H
