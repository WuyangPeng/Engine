///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 18:07)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckCCITTTable.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

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
            value = (value << 1) ^ 0x1021;
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
