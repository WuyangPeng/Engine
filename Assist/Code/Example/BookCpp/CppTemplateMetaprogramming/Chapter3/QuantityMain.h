///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/26 22:38)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_QUANTITY_MAIN_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_QUANTITY_MAIN_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "BadQuantity.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        class CPP_TEMPLATE_METAPROGRAMMING_DEFAULT_DECLARE QuantityMain final
        {
        public:
            using ClassType = QuantityMain;

        public:
            QuantityMain() noexcept;

            CLASS_INVARIANT_DECLARE;

            void Main() const noexcept;
            void Test1() const noexcept;
            void FF() const;
            void Bogus(Quantity<float, Mass> m, Quantity<float, Acceleration> a) const noexcept;
            void BadQuantityBogus2(BadQuantity<float, Mass> m, BadQuantity<float, Acceleration> a) const noexcept;
            void BadQuantityTest1() const noexcept;
            void Bogus2(Quantity<float, Mass> m, Quantity<float, Acceleration> a) const noexcept;
            void Main3();
            void Main2();
        };
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_QUANTITY_MAIN_H
