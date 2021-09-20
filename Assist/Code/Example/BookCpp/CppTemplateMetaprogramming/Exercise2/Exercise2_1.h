///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/14 23:15)

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

        // �ҵĽ������

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

        // Ariel Badichi�Ľ������
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

        // ��ģ��ٶ���������
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

        // Andrzej Polanski�Ľ������
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

        // Andriy Tylychko���޸�
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

        // ��ϲ����Andrzej Polanski�Ľ�������������м������⣺

        // template <class X, class Y, class R>
        // struct ReplaceTypeImpl4<R (*)(B), X, Y, false>

        // ��ֻ������ָ�룬��ָ�뵥������

        // template <class C, class X, class Y>
        // struct ReplaceTypeImpl4<C*, X, Y, false>

        // ������ȷ�İ汾��������������

        template <typename R, typename P, typename X, typename Y>
        struct ReplaceTypeImpl4<R(P), X, Y, false>
        {
            typedef typename ReplaceType4<R, X, Y>::Type ReturnType;
            typedef typename ReplaceType4<P, X, Y>::Type ParamType;
            typedef ReturnType Type(ParamType);
        };

        // �����������Զ������������á�Ӧ��������ͬ������

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

        // ͬʱ�������޲���û�д���������ӣ�

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
