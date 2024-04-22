/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:16)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_FIBONACCI_H
#define CORE_TOOLS_TEMPLATE_TOOLS_FIBONACCI_H

#include "CoreTools/CoreToolsDll.h"

    namespace CoreTools
{
    template <uint32_t N>
    struct Fibonacci
    {
        enum
        {
            Value = static_cast<uint32_t>(Fibonacci<N - 1>::Value) + static_cast<uint32_t>(Fibonacci<N - 2>::Value)
        };
    };

    template <>
    struct Fibonacci<0>
    {
        enum
        {
            Value = 0
        };
    };

    template <>
    struct Fibonacci<1>
    {
        enum
        {
            Value = 1
        };
    };

    NODISCARD uint32_t CORE_TOOLS_DEFAULT_DECLARE RecursiveFibonacci(uint32_t integer) noexcept;
    NODISCARD uint32_t CORE_TOOLS_DEFAULT_DECLARE NonRecursiveFibonacci(uint32_t integer);
}

#define FIBONACCI(n) CoreTools::Fibonacci<n>::Value

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_FIBONACCI_H
