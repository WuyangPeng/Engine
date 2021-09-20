///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/07 21:16)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_5_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_5_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/placeholders.hpp>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

        template <class T, class Dimensions>
        struct Quantity3
        {
            explicit Quantity3(T x) noexcept
                : m_Value(x)
            {
            }

            T Value() const noexcept
            {
                return m_Value;
            }

            template <class OtherDimensions>
            Quantity3(Quantity3<T, OtherDimensions> const& rhs) noexcept
                : m_Value(rhs.Value())
            {
                static_assert(boost::mpl::equal<Dimensions, OtherDimensions>::type::value);
            }

        private:
            T m_Value;
        };

        template <class T, class D1, class D2>
        Quantity3<T, D1> operator+(Quantity3<T, D1> lhs, Quantity3<T, D2> rhs) noexcept
        {
            static_assert(boost::mpl::equal<D1, D2>::type::value);

            return Quantity3<T, D1>(lhs.Value() + rhs.Value());
        }

        template <class T, class D1, class D2>
        Quantity3<T, D1> operator-(Quantity3<T, D1> lhs, Quantity3<T, D2> rhs) noexcept
        {
            static_assert(boost::mpl::equal<D1, D2>::type::value);

            return Quantity3<T, D1>(lhs.Value() - rhs.Value());
        }

        template <typename D1, typename D2>
        struct MultiplyDimensions3 : mpl::transform<D1, D2, mpl::plus<_, _>>
        {
        };

        template <class T, class D1, class D2>
        Quantity3<T, typename MultiplyDimensions3<D1, D2>::type> operator*(Quantity3<T, D1> lhs, Quantity3<T, D2> rhs) noexcept
        {
            using DimType = typename MultiplyDimensions3<D1, D2>::type;
            return Quantity3<T, DimType>(lhs.Value() * rhs.Value());
        }

        template <typename D1, typename D2>
        struct DivideDimensions3 : mpl::transform<D1, D2, mpl::minus<_, _>>
        {
        };

        template <class T, class D1, class D2>
        Quantity3<T, typename DivideDimensions3<D1, D2>::type> operator/(Quantity3<T, D1> lhs, Quantity3<T, D2> rhs) noexcept
        {
            using DimType = typename DivideDimensions3<D1, D2>::type;
            return Quantity3<T, DimType>(lhs.Value() / rhs.Value());
        }

        template <typename S, typename T, typename D>
        S& operator<<(S& out, Quantity3<T, D> quantity)
        {
            return out << quantity.Value();
        }
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_5_H
