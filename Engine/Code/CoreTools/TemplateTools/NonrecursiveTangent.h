///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 15:22)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_TANGENT_H
#define CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_TANGENT_H

#include "CoreTools/CoreToolsDll.h"

#include "NonrecursiveCosine.h"
#include "NonrecursiveSine.h"

namespace CoreTools
{
    template <double& Radian>
    struct NonrecursiveTangent
    {
        static constexpr double Tan() noexcept
        {
            return NonrecursiveSine<Radian>::Sin() / NonrecursiveCosine<Radian>::Cos();
        }
    };
}

#define NONRECURSIVE_TANGENT(r) CoreTools::NonrecursiveTangent<r>::Tan()

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_TANGENT_H
