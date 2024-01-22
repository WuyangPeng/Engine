/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:24)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_RECURSIVE_SINE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_RECURSIVE_SINE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    constexpr double GetSineSeries(double radian, int index, int maxTerms) noexcept
    {
        if (const auto isContinue = (index + 1 != maxTerms); isContinue)
        {
            const auto nextIndex = (index + 1) * isContinue;
            const auto nextMaxTerms = maxTerms * isContinue;

            return 1 - radian * radian / (2.0 * index + 2.0) / (2.0 * index + 3.0) * GetSineSeries(radian, nextIndex, nextMaxTerms);
        }
        else
        {
            return 1.0;
        }
    }

    // Radian在0和2π之间。
    constexpr double RecursiveSine(double radian, int maxTerms = 10) noexcept
    {
        return radian * GetSineSeries(radian, 0, maxTerms);
    }
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_RECURSIVE_SINE_H
