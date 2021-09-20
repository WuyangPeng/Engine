///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/07 23:38)

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
            int f(T* x)  // 声明
            {
                U y[10]{};  // 定义
                return 10;
            }
        };
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_CHAPTER_2X_H
