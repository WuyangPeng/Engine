///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/14 23:15)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_1_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_1_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/type_traits/is_same.hpp>
#include <type_traits>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        template <class, class, class>
        struct ReplaceType
        {
            typedef int Type;
        };

        typedef ReplaceType<void*, void, int>::Type T1;  // int*
        typedef ReplaceType<int const* [10], int const, long>::Type T2;  // long* [10]
        typedef ReplaceType<char& (*)(char&), char&, long&>::Type T3;  // long& (*)(long&)

        // 我的解决方案

        template <class C, class X, class Y>
        struct ReplaceType1;

        template <class C, class X, class Y, bool same>
        struct ReplaceTypeImpl1;

        template <class C, class X, class Y>
        struct ReplaceTypeImpl1<C, X, Y, true>
        {
            using Type = Y;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl1<C, X, Y, false>
        {
            using Type = C;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl1<C*, X, Y, false>
        {
            using Type = typename ReplaceType1<C, X, Y>::Type*;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl1<C const, X, Y, false>
        {
            using Type = typename ReplaceType1<C, X, Y>::Type const;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl1<C&, X, Y, false>
        {
            using Type = typename ReplaceType1<C, X, Y>::Type&;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl1<C[], X, Y, false>
        {
            using Type = typename ReplaceType1<C, X, Y>::Type[];
        };

        template <class C, class X, class Y, int N>
        struct ReplaceTypeImpl1<C[N], X, Y, false>
        {
            using Type = typename ReplaceType1<C, X, Y>::Type[N];
        };

        template <typename R, typename P, typename X, typename Y>
        struct ReplaceTypeImpl1<R (*)(P), X, Y, false>
        {
            using ReturnType = typename ReplaceType1<R, X, Y>::Type;
            using ParamType = typename ReplaceType1<P, X, Y>::Type;
            using Type = ReturnType (*)(ParamType);
        };

        template <typename A, typename B, typename C, typename X, typename Y>
        struct ReplaceTypeImpl1<A (*)(B, C), X, Y, false>
        {
            using ReturnType = typename ReplaceType1<A, X, Y>::Type;
            using ParamType1 = typename ReplaceType1<B, X, Y>::Type;
            using ParamType2 = typename ReplaceType1<C, X, Y>::Type;
            using Type = ReturnType (*)(ParamType1, ParamType2);
        };

        template <typename R, typename X, typename Y>
        struct ReplaceTypeImpl1<R (*)(), X, Y, false>
        {
            using ReturnType = typename ReplaceType1<R, X, Y>::Type;
            using Type = ReturnType (*)();
        };

        template <class C, class X, class Y>
        struct ReplaceType1
        {
            static constexpr bool isSame = std::is_same<C, X>::value;
            using Type = typename ReplaceTypeImpl1<C, X, Y, isSame>::Type;
        };

        // Ariel Badichi的解决方案
        template <bool cond, typename X, typename Y>
        struct SelectType;

        template <typename X, typename Y>
        struct SelectType<true, X, Y>
        {
            typedef X Type;
        };

        template <typename X, typename Y>
        struct SelectType<false, X, Y>
        {
            typedef Y Type;
        };

        // 主模板假定基本类型
        template <typename C, typename X, typename Y>
        struct ReplaceType2
        {
            static const bool issame = boost::is_same<C, X>::value;
            typedef typename SelectType<issame, Y, C>::Type Type;
        };

        template <typename C, typename X, typename Y>
        struct ReplaceType2<C*, X*, Y>
        {
            typedef typename ReplaceType2<C, X*, Y>::Type* up;
            static const bool issame = boost::is_same<C, X>::value;
            typedef typename SelectType<issame, Y, up>::Type Type;
        };

        template <typename C, typename X, typename Y>
        struct ReplaceType2<C&, X&, Y>
        {
            typedef typename ReplaceType2<C, X&, Y>::Type& up;
            static const bool issame = boost::is_same<C, X>::value;
            typedef typename SelectType<issame, Y, up>::Type Type;
        };

        template <typename C, typename X, typename Y, std::size_t N>
        struct ReplaceType2<C[N], X[N], Y>
        {
            typedef typename ReplaceType2<C, X[N], Y>::Type up[N];
            static const bool issame = boost::is_same<C, X>::value;
            typedef typename SelectType<issame, Y, up>::Type Type;
        };

        template <typename C, typename X, typename Y>
        struct ReplaceType2<C*, X, Y>
        {
            typedef typename ReplaceType2<C, X, Y>::Type* Type;
        };

        template <typename C, typename X, typename Y>
        struct ReplaceType2<C&, X, Y>
        {
            typedef typename ReplaceType2<C, X, Y>::Type& Type;
        };

        template <typename C, typename X, typename Y, std::size_t N>
        struct ReplaceType2<C[N], X, Y>
        {
            typedef typename ReplaceType2<C, X, Y>::Type Type[N];
        };

        template <typename C, typename X, typename Y>
        struct ReplaceType2<C (*)(), X, Y>
        {
            typedef typename ReplaceType2<C, X, Y>::Type R;
            typedef R (*Type)();
        };

        template <typename C, typename X, typename Y, typename A>
        struct ReplaceType2<C (*)(A), X, Y>
        {
            typedef typename ReplaceType2<C, X, Y>::Type R;
            typedef typename ReplaceType2<A, X, Y>::Type B;
            typedef R (*Type)(B);
        };

        // Andrzej Polanski的解决方案
        template <class C, class X, class Y>
        struct ReplaceType3;

        template <class C, class X, class Y, bool same>
        struct ReplaceTypeImpl3;

        template <class C, class X, class Y>
        struct ReplaceTypeImpl3<C, X, Y, true>
        {
            typedef Y Type;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl3<C, X, Y, false>
        {
            typedef C Type;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl3<C*, X, Y, false>
        {
            typedef typename ReplaceType3<C, X, Y>::Type* Type;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl3<C const, X, Y, false>
        {
            typedef typename ReplaceType3<C, X, Y>::Type const Type;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl3<C&, X, Y, false>
        {
            typedef typename ReplaceType3<C, X, Y>::Type& Type;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl3<C[], X, Y, false>
        {
            typedef typename ReplaceType3<C, X, Y>::Type Type[];
        };

        template <class C, class X, class Y, int N>
        struct ReplaceTypeImpl3<C[N], X, Y, false>
        {
            typedef typename ReplaceType3<C, X, Y>::Type Type[N];
        };

        template <class X, class Y, class A, class B>
        struct ReplaceTypeImpl3<A (*)(B), X, Y, false>
        {
            typedef typename ReplaceType3<A, X, Y>::Type (*Type)(typename ReplaceType3<B, X, Y>::Type);
        };

        template <class X, class Y, class A, class B, class C>
        struct ReplaceTypeImpl3<A (*)(B, C), X, Y, false>
        {
            typedef typename ReplaceType3<A, X, Y>::Type (*Type)(typename ReplaceType3<B, X, Y>::Type, typename ReplaceType3<C, X, Y>::Type);
        };

        template <class C, class X, class Y>
        struct ReplaceType3
        {
            static const bool is_same = boost::is_same<C, X>::value;
            typedef typename ReplaceTypeImpl3<C, X, Y, is_same>::Type Type;
        };

        // Andriy Tylychko的修改
        template <class C, class X, class Y>
        struct ReplaceType4;

        template <class C, class X, class Y, bool same>
        struct ReplaceTypeImpl4;

        template <class C, class X, class Y>
        struct ReplaceTypeImpl4<C, X, Y, true>
        {
            typedef Y Type;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl4<C, X, Y, false>
        {
            typedef C Type;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl4<C*, X, Y, false>
        {
            typedef typename ReplaceType4<C, X, Y>::Type* Type;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl4<C const, X, Y, false>
        {
            typedef typename ReplaceType4<C, X, Y>::Type const Type;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl4<C&, X, Y, false>
        {
            typedef typename ReplaceType4<C, X, Y>::Type& Type;
        };

        template <class C, class X, class Y>
        struct ReplaceTypeImpl4<C[], X, Y, false>
        {
            typedef typename ReplaceType4<C, X, Y>::Type Type[];
        };

        template <class C, class X, class Y, int N>
        struct ReplaceTypeImpl4<C[N], X, Y, false>
        {
            typedef typename ReplaceType4<C, X, Y>::Type Type[N];
        };

        // 我喜欢安Andrzej Polanski的解决方案，但它有几个问题：

        // template <class X, class Y, class R>
        // struct ReplaceTypeImpl4<R (*)(B), X, Y, false>

        // 它只处理函数指针，但指针单独处理

        // template <class C, class X, class Y>
        // struct ReplaceTypeImpl4<C*, X, Y, false>

        // 所以正确的版本看起来像这样：

        template <typename R, typename P, typename X, typename Y>
        struct ReplaceTypeImpl4<R(P), X, Y, false>
        {
            typedef typename ReplaceType4<R, X, Y>::Type ReturnType;
            typedef typename ReplaceType4<P, X, Y>::Type ParamType;
            typedef ReturnType Type(ParamType);
        };

        // 这种做法会自动处理函数的引用。应适用用相同的修正

        //  template <class X, class Y, class A, class B, class C>
        //  struct ReplaceTypeImpl4<A (*)(B, C), X, Y, false>

        template <typename A, typename B, typename C, typename X, typename Y>
        struct ReplaceTypeImpl4<A(B, C), X, Y, false>
        {
            typedef typename ReplaceType4<A, X, Y>::Type ReturnType;
            typedef typename ReplaceType4<B, X, Y>::Type ParamType1;
            typedef typename ReplaceType4<C, X, Y>::Type ParamType2;
            typedef ReturnType Type(ParamType1, ParamType2);
        };

        // 同时，函数无参数没有处理，所以添加：

        template <typename R, typename X, typename Y>
        struct ReplaceTypeImpl4<R(), X, Y, false>
        {
            typedef typename ReplaceType4<R, X, Y>::Type ReturnType;
            typedef ReturnType Type();
        };

        template <class C, class X, class Y>
        struct ReplaceType4
        {
            static const bool is_same = boost::is_same<C, X>::value;
            typedef typename ReplaceTypeImpl4<C, X, Y, is_same>::Type Type;
        };
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_1_H
