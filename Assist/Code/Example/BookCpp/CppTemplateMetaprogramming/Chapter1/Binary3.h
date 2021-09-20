///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/31 22:17)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER1_BINARY3_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER1_BINARY3_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        class CPP_TEMPLATE_METAPROGRAMMING_DEFAULT_DECLARE Binary3 final
        {
        public:
            using ClassType = Binary3;

        public:
            Binary3() noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD int Main() const;
        };
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER1_BINARY3_H
