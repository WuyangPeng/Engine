/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:23)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_NON_RECURSIVE_SINE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_NON_RECURSIVE_SINE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    struct NonRecursiveSine
    {
        static constexpr double Sin(const double radian) noexcept
        {
            const auto radianSquare = radian * radian;

            return radian * (1.0 - radianSquare / 2.0 / 3.0 * (1.0 - radianSquare / 4.0 / 5.0 * (1.0 - radianSquare / 6.0 / 7.0 * (1.0 - radianSquare / 8.0 / 9.0 * (1.0 - radianSquare / 10.0 / 11.0 * (1.0 - radianSquare / 12.0 / 13.0 * (1.0 - radianSquare / 14.0 / 15.0 * (1.0 - radianSquare / 16.0 / 17.0 * (1.0 - radianSquare / 18.0 / 19.0 * (1.0 - radianSquare / 20.0 / 21.0))))))))));
        }
    };
}

#define NON_RECURSIVE_SINE(r) CoreTools::NonRecursiveSine::Sin(r)

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_NON_RECURSIVE_SINE_H
