/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:14)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_NON_RECURSIVE_TANGENT_H
#define CORE_TOOLS_TEMPLATE_TOOLS_NON_RECURSIVE_TANGENT_H

#include "CoreTools/CoreToolsDll.h"

#include "NonRecursiveCosine.h"
#include "NonRecursiveSine.h"

namespace CoreTools
{
    struct NonRecursiveTangent
    {
        static constexpr double Tan(const double radian) noexcept
        {
            return NonRecursiveSine::Sin(radian) / NonRecursiveCosine::Cos(radian);
        }
    };
}

#define NON_RECURSIVE_TANGENT(r) CoreTools::NonRecursiveTangent::Tan(r)

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_NON_RECURSIVE_TANGENT_H
