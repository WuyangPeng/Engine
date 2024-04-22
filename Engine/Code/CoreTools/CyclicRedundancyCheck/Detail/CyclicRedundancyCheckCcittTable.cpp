/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:14)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckCcittTable.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <gsl/util>

CoreTools::CyclicRedundancyCheckCcittTable::CyclicRedundancyCheckCcittTable() noexcept
    : table{}
{
    Calculate();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheckCcittTable)

void CoreTools::CyclicRedundancyCheckCcittTable::Calculate() noexcept
{
    auto index = 0;
    for (auto& element : table)
    {
        element = CalculateCcitt(index);

        ++index;
    }
}

uint16_t CoreTools::CyclicRedundancyCheckCcittTable::CalculateCcitt(uint32_t index) noexcept
{
    uint16_t value{ 0 };
    constexpr auto bitSize = 8;
    index <<= bitSize;

    for (auto i = bitSize; 0 < i; --i)
    {
        if (((index ^ value) & 0x8000) != 0)
            value = gsl::narrow_cast<uint16_t>(value << 1) ^ gsl::narrow_cast<uint16_t>(0x1021);
        else
            value <<= 1;

        index <<= 1;
    }

    return value;
}

uint16_t CoreTools::CyclicRedundancyCheckCcittTable::GetCcitt(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return table.at(index);
}
