///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/06 22:23)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_2_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_2_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/equal.hpp>
#include <boost/mpl/multiplies.hpp>
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

        using TransformType2 = mpl::transform<VectorCType, mpl::multiplies<_1, _1>>::type;

        using Expected2 = mpl::vector_c<int, 1, 4, 9>;

        static_assert(mpl::equal<Expected2, TransformType2>::type::value);
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE3_2_H
