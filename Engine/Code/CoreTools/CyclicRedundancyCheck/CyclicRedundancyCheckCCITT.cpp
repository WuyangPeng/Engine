//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 14:07)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckCCITT.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CyclicRedundancyCheckCCITT::CyclicRedundancyCheckCCITT(const char* data, int length) noexcept
    : m_CyclicRedundancyCheck{ 0 }
{
    Calculation(data, length);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::CyclicRedundancyCheckCCITT::Calculation(const char* data, int length) noexcept
{
    if (data != nullptr)
    {
        for (auto i = 0; i < length; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            m_CyclicRedundancyCheck = GetCCITT(m_CyclicRedundancyCheck, data[i]);
#include STSTEM_WARNING_POP
        }
    }
}

uint16_t CoreTools::CyclicRedundancyCheckCCITT::GetCCITT(uint16_t cyclicRedundancyCheck, uint16_t value) noexcept
{
    constexpr auto bitSize = 8;
    value <<= bitSize;

    for (auto i = bitSize; 0 < i; --i)
    {
        if (((value ^ cyclicRedundancyCheck) & 0X8000) != 0)
            cyclicRedundancyCheck = (cyclicRedundancyCheck << 1) ^ 0x1021;
        else
            cyclicRedundancyCheck <<= 1;

        value <<= 1;
    }

    return (cyclicRedundancyCheck);
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheckCCITT)

uint16_t CoreTools::CyclicRedundancyCheckCCITT::GetCyclicRedundancyCheck() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CyclicRedundancyCheck;
}
