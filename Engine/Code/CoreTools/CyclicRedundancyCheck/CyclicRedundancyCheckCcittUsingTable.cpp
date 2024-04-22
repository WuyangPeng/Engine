/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:15)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckCcittUsingTable.h"
#include "CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CyclicRedundancyCheckCcittUsingTable::CyclicRedundancyCheckCcittUsingTable(const char* data, int length)
    : cyclicRedundancyCheck{ 0 }
{
    Calculation(data, length);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::CyclicRedundancyCheckCcittUsingTable::Calculation(const char* data, int length)
{
    if (data != nullptr)
    {
        for (auto i = 0; i < length; ++i)
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            cyclicRedundancyCheck = GetCcitt(cyclicRedundancyCheck, data[i]);

#include SYSTEM_WARNING_POP
        }
    }
}

uint16_t CoreTools::CyclicRedundancyCheckCcittUsingTable::GetCcitt(uint16_t crc, uint16_t value)
{
    return (crc << 8u) ^ CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.GetCcitt((crc >> 8) ^ value);
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheckCcittUsingTable)

uint16_t CoreTools::CyclicRedundancyCheckCcittUsingTable::GetCyclicRedundancyCheck() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return cyclicRedundancyCheck;
}
