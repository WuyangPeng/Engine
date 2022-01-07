///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 15:38)

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
