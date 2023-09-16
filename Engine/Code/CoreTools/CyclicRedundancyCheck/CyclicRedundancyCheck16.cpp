///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/22 19:21)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheck16.h"
#include "CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CyclicRedundancyCheck16::CyclicRedundancyCheck16(const char* data, int length)
    : cyclicRedundancyCheck{ 0 }
{
    Calculation(data, length);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::CyclicRedundancyCheck16::Calculation(const char* data, int length)
{
    if (data != nullptr)
    {
        for (auto i = 0; i < length; ++i)
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            const auto value = data[i];

#include SYSTEM_WARNING_POP

            // 低4位
            const auto lower = CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table(cyclicRedundancyCheck & 0xF);
            cyclicRedundancyCheck = (cyclicRedundancyCheck >> 4) & 0x0FFF;
            cyclicRedundancyCheck = cyclicRedundancyCheck ^ lower ^ CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table(value & 0xF);

            // 高4位
            const auto upper = CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table(cyclicRedundancyCheck & 0xF);
            cyclicRedundancyCheck = (cyclicRedundancyCheck >> 4) & 0x0FFF;
            cyclicRedundancyCheck = cyclicRedundancyCheck ^ upper ^ CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table((value >> 4) & 0xF);
        }
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheck16)

uint16_t CoreTools::CyclicRedundancyCheck16::GetCyclicRedundancyCheck16() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return cyclicRedundancyCheck;
}
