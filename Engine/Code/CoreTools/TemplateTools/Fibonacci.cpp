///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:43)

#include "CoreTools/CoreToolsExport.h"

#include "Fibonacci.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

uint32_t CoreTools::RecursiveFibonacci(uint32_t integer) noexcept
{
    if (integer <= 1)
    {
        return integer;
    }

    return RecursiveFibonacci(integer - 1) + RecursiveFibonacci(integer - 2);
}

uint32_t CoreTools::NonRecursiveFibonacci(uint32_t integer)
{
    auto previous = -1;
    auto result = 1;
    for (auto i = 0u; i <= integer; ++i)
    {
        const auto sum = result + previous;
        previous = result;
        result = sum;
    }

    return boost::numeric_cast<uint32_t>(result);
}
