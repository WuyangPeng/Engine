///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/08 23:04)

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
        // �ҵĽ������
        template <typename T>
        struct AddConstRef1
        {
            using ConstType = typename std::add_const<T>::type;
            using Type = typename std::add_lvalue_reference<ConstType>::type;
        };

        // Ariel Badichi�Ľ������
        template <typename T>
        struct AddConstRef2
        {
            typedef typename boost::add_const<T>::type ConstType;
            typedef typename boost::add_reference<ConstType>::type Type;
        };

        // �ҵ�Ԫ����ֻ���е㲻ͬ��
        // �����������õ����������еĹ��ߣ������Ǵ�ͷ��ʼ��

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

        // Zedd�Ľ������

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

        // ���T��int const���������ģ��add_const_ref<int const>::Type�Ľ���ǡ�int const const&�����ǲ��Ǵ��ˣ�

        // û�У�������ȫ��ȷ��
        static_assert(boost::is_same<AddConstRef4<int const>::Type, int const&>::type::value);

        // ������˵������Ȼ�ǡ���ȷ���Ĵ𰸡�

        // JCR�Ľ������

        // ��һ����������ƺ������������⣬��Ϊ��int�������ڲ�Ӧ�ó�Ϊ����ʱ���ó�������������ĿҪ��ģ�����
        // �Ҳ�ȷ���ڶ��ֽ��������ι������ҵĽ���������£�����Ȼ�������ܸ��ӣ����κ��뷨��

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

        // �ұ����������¼��㣬�Ա㣺
        // BOOST_STATIC_ASSERT((boost::is_same<add_const_ref<int&>::Type, int const&>::value));
        // �ܹ�����

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

        // ��֮����ʹ�����public���ʿ��ƣ�����Ϊ�Ҹ��˲�ϲ���Է�POD����ʹ�á��ṹ����
        // �ڵ�һ��ʾ���У���¶��typedef ct�������Ƕ����boost����������
        // ����ΪҲ����ʹ��private������Ƕ�ף�����Ȼ������typedef ct��
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_0_H
