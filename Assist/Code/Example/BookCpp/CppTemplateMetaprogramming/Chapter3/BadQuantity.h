///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/26 22:36)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_BAD_QUANTITY_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_BAD_QUANTITY_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/plus.hpp>
#include <boost/mpl/transform.hpp>

#include "Quantity.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        template <class T, class Dimensions>
        struct BadQuantity
        {
            explicit BadQuantity(T x) noexcept
                : m_Value(x)
            {
            }

            T value() const noexcept
            {
                return m_Value;
            }

            // converting constructor
            template <class OtherDimensions>
            BadQuantity(BadQuantity<T, OtherDimensions> const& rhs) noexcept
                : m_Value(rhs.value())
            {
            }
            // ...

        private:
            T m_Value;
        };

        template <class T, class D>
        BadQuantity<T, D> operator+(BadQuantity<T, D> x, BadQuantity<T, D> y) noexcept
        {
            return BadQuantity<T, D>(x.value() + y.value());
        }

        template <class T, class D>
        BadQuantity<T, D> operator-(BadQuantity<T, D> x, BadQuantity<T, D> y) noexcept
        {
            return BadQuantity<T, D>(x.value() - y.value());
        }

        template <class T, class D1, class D2>
        BadQuantity<T,
                    typename boost::mpl::transform<D1, D2, PlusF>::type  // new dimensions
                    >
            operator*(BadQuantity<T, D1> x, BadQuantity<T, D2> y) noexcept
        {
            typedef typename mpl::transform<D1, D2, PlusF>::type dim;
            return BadQuantity<T, dim>(x.value() * y.value());
        }
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_BAD_QUANTITY_H
