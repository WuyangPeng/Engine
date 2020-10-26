//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 15:28)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_RECURSIVE_SINE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_RECURSIVE_SINE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <double& Radian, int Index, int MaxTerms>
    struct SineSeries
    {
        enum
        {
            Continue = Index + 1 != MaxTerms,
            NextIndex = (Index + 1) * Continue,
            NextMaxTerms = MaxTerms * Continue,
        };

        static double Value() noexcept
        {
            return 1 - Radian * Radian / (2.0 * Index + 2.0) / (2.0 * Index + 3.0) * SineSeries<Radian, NextIndex, NextMaxTerms>::Value();
        }
    };

    // Radian��0��2��֮�䡣
    template <double& Radian, int MaxTerms = 10>
    struct RecursiveSine
    {
        static inline double Sin() noexcept
        {
            return Radian * SineSeries<Radian, 0, MaxTerms>::Value();
        }
    };
}

#define RECURSIVE_SINE(r) CoreTools::RecursiveSine<r>::Sin()

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_RECURSIVE_SINE_H
