///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/07 21:16)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_3_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_3_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/apply.hpp>
#include <type_traits>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

        template <class F, class X>
        struct Twice7 : mpl::apply<F, typename mpl::apply<F, X>::type>
        {
        };

        using PPInt = Twice7<std::add_pointer<_>, int>::type;
        using PPPPInt = Twice7<std::add_pointer<_>, PPInt>::type;
        static_assert(std::is_same<PPPPInt, int****>::value);
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_3_H
