///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 15:35)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_TRIGONOMETRIC_FUNCTION_H
#define CORE_TOOLS_TEMPLATE_TOOLS_TRIGONOMETRIC_FUNCTION_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    namespace TrigonometricFunction
    {
        // 递归 Sine
        NODISCARD double CORE_TOOLS_DEFAULT_DECLARE SineSeries(double radian, int index, int maxTerms) noexcept;
        NODISCARD double CORE_TOOLS_DEFAULT_DECLARE RecursiveSine(double radian) noexcept;

        // 非递归 Sine
        NODISCARD constexpr double NonRecursiveSine(double radian) noexcept
        {
            const auto radianSqrare = radian * radian;

            return radian * (1.0 - radianSqrare / 2.0 / 3.0 * (1.0 - radianSqrare / 4.0 / 5.0 * (1.0 - radianSqrare / 6.0 / 7.0 * (1.0 - radianSqrare / 8.0 / 9.0 * (1.0 - radianSqrare / 10.0 / 11.0 * (1.0 - radianSqrare / 12.0 / 13.0 * (1.0 - radianSqrare / 14.0 / 15.0 * (1.0 - radianSqrare / 16.0 / 17.0 * (1.0 - radianSqrare / 18.0 / 19.0 * (1.0 - radianSqrare / 20.0 / 21.0))))))))));
        }
    }
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_TRIGONOMETRIC_FUNCTION_H
