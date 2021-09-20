///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/06 22:23)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_0_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_0_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/int.hpp>
#include <boost/static_assert.hpp>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        // 我的解决方案
        template <unsigned long N>
        struct Exercise3Binary1
        {
            static const auto digit = N % 10;
            static_assert(digit == 1 || digit == 0);

            static const auto value = (Exercise3Binary1<N / 10>::value << 1) + digit;
        };

        template <>
        struct Exercise3Binary1<0>
        {
            static unsigned const value = 0;
        };

        // 另一个解决方案
        template <unsigned long N>
        class Exercise3Binary2 : public boost::mpl::int_<boost::mpl::int_<Exercise3Binary2<N / 10>::value>::value << 1 | N % 10>
        {
            static_assert((N % 10 & ~1) == 0);
        };

        template <>
        class Exercise3Binary2<0> : public boost::mpl::int_<0>
        {
        };
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_0_H
