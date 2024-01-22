/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:40)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckCCITT.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <gsl/util>

CoreTools::CyclicRedundancyCheckCCITT::CyclicRedundancyCheckCCITT(const char* data, int length) noexcept
    : cyclicRedundancyCheck{ 0 }
{
    Calculation(data, length);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::CyclicRedundancyCheckCCITT::Calculation(const char* data, int length) noexcept
{
    if (data != nullptr)
    {
        for (auto i = 0; i < length; ++i)
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            cyclicRedundancyCheck = GetCCITT(cyclicRedundancyCheck, data[i]);

#include SYSTEM_WARNING_POP
        }
    }
}

uint16_t CoreTools::CyclicRedundancyCheckCCITT::GetCCITT(uint16_t crc, uint16_t value) noexcept
{
    constexpr auto bitSize = 8;
    value <<= bitSize;

    for (auto i = bitSize; 0 < i; --i)
    {
        if (((value ^ crc) & 0X8000) != 0)
            crc = (crc << 1) ^ gsl::narrow_cast<uint16_t>(0x1021);
        else
            crc <<= 1;

        value <<= 1;
    }

    return (crc);
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheckCCITT)

uint16_t CoreTools::CyclicRedundancyCheckCCITT::GetCyclicRedundancyCheck() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return cyclicRedundancyCheck;
}
