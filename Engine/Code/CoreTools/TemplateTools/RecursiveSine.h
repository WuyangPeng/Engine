///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 15:24)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_RECURSIVE_SINE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_RECURSIVE_SINE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    constexpr double GetSineSeries(double radian, int index, int maxTerms) noexcept
    {
        const auto isContinue = (index + 1 != maxTerms);
        if (isContinue)
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

    // Radian��0��2��֮�䡣

    constexpr double RecursiveSine(double radian, int maxTerms = 10) noexcept
    {
        return radian * GetSineSeries(radian, 0, maxTerms);
    }
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_RECURSIVE_SINE_H
