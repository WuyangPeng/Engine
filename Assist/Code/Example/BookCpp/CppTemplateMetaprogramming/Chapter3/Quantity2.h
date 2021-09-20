///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/26 22:36)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_QUANTITY2_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_QUANTITY2_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Quantity.h"

#include <boost/mpl/equal.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/static_assert.hpp>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        template <class T, class Dimensions>
        struct Quantity2
        {
            explicit Quantity2(T x) noexcept
                : m_Value(x)
            {
            }

            T value() const noexcept
            {
                return m_Value;
            }

            template <class OtherDimensions>
            Quantity2(Quantity2<T, OtherDimensions> const& rhs) noexcept
                : m_Value(rhs.value())
            {
                BOOST_STATIC_ASSERT((boost::mpl::equal<Dimensions, OtherDimensions>::type::value));
            }

        private:
            T m_Value;
        };

        template <class T, class D>
        Quantity2<T, D> operator+(Quantity2<T, D> x, Quantity2<T, D> y) noexcept
        {
            return Quantity2<T, D>(x.value() + y.value());
        }

        template <class T, class D>
        Quantity2<T, D> operator-(Quantity2<T, D> x, Quantity2<T, D> y) noexcept
        {
            return Quantity2<T, D>(x.value() - y.value());
        }

        template <class T, class D1, class D2>
        Quantity2<T,
                  typename boost::mpl::transform<D1, D2, PlusF>::type  // new dimensions
                  >
            operator*(Quantity2<T, D1> x, Quantity2<T, D2> y) noexcept
        {
            typedef typename mpl::transform<D1, D2, PlusF>::type dim;
            return Quantity2<T, dim>(x.value() * y.value());
        }

        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

        template <class D1, class D2>
        struct DivideDimensions : mpl::transform<D1, D2, mpl::minus<_1, _2>>  // forwarding again
        {
        };

        template <class T, class D1, class D2>
        Quantity2<T, typename DivideDimensions<D1, D2>::type> operator/(Quantity2<T, D1> x, Quantity2<T, D2> y) noexcept
        {
            return Quantity2<T, typename DivideDimensions<D1, D2>::type>(x.value() / y.value());
        }
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_QUANTITY2_H
