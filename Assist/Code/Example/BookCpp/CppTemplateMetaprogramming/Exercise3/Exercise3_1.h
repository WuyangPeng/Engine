///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/06 22:23)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_1_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_1_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/equal.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/vector_c.hpp>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;
        using VectorCType = mpl::vector_c<int, 1, 2, 3>;

        using TransformType1 = mpl::transform<VectorCType, mpl::plus<_, mpl::int_<1>>>::type;

        using Expected1 = mpl::vector_c<int, 2, 3, 4>;

        static_assert(mpl::equal<Expected1, TransformType1>::type::value);
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_1_H
