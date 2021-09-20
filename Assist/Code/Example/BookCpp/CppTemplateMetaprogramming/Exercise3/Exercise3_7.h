///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/07 21:16)

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

        // （我正在逐行添加注释，说出我认为每一行所做的事情）

        // 这是使用Lambda工具生成的元函数类。
        // 由元函数类持有的元函数接收一个参数。 它将根据该参数生成一个元函数类。
        // （参数必须是lambda表达式）
        typedef mpl::lambda<mpl::lambda<_1>>::type t1;

        // 在这里，我将在元函数类中调用元函数，该类为mpl::lambda<_1>。
        using AddptrF = t1::template apply<boost::add_pointer<_>>::type;

        // 现在，我已经从lambda表达式boost::add_pointer<_>生成了元函数类，现在可以使用它：
        static_assert(std::is_same<mpl::apply<AddptrF, int>::type, int*>::type::value);

        // 在这里，我们使用元函数mpl::apply。 我们传递一个元函数和一个参数。
        // 我认为这是一个错误，因为将_1作为第一个参数会导致无限递归（或更可能是MPL静态断言）
        typedef mpl::apply<_1, mpl::plus<_1, _2>>::type t2;

        // 好的，我试试这个：
        using One = mpl::int_<1>;
        static_assert(mpl::apply<t2, One, One>::type::value);
        // 它似乎可以编译。 但是，这有什么价值呢？ 让我们来看看：
        static_assert(mpl::apply<t2, One, One>::type::value == 2);
        // The value is 2. OK, so now I think mpl::apply's function is
        // the mpl::plus<_1, _2> and the arguments passed in the enclosing
        // mpl::apply are passed to plus. Let's try:
        // 值是2。所以现在我认为mpl::apply的功能是mpl::plus<_1, _2>，
        // 并将在封闭的mpl::apply中传递的参数传递给plus。 我们试试看：
        using Two = mpl::int_<2>;
        static_assert(mpl::apply<t2, One, Two>::type::value == 3);
        // 到现在为止还挺好。 让我们看一下顺序是正确的：
        typedef mpl::apply<_1, mpl::minus<_1, _2>>::type t2_;
        static_assert(mpl::apply<t2_, Two, One>::type::value == 1);

        // 从上一个实验中，我们知道_1使lambda工具评估第二个参数。
        // 在这种情况下，第二个参数是元函数。
        typedef mpl::apply<_1, std::vector<int>>::type t3;

        // 所以我认为结果是std::vector<int>本身，因此t3是std::vector<int>。
        static_assert(std::is_same<t3, std::vector<int>>::type::value);

        // 从现在起，我们的std::vector传递给了lambda工具，我相信t4是一个元函数类，其结果是std::vector<argument>。
        typedef mpl::apply<_1, std::vector<_1>>::type t4;

        // 我们试试看：
        typedef mpl::apply<t4, int>::type t4result;
        static_assert(std::is_same<std::vector<int>, t4result>::type::value);

        // Correct again.
        // First we swap _1 for std::vector<int>, so we have a lambda facility
        // specialized with the std::vector<int>. So I suspect t5 is actually the
        // lambda facility, and we need to get its resulting ::type.
        // 首先，我们将_1交换为std::vector<int>，因此我们拥有专用于std::vector<int>的lambda工具。
        // 所以我怀疑t5实际上是lambda工具，我们需要获取其结果::type。
        typedef mpl::apply<mpl::lambda<_1>, std::vector<int>>::type t5;

        // 我认为结果类型是 std::vector<int>，因为它不是一个元函数。
        // typedef t5::type t5result;
        // static_assert(std::is_same<std::vector<int>, t5result>::type::value);
        // 嗯。不，看来t5是std::vector<int>。
        static_assert(std::is_same<std::vector<int>, t5>::type::value);

        // 嗯，所以apply将lambda工具应用于_1，这将创建特化，然后Apply将lambda本身应用，从而生成std::vector<>。

        // 好的。 我们在第一个参数中应用_1，因此我们使用mpl::lambda<std::vector<_1> > ..然后应用它。
        // 结果是一个元函数类，我们需要应用它来获取std::vector。
        typedef mpl::apply<mpl::lambda<_1>, std::vector<_1>>::type t6;
        typedef mpl::apply<t6, int>::type t6result;
        static_assert(std::is_same<t6result, std::vector<int>>::type::value);

        // 嗯，我认为这是通常的情况。 我们对第一个参数应用_1：mpl::apply<mpl::lambda<mpl::plus<_1, _2> > >。
        // 结果是一个用于plus的元函数类。
        typedef mpl::apply<mpl::lambda<_1>, mpl::plus<_1, _2>>::type t7;
        // 我们使用带有两个参数的元函数类：
        static_assert(mpl::apply<t7, One, Two>::type::value == 3);

        // 好的，比较棘手。 因此，首先我们评估第一个参数，结果为mpl::apply<mpl::lambda<mpl::plus<_1, _2> > >。
        // 这会将lambda评估应用于plus。
        typedef mpl::apply<_1, mpl::lambda<mpl::plus<_1, _2>>>::type t8;
        static_assert(mpl::apply<t8, One, Two>::type::value == 3);
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_7_H
