///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/26 22:36)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_QUANTITY_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_QUANTITY_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/equal.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/static_assert.hpp>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        namespace mpl = boost::mpl;

        template <class T, class Dimensions>
        struct Quantity
        {
            explicit Quantity(T x) noexcept
                : m_Value(x)
            {
            }

            T value() const noexcept
            {
                return m_Value;
            }

            template <class OtherDimensions>
            Quantity(Quantity<T, OtherDimensions> const& rhs) noexcept
                : m_Value(rhs.value())
            {
                BOOST_STATIC_ASSERT((boost::mpl::equal<Dimensions, OtherDimensions>::type::value));
            }

        private:
            T m_Value;
        };

        template <class T, class D>
        Quantity<T, D> operator+(Quantity<T, D> x, Quantity<T, D> y) noexcept
        {
            return Quantity<T, D>(x.value() + y.value());
        }

        template <class T, class D>
        Quantity<T, D> operator-(Quantity<T, D> x, Quantity<T, D> y) noexcept
        {
            return Quantity<T, D>(x.value() - y.value());
        }

        struct PlusF
        {
            template <class T1, class T2>
            struct apply
            {
                typedef typename boost::mpl::plus<T1, T2>::type type;
            };
        };

        template <class T, class D1, class D2>
        Quantity<T,
                 typename boost::mpl::transform<D1, D2, PlusF>::type  // new dimensions
                 >
            operator*(Quantity<T, D1> x, Quantity<T, D2> y) noexcept
        {
            typedef typename mpl::transform<D1, D2, PlusF>::type dim;
            return Quantity<T, dim>(x.value() * y.value());
        }

        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

        template <class T, class D1, class D2>
        Quantity<T, typename mpl::transform<D1, D2, mpl::minus<_1, _2>>::type> operator/(Quantity<T, D1> x, Quantity<T, D2> y) noexcept
        {
            typedef typename mpl::transform<D1, D2, mpl::minus<_1, _2>>::type dim;

            return Quantity<T, dim>(x.value() / y.value());
        }
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_QUANTITY_H
