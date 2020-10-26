//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:27)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_SINE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_SINE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <double& Radian>
    struct NonrecursiveSine
    {
        static double Sin()
        {
            auto RadianSqrare = Radian * Radian;
            return Radian * (1.0 - RadianSqrare / 2.0 / 3.0 * (1.0 - RadianSqrare / 4.0 / 5.0 * (1.0 - RadianSqrare / 6.0 / 7.0 * (1.0 - RadianSqrare / 8.0 / 9.0 * (1.0 - RadianSqrare / 10.0 / 11.0 * (1.0 - RadianSqrare / 12.0 / 13.0 * (1.0 - RadianSqrare / 14.0 / 15.0 * (1.0 - RadianSqrare / 16.0 / 17.0 * (1.0 - RadianSqrare / 18.0 / 19.0 * (1.0 - RadianSqrare / 20.0 / 21.0))))))))));
        }
    };
}

#define NONRECURSIVE_SINE(r) CoreTools::NonrecursiveSine<r>::Sin()

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_SINE_H
