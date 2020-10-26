//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:27)

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
        static double Tan()
        {
            return NonrecursiveSine<Radian>::Sin() / NonrecursiveCosine<Radian>::Cos();
        }
    };
}

#define NONRECURSIVE_TANGENT(r) CoreTools::NonrecursiveTangent<r>::Tan()

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_TANGENT_H
