//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:26)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_COSINE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_COSINE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <double& Radian>
    struct NonrecursiveCosine
    {
        static double Cos()
        {
            auto RadianSqrare = Radian * Radian;
            return (1.0 - RadianSqrare / 2.0 * (1.0 - RadianSqrare / 3.0 / 4.0 * (1.0 - RadianSqrare / 5.0 / 6.0 * (1.0 - RadianSqrare / 7.0 / 8.0 * (1.0 - RadianSqrare / 9.0 / 10.0 * (1.0 - RadianSqrare / 11.0 / 12.0 * (1.0 - RadianSqrare / 13.0 / 14.0 * (1.0 - RadianSqrare / 15.0 / 16.0 * (1.0 - RadianSqrare / 17.0 / 18.0 * (1.0 - RadianSqrare / 19.0 / 20.0 * (1.0 - RadianSqrare / 21.0 / 22.0)))))))))));
        }
    };
}

#define NONRECURSIVE_COSINE(r) CoreTools::NonrecursiveCosine<r>::Cos()

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_COSINE_H
