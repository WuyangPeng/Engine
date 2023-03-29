///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/22 19:20)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheck16Table.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CyclicRedundancyCheck16Table::CyclicRedundancyCheck16Table() noexcept
    : table{ 0x0000,
             0xCC01,
             0xD801,
             0x1400,
             0xF001,
             0x3C00,
             0x2800,
             0xE401,
             0xA001,
             0x6C00,
             0x7800,
             0xB401,
             0x5000,
             0x9C01,
             0x8801,
             0x4400 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheck16Table)

uint16_t CoreTools::CyclicRedundancyCheck16Table::Get16Table(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return table.at(index);
}
