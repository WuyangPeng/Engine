//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 15:32)

#include "CoreTools/CoreToolsExport.h"

#include "Fibonacci.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

uint32_t CoreTools::RecursiveFibonacci(uint32_t integer) noexcept
{
    if (integer <= 1)
        return integer;

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
