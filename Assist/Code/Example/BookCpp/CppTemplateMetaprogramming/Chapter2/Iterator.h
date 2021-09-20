///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/08 23:04)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_ITERATOR_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_ITERATOR_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        class CPP_TEMPLATE_METAPROGRAMMING_DEFAULT_DECLARE Iterator final
        {
        public:
            using ClassType = Iterator;

        public:
            Iterator() noexcept;

            CLASS_INVARIANT_DECLARE;

            void IterSwap1Main() const;
            void IterSwap2Main() const;
            void IterSwap4Main() const;
            void FooMain() const noexcept;
            void IterSwap5Main() const;
            void IterSwap6Main() const;
            void NonstdMain() const;
        };
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_ITERATOR_H
