///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/07 21:16)

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

        // 我试图使用占位符表达式解决此问题，但遇到了意外（至少对我而言）。 正如我希望的那样，以下代码有效：
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

        // 但是，当我尝试使用boost::mpl::apply而不是Apply2时，出现了一些漂亮的错误。 即使我只尝试使用mpl::apply一次，如
        // static_assert(std::is_same<mpl::apply<mpl::lambda<mpl::apply<_1, _2>>, AddPtrF, int>::type, int*>::value);
        // 问题是您没有为嵌套的“mpl::apply<...>”使用“::type”，因此，我们获得：
        // static_assert(std::is_same<mpl::apply<mpl::lambda<mpl::apply<_1, _2>::type>, AddPtrF, int>::type, int*>::value);
        // 坏消息是它可以编译但不能按预期工作，结果是“int”，而不是“int*”。
        // 我认为原因是占位符替换时间，但无法解释原因。 确实，使用手工apply1效果很好，因为可以不使用“::type”。 尝试
        // static_assert(std::is_same<mpl::apply<mpl::lambda<Apply2<_1, _2>::type>, AddPtrF, int>::type, int*>::value);
        // 出于与上一个示例相同的原因，它不起作用。 那么apply1和mpl::apply之间有什么区别？为什么如果它们是如此相似，
        // apply1可以不带“::type”而mpl::apply不能使用？ 因为mpl::apply是部分模板特化。
        // 结果，以下版本：
        // using Twice = mpl::lambda<mpl::apply<mpl::_1, mpl::apply<_1, _2>::type>::type>::type;
        // static_assert(std::is_same<mpl::apply<Twice, std::add_pointer<_>, int>::type, int**>::value);
        // 我收到的另一个可行的解决方案如下所示：
        static_assert(std::is_same<mpl::apply<std::add_pointer<_>, mpl::apply<std::add_pointer<_>, int>::type>::type, int**>::value);
        // 但不允许分隔“std::add_pointer<_>”。
    }

}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_6_H
