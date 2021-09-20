///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/07 21:16)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_4_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_4_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/apply.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/is_same.hpp>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

        template <class F, class X>
        struct Twice8 : mpl::apply<F, typename mpl::apply<F, X>::type>
        {
        };

        using AddPointerLambda = mpl::lambda<boost::add_pointer<_>>::type;
        using PType = Twice8<Twice8<AddPointerLambda, _>, int>::type;
        static_assert(boost::is_same<int****, PType>::value);

    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_4_H
