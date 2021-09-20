///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/09 11:46)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_8_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_8_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/equal.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform.hpp>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

        template <class T, class Dimensions, int Unit = 1>
        struct Quantity4
        {
            static_assert(Unit != 0);

            explicit Quantity4(T x) noexcept
                : m_Value(x)
            {
            }

            T Value() const noexcept
            {
                return m_Value;
            }

            template <class OtherDimensions, int OtherUnit>
            Quantity4(Quantity4<T, OtherDimensions, OtherUnit> const& rhs) noexcept
                : m_Value(rhs.Value() * Unit / OtherUnit)
            {
                static_assert(boost::mpl::equal<Dimensions, OtherDimensions>::type::value);
            }

        private:
            T m_Value;
        };

        template <class T, class D1, class D2, int U1, int U2>
        Quantity4<T, D1, U1> operator+(Quantity4<T, D1, U1> lhs, Quantity4<T, D2, U2> rhs) noexcept
        {
            static_assert(boost::mpl::equal<D1, D2>::type::value);

            return Quantity4<T, D1, U1>(lhs.Value() + rhs.Value() * U1 / U2);
        }

        template <class T, class D1, class D2, int U1, int U2>
        Quantity4<T, D1, U1> operator-(Quantity4<T, D1, U1> lhs, Quantity4<T, D2, U2> rhs) noexcept
        {
            static_assert(boost::mpl::equal<D1, D2>::type::value);

            return Quantity4<T, D1, U1>(lhs.Value() - rhs.Value() * U1 / U2);
        }

        template <typename D1, typename D2>
        struct MultiplyDimensions4 : mpl::transform<D1, D2, mpl::plus<_, _>>
        {
        };

        template <class T, class D1, class D2, int U1, int U2>
        Quantity4<T, typename MultiplyDimensions4<D1, D2>::type, U1> operator*(Quantity4<T, D1, U1> lhs, Quantity4<T, D2, U2> rhs) noexcept
        {
            using DimType = typename MultiplyDimensions4<D1, D2>::type;
            return Quantity4<T, DimType, U1>(lhs.Value() * rhs.Value() / U2);
        }

        template <typename D1, typename D2>
        struct DivideDimensions4 : mpl::transform<D1, D2, mpl::minus<_, _>>
        {
        };

        template <class T, class D1, class D2, int U1, int U2>
        Quantity4<T, typename DivideDimensions4<D1, D2>::type, U1> operator/(Quantity4<T, D1, U1> lhs, Quantity4<T, D2, U2> rhs) noexcept
        {
            using DimType = typename DivideDimensions4<D1, D2>::type;
            return Quantity4<T, DimType, U1>((lhs.Value()) / (rhs.Value() / U2));
        }

    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_8_H
