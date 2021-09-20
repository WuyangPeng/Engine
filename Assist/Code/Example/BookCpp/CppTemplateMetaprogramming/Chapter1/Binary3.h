///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/31 22:17)

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
