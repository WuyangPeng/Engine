///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/08 23:04)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_CHAPTER_2X_INSTANTIATE_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_CHAPTER_2X_INSTANTIATE_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        class CPP_TEMPLATE_METAPROGRAMMING_DEFAULT_DECLARE Chapter2XInstantiate final
        {
        public:
            using ClassType = Chapter2XInstantiate;

        public:
            Chapter2XInstantiate() noexcept;

            CLASS_INVARIANT_DECLARE;

            void Main() const noexcept;
        };
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_CHAPTER_2X_INSTANTIATE_H
