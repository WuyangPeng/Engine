//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 14:05)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheck32.h"
#include "CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CyclicRedundancyCheck32::CyclicRedundancyCheck32(const char* data, int length)
    : m_CyclicRedundancyCheck{ 0 }
{
    Calculation(data, length);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::CyclicRedundancyCheck32::Calculation(const char* data, int length)
{
    if (data != nullptr)
    {
        for (auto i = 0; i < length; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            const auto value = (m_CyclicRedundancyCheck ^ data[i]) & 0x000000FFL;
#include STSTEM_WARNING_POP

            m_CyclicRedundancyCheck = ((m_CyclicRedundancyCheck >> 8) & 0x00FFFFFFL) ^ CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get32Table(value);
        }
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheck32)

uint32_t CoreTools::CyclicRedundancyCheck32::GetCyclicRedundancyCheck32() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CyclicRedundancyCheck;
}
