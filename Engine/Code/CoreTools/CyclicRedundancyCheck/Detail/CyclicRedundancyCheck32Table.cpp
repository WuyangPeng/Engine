//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:44)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheck32Table.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CyclicRedundancyCheck32Table::CyclicRedundancyCheck32Table() noexcept
    : m_Table{}
{
    Calculate();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheck32Table)

void CoreTools::CyclicRedundancyCheck32Table::Calculate() noexcept
{
    auto index = 0;
    for (auto& value : m_Table)
    {
        value = Calculate32(index);

        ++index;
    }
}

uint32_t CoreTools::CyclicRedundancyCheck32Table::Calculate32(uint32_t index) noexcept
{
    auto value = index;
    constexpr auto bitSize = 8;

    for (auto i = bitSize; i > 0; i--)
    {
        if ((value & 1) != 0)
            value = (value >> 1) ^ 0xEDB88320L;
        else
            value >>= 1;
    }

    return value;
}

uint32_t CoreTools::CyclicRedundancyCheck32Table::Get32Table(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Table.at(index);
}
