///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/07 21:16)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_6_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_6_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/apply.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/plus.hpp>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

        struct TwiceLambda
        {
            template <typename F, typename X>
            struct apply : mpl::apply<F, typename mpl::apply<F, X>::type>
            {
            };
        };

        using FiveType = mpl::int_<5>::type;
        using UnaryPlus = mpl::plus<_1, _1>;

        static_assert(mpl::apply<TwiceLambda, UnaryPlus, FiveType>::type::value == 20);

        // ����ͼʹ��ռλ�����ʽ��������⣬�����������⣨���ٶ��Ҷ��ԣ��� ������ϣ�������������´�����Ч��
        struct AddPtrF
        {
            template <class T>
            struct apply : std::add_pointer<T>
            {
            };
        };

        template <class F, class X>
        struct Apply2 : F::template apply<X>
        {
        };

        static_assert(std::is_same<mpl::apply<mpl::lambda<Apply2<_1, Apply2<_1, _2>>>, AddPtrF, int>::type, int**>::value);

        // ���ǣ����ҳ���ʹ��boost::mpl::apply������Apply2ʱ��������һЩƯ���Ĵ��� ��ʹ��ֻ����ʹ��mpl::applyһ�Σ���
        // static_assert(std::is_same<mpl::apply<mpl::lambda<mpl::apply<_1, _2>>, AddPtrF, int>::type, int*>::value);
        // ��������û��ΪǶ�׵ġ�mpl::apply<...>��ʹ�á�::type������ˣ����ǻ�ã�
        // static_assert(std::is_same<mpl::apply<mpl::lambda<mpl::apply<_1, _2>::type>, AddPtrF, int>::type, int*>::value);
        // ����Ϣ�������Ա��뵫���ܰ�Ԥ�ڹ���������ǡ�int���������ǡ�int*����
        // ����Ϊԭ����ռλ���滻ʱ�䣬���޷�����ԭ�� ȷʵ��ʹ���ֹ�apply1Ч���ܺã���Ϊ���Բ�ʹ�á�::type���� ����
        // static_assert(std::is_same<mpl::apply<mpl::lambda<Apply2<_1, _2>::type>, AddPtrF, int>::type, int*>::value);
        // ��������һ��ʾ����ͬ��ԭ�����������á� ��ôapply1��mpl::apply֮����ʲô����Ϊʲô���������������ƣ�
        // apply1���Բ�����::type����mpl::apply����ʹ�ã� ��Ϊmpl::apply�ǲ���ģ���ػ���
        // ��������°汾��
        // using Twice = mpl::lambda<mpl::apply<mpl::_1, mpl::apply<_1, _2>::type>::type>::type;
        // static_assert(std::is_same<mpl::apply<Twice, std::add_pointer<_>, int>::type, int**>::value);
        // ���յ�����һ�����еĽ������������ʾ��
        static_assert(std::is_same<mpl::apply<std::add_pointer<_>, mpl::apply<std::add_pointer<_>, int>::type>::type, int**>::value);
        // ��������ָ���std::add_pointer<_>����
    }

}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_6_H
