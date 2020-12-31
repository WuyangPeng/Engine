//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 14:02)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheck16.h"
#include "CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CyclicRedundancyCheck16::CyclicRedundancyCheck16(const char* data, int length)
    : m_CyclicRedundancyCheck{ 0 }
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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            const auto value = data[i];
#include STSTEM_WARNING_POP

            // ��4λ
            const auto lower = CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table(m_CyclicRedundancyCheck & 0xF);
            m_CyclicRedundancyCheck = (m_CyclicRedundancyCheck >> 4) & 0x0FFF;
            m_CyclicRedundancyCheck = m_CyclicRedundancyCheck ^ lower ^ CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table(value & 0xF);

            // ����λ
            const auto upper = CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table(m_CyclicRedundancyCheck & 0xF);
            m_CyclicRedundancyCheck = (m_CyclicRedundancyCheck >> 4) & 0x0FFF;
            m_CyclicRedundancyCheck = m_CyclicRedundancyCheck ^ upper ^ CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table((value >> 4) & 0xF);
        }
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheck16)

uint16_t CoreTools::CyclicRedundancyCheck16::GetCyclicRedundancyCheck16() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CyclicRedundancyCheck;
}
