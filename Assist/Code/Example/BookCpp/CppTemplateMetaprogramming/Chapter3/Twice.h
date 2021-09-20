///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/27 23:18)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_TWICE_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_TWICE_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/assert.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/is_same.hpp>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        template <class F, class X>
        struct Twice1
        {
            typedef typename F::template apply<X>::type once;  // f(x)
            typedef typename F::template apply<once>::type type;  // f(f(x))
        };

        struct AddPointerF1
        {
            template <class T>
            struct apply : boost::add_pointer<T>
            {
            };
        };
        BOOST_STATIC_ASSERT((boost::is_same<Twice1<AddPointerF1, int>::type, int**>::value));

        template <class F, class X>
        struct Twice2 : F::template apply<typename F::template apply<X>::type>
        {
        };

        struct AddPointerF2
        {
            template <class T>
            struct apply : boost::add_pointer<T>
            {
            };
        };
        BOOST_STATIC_ASSERT((boost::is_same<Twice2<AddPointerF2, int>::type, int**>::value));

        template <class UnaryMetaFunctionClass, class Arg>
        struct Apply1 : UnaryMetaFunctionClass::template apply<Arg>
        {
        };

        template <class F, class X>
        struct Twice3 : Apply1<F, typename Apply1<F, X>::type>
        {
        };

        struct AddPointerF3
        {
            template <class T>
            struct apply : boost::add_pointer<T>
            {
            };
        };

        BOOST_STATIC_ASSERT((boost::is_same<Twice3<AddPointerF3, int>::type, int**>::value));
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_TWICE_H
