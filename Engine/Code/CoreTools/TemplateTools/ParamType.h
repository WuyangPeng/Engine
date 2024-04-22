/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:14)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_PARAM_TYPE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_PARAM_TYPE_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/or.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_scalar.hpp>
#include <boost/type_traits/is_stateless.hpp>

namespace CoreTools
{
    template <class T>
    struct ParamType : boost::mpl::eval_if<boost::mpl::or_<boost::is_scalar<T>,
                                                           boost::is_stateless<T>,
                                                           boost::is_reference<T>>,
                                           boost::mpl::identity<T>,
                                           boost::add_reference<const T>>
    {
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_PARAM_TYPE_H