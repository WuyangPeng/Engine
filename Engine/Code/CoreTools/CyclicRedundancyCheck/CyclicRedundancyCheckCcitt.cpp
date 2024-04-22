/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:14)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckCcitt.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <gsl/util>

CoreTools::CyclicRedundancyCheckCcitt::CyclicRedundancyCheckCcitt(const char* data, int length) noexcept
    : cyclicRedundancyCheck{ 0 }
{
    Calculation(data, length);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::CyclicRedundancyCheckCcitt::Calculation(const char* data, int length) noexcept
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

uint16_t CoreTools::CyclicRedundancyCheckCcitt::GetCcitt(uint16_t crc, uint16_t value) noexcept
{
    constexpr auto bitSize = 8;
    value <<= bitSize;

    for (auto i = bitSize; 0 < i; --i)
    {
        if (((value ^ crc) & 0X8000) != 0)
            crc = (crc << 1u) ^ gsl::narrow_cast<uint16_t>(0x1021);
        else
            crc <<= 1;

        value <<= 1;
    }

    return (crc);
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheckCcitt)

uint16_t CoreTools::CyclicRedundancyCheckCcitt::GetCyclicRedundancyCheck() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return cyclicRedundancyCheck;
}
