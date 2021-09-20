///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/08 23:04)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_APPLY_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_APPLY_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        class CPP_TEMPLATE_METAPROGRAMMING_DEFAULT_DECLARE Apply final
        {
        public:
            using ClassType = Apply;

        public:
            Apply() noexcept;

            CLASS_INVARIANT_DECLARE;

            void Main() const;
        };
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_APPLY_H
