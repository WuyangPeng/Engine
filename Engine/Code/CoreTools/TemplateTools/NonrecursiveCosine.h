///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:47)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_NON_RECURSIVE_COSINE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_NON_RECURSIVE_COSINE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    struct NonRecursiveCosine
    {
        static constexpr double Cos(const double radian) noexcept
        {
            const auto radianSquare = radian * radian;

            return (1.0 - radianSquare / 2.0 * (1.0 - radianSquare / 3.0 / 4.0 * (1.0 - radianSquare / 5.0 / 6.0 * (1.0 - radianSquare / 7.0 / 8.0 * (1.0 - radianSquare / 9.0 / 10.0 * (1.0 - radianSquare / 11.0 / 12.0 * (1.0 - radianSquare / 13.0 / 14.0 * (1.0 - radianSquare / 15.0 / 16.0 * (1.0 - radianSquare / 17.0 / 18.0 * (1.0 - radianSquare / 19.0 / 20.0 * (1.0 - radianSquare / 21.0 / 22.0)))))))))));
        }
    };
}

#define NON_RECURSIVE_COSINE(r) CoreTools::NonRecursiveCosine::Cos(r)

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_NON_RECURSIVE_COSINE_H
