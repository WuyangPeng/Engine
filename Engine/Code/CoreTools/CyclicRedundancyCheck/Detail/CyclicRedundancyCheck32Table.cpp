///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 09:28)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheck32Table.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CyclicRedundancyCheck32Table::CyclicRedundancyCheck32Table() noexcept
    : table{}
{
    Calculate();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheck32Table)

void CoreTools::CyclicRedundancyCheck32Table::Calculate() noexcept
{
    auto index = 0;
    for (auto& value : table)
    {
        value = Calculate32(index);

        ++index;
    }
}

uint32_t CoreTools::CyclicRedundancyCheck32Table::Get32Table(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return table.at(index);
}
