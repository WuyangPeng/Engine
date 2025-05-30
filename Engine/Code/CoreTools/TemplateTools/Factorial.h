/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:16)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_FACTORIAL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_FACTORIAL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <unsigned N>
    struct Factorial
    {
        enum
        {
            Value = N * Factorial<N - 1>::Value
        };
    };

    template <>
    struct Factorial<0>
    {
        enum
        {
            Value = 1
        };
    };

    template <>
    struct Factorial<1>
    {
        enum
        {
            Value = 1
        };
    };

    NODISCARD uint32_t CORE_TOOLS_DEFAULT_DECLARE RecursiveFactorial(uint32_t integer) noexcept;

    NODISCARD constexpr uint32_t NonRecursiveFactorial(uint32_t integer) noexcept
    {
        auto result = 1u;

        for (auto index = 1u; index <= integer; ++index)
        {
            result *= index;
        }

        return result;
    }
}

#define FACTORIAL(n) CoreTools::Factorial<n>::Value

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_FACTORIAL_H
