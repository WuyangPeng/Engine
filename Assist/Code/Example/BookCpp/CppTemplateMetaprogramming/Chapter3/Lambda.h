///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/04 22:31)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_LAMBDA_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_LAMBDA_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/apply.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/multiplies.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/is_same.hpp>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

        template <class UnaryMetaFunctionClass, class Arg>
        struct Apply4 : UnaryMetaFunctionClass::template apply<Arg>
        {
        };

        template <class F, class X>
        struct Twice4 : Apply4<F, typename Apply4<F, X>::type>
        {
        };

        struct AddPointerF4
        {
            template <class T>
            struct apply : boost::add_pointer<T>
            {
            };
        };

        BOOST_STATIC_ASSERT((boost::is_same<Twice4<AddPointerF4, int>::type, int**>::value));

        template <class X>
        struct TwoPointers1 : Twice4<boost::add_pointer<_1>, X>
        {
        };

        template <class T>
        struct AddPointer
        {
            typedef T* type;
        };

        template <class X>
        struct TwoPointers2 : Twice4<typename mpl::lambda<boost::add_pointer<_1>>::type, X>
        {
        };

        BOOST_STATIC_ASSERT((boost::is_same<TwoPointers2<int>::type, int**>::value));

        template <class UnaryMetaFunctionClass, class Arg>
        struct Apply5 : UnaryMetaFunctionClass::template apply<Arg>
        {
        };

        template <class F, class X>
        struct Twice5 : Apply5<typename mpl::lambda<F>::type, typename Apply5<typename mpl::lambda<F>::type, X>::type>
        {
        };

        struct AddPointerF5
        {
            template <class T>
            struct apply : boost::add_pointer<T>
            {
            };
        };

        template <class F, class X>
        struct Twice6 : mpl::apply<F, typename mpl::apply<F, X>::type>
        {
        };

        struct AddPointerF6
        {
            template <class T>
            struct apply : boost::add_pointer<T>
            {
            };
        };

        BOOST_STATIC_ASSERT((boost::is_same<Twice6<AddPointerF6, int>::type, int**>::value));

        BOOST_STATIC_ASSERT((boost::is_same<Twice6<boost::add_pointer<_1>, int>::type, int**>::value));

        enum
        {
            is13 =
                // binary lambda expression applied to 2 additional arguments
                mpl::apply <
                mpl::plus < _1,
            _2 >,
            mpl::int_<6>,
            mpl::int_<7> > ::type::value  // == 13
        };
        BOOST_STATIC_ASSERT(is13 == 13);

        enum
        {
            value1 = mpl::apply < mpl::plus < _1,
            mpl::int_<42> >,
            mpl::int_<3> > ::type::value
        };
        BOOST_STATIC_ASSERT(value1 == 45);

        enum
        {
            value2 = mpl::apply < mpl::multiplies < mpl::plus < _1,
            _2 >,
            mpl::minus < _1,
            _2 >>,
            mpl::int_<5>,
            mpl::int_<3> > ::type::value
        };
        BOOST_STATIC_ASSERT(value2 == 16);
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_TWICE_H
