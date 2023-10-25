///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 09:29)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckCCITTTable.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <gsl/util>

CoreTools::CyclicRedundancyCheckCCITTTable::CyclicRedundancyCheckCCITTTable() noexcept
    : table{}
{
    Calculate();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheckCCITTTable)

void CoreTools::CyclicRedundancyCheckCCITTTable::Calculate() noexcept
{
    auto index = 0;
    for (auto& value : table)
    {
        value = CalculateCCITT(index);

        ++index;
    }
}

uint16_t CoreTools::CyclicRedundancyCheckCCITTTable::CalculateCCITT(uint32_t index) noexcept
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

uint16_t CoreTools::CyclicRedundancyCheckCCITTTable::GetCCITT(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return table.at(index);
}
