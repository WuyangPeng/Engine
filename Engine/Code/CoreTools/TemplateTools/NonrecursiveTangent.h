///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:18)

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
