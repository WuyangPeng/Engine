///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/08 23:04)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_0_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_0_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/static_assert.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <type_traits>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        // 我的解决方案
        template <typename T>
        struct AddConstRef1
        {
            using ConstType = typename std::add_const<T>::type;
            using Type = typename std::add_lvalue_reference<ConstType>::type;
        };

        // Ariel Badichi的解决方案
        template <typename T>
        struct AddConstRef2
        {
            typedef typename boost::add_const<T>::type ConstType;
            typedef typename boost::add_reference<ConstType>::type Type;
        };

        // 我的元函数只是有点不同。
        // 上述方法更好地利用了现有的工具，下面是从头开始。

        template <typename T, bool B = std::is_reference<T>::value>
        struct AddConstRef3;

        template <typename T>
        struct AddConstRef3<T, true>
        {
            typedef T Type;
        };
        template <typename T>
        struct AddConstRef3<T, false>
        {
            typedef T const& Type;
        };

        // Zedd的解决方案

        template <typename T>
        struct AddConstRef4
        {
            typedef T const& Type;
        };

        template <typename T>
        struct AddConstRef4<T&>
        {
            typedef T& Type;
        };

        // 如果T是int const？按照这个模板add_const_ref<int const>::Type的结果是“int const const&”。是不是错了？

        // 没有，这是完全正确：
        static_assert(boost::is_same<AddConstRef4<int const>::Type, int const&>::type::value);

        // 对我来说，这显然是“正确”的答案。

        // JCR的解决方案

        // 第一个解决方案似乎并不令人满意，因为对int的引用在不应该成为常量时会变得常量。（这是题目要求的！！）
        // 我不确定第二种解决方案如何工作。我的解决方案如下，我仍然觉得它很复杂，有任何想法吗？

        template <bool b>
        struct AddConstRef5Impl
        {
        };

        template <>
        struct AddConstRef5Impl<true>
        {
            template <typename T>
            struct TypeImpl
            {
                typedef T Type;
            };
        };

        template <>
        struct AddConstRef5Impl<false>
        {
            template <typename T>
            struct TypeImpl
            {
                typedef T const& Type;
            };
        };

        template <typename T>
        struct AddConstRef5
        {
            static const bool test = boost::is_reference<T>::type::value;
            typedef typename AddConstRef5Impl<test>::template TypeImpl<T>::Type Type;
        };

        // 我必须做到以下几点，以便：
        // BOOST_STATIC_ASSERT((boost::is_same<add_const_ref<int&>::Type, int const&>::value));
        // 能工作。

        template <class T>
        class AddConstRef6
        {
        public:
            typedef typename boost::add_reference<
                typename boost::add_const<
                    typename boost::remove_reference<
                        T>::type>::type>::type Type;
        };

        BOOST_STATIC_ASSERT((boost::is_same<AddConstRef6<int&>::Type, int const&>::value));

        // 我之所以使用类和public访问控制，是因为我个人不喜欢对非POD类型使用“结构”。
        // 在第一个示例中，暴露了typedef ct，因此我嵌套了boost类型特征。
        // 我认为也可以使用private来避免嵌套，而仍然不公开typedef ct。
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_0_H
