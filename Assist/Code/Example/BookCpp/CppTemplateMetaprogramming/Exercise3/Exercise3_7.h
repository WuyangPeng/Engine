///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/07 21:16)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_7_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_7_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/apply.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/plus.hpp>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

        // ���������������ע�ͣ�˵������Ϊÿһ�����������飩

        // ����ʹ��Lambda�������ɵ�Ԫ�����ࡣ
        // ��Ԫ��������е�Ԫ��������һ�������� �������ݸò�������һ��Ԫ�����ࡣ
        // ������������lambda���ʽ��
        typedef mpl::lambda<mpl::lambda<_1>>::type t1;

        // ������ҽ���Ԫ�������е���Ԫ����������Ϊmpl::lambda<_1>��
        using AddptrF = t1::template apply<boost::add_pointer<_>>::type;

        // ���ڣ����Ѿ���lambda���ʽboost::add_pointer<_>������Ԫ�����࣬���ڿ���ʹ������
        static_assert(std::is_same<mpl::apply<AddptrF, int>::type, int*>::type::value);

        // ���������ʹ��Ԫ����mpl::apply�� ���Ǵ���һ��Ԫ������һ��������
        // ����Ϊ����һ��������Ϊ��_1��Ϊ��һ�������ᵼ�����޵ݹ飨���������MPL��̬���ԣ�
        typedef mpl::apply<_1, mpl::plus<_1, _2>>::type t2;

        // �õģ������������
        using One = mpl::int_<1>;
        static_assert(mpl::apply<t2, One, One>::type::value);
        // ���ƺ����Ա��롣 ���ǣ�����ʲô��ֵ�أ� ��������������
        static_assert(mpl::apply<t2, One, One>::type::value == 2);
        // The value is 2. OK, so now I think mpl::apply's function is
        // the mpl::plus<_1, _2> and the arguments passed in the enclosing
        // mpl::apply are passed to plus. Let's try:
        // ֵ��2��������������Ϊmpl::apply�Ĺ�����mpl::plus<_1, _2>��
        // �����ڷ�յ�mpl::apply�д��ݵĲ������ݸ�plus�� �������Կ���
        using Two = mpl::int_<2>;
        static_assert(mpl::apply<t2, One, Two>::type::value == 3);
        // ������Ϊֹ��ͦ�á� �����ǿ�һ��˳������ȷ�ģ�
        typedef mpl::apply<_1, mpl::minus<_1, _2>>::type t2_;
        static_assert(mpl::apply<t2_, Two, One>::type::value == 1);

        // ����һ��ʵ���У�����֪��_1ʹlambda���������ڶ���������
        // ����������£��ڶ���������Ԫ������
        typedef mpl::apply<_1, std::vector<int>>::type t3;

        // ��������Ϊ�����std::vector<int>�������t3��std::vector<int>��
        static_assert(std::is_same<t3, std::vector<int>>::type::value);

        // �����������ǵ�std::vector���ݸ���lambda���ߣ�������t4��һ��Ԫ�����࣬������std::vector<argument>��
        typedef mpl::apply<_1, std::vector<_1>>::type t4;

        // �������Կ���
        typedef mpl::apply<t4, int>::type t4result;
        static_assert(std::is_same<std::vector<int>, t4result>::type::value);

        // Correct again.
        // First we swap _1 for std::vector<int>, so we have a lambda facility
        // specialized with the std::vector<int>. So I suspect t5 is actually the
        // lambda facility, and we need to get its resulting ::type.
        // ���ȣ����ǽ�_1����Ϊstd::vector<int>���������ӵ��ר����std::vector<int>��lambda���ߡ�
        // �����һ���t5ʵ������lambda���ߣ�������Ҫ��ȡ����::type��
        typedef mpl::apply<mpl::lambda<_1>, std::vector<int>>::type t5;

        // ����Ϊ��������� std::vector<int>����Ϊ������һ��Ԫ������
        // typedef t5::type t5result;
        // static_assert(std::is_same<std::vector<int>, t5result>::type::value);
        // �š���������t5��std::vector<int>��
        static_assert(std::is_same<std::vector<int>, t5>::type::value);

        // �ţ�����apply��lambda����Ӧ����_1���⽫�����ػ���Ȼ��Apply��lambda����Ӧ�ã��Ӷ�����std::vector<>��

        // �õġ� �����ڵ�һ��������Ӧ��_1���������ʹ��mpl::lambda<std::vector<_1> > ..Ȼ��Ӧ������
        // �����һ��Ԫ�����࣬������ҪӦ��������ȡstd::vector��
        typedef mpl::apply<mpl::lambda<_1>, std::vector<_1>>::type t6;
        typedef mpl::apply<t6, int>::type t6result;
        static_assert(std::is_same<t6result, std::vector<int>>::type::value);

        // �ţ�����Ϊ����ͨ��������� ���ǶԵ�һ������Ӧ��_1��mpl::apply<mpl::lambda<mpl::plus<_1, _2> > >��
        // �����һ������plus��Ԫ�����ࡣ
        typedef mpl::apply<mpl::lambda<_1>, mpl::plus<_1, _2>>::type t7;
        // ����ʹ�ô�������������Ԫ�����ࣺ
        static_assert(mpl::apply<t7, One, Two>::type::value == 3);

        // �õģ��Ƚϼ��֡� ��ˣ���������������һ�����������Ϊmpl::apply<mpl::lambda<mpl::plus<_1, _2> > >��
        // ��Ὣlambda����Ӧ����plus��
        typedef mpl::apply<_1, mpl::lambda<mpl::plus<_1, _2>>>::type t8;
        static_assert(mpl::apply<t8, One, Two>::type::value == 3);
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_7_H
