//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 15:17)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_FIBONACCI_H
#define CORE_TOOLS_TEMPLATE_TOOLS_FIBONACCI_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <unsigned N>
    struct Fibonacci
    {
        enum
        {
            Value = Fibonacci<N - 1>::Value + Fibonacci<N - 2>::Value
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

    [[nodiscard]] uint32_t CORE_TOOLS_DEFAULT_DECLARE RecursiveFibonacci(uint32_t integer) noexcept;
    [[nodiscard]] uint32_t CORE_TOOLS_DEFAULT_DECLARE NonRecursiveFibonacci(uint32_t integer);
}

#define FIBONACCI(n) CoreTools::Fibonacci<n>::Value

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_FIBONACCI_H
