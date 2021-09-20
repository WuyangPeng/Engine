///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/27 23:18)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_TRANSFORM_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_TRANSFORM_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Quantity.h"

#include <boost/mpl/int.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/static_assert.hpp>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        template <class InputIterator1, class InputIterator2, class OutputIterator, class BinaryOperation>
        void Transform(MAYBE_UNUSED InputIterator1 start1,
                       MAYBE_UNUSED InputIterator2 finish1,
                       MAYBE_UNUSED InputIterator2 start2,
                       MAYBE_UNUSED OutputIterator result,
                       MAYBE_UNUSED BinaryOperation func)
        {
        }

        namespace mpl = boost::mpl;

        BOOST_STATIC_ASSERT((mpl::plus<mpl::int_<2>, mpl::int_<3>>::type::value == 5));

        template <class T, class D1, class D2>
        Quantity<T, typename mpl::transform<D1, D2, mpl::plus<D1, D2>>::type> operator*(Quantity<T, D1> x, Quantity<T, D2> y);

        typedef mpl::vector_c<int, 1, 1, -2, 0, 0, 0, 0> xxxx;

        struct minus_f
        {
            template <class T1, class T2>
            struct apply : mpl::minus<T1, T2>
            {
            };
        };

        using namespace mpl::placeholders;

        namespace mpl = boost::mpl;

        template <class D1, class D2>
        typename mpl::transform<D1, D2, mpl::minus<_1, _2>>::type fff(D1, D2);

    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_TRANSFORM_H
