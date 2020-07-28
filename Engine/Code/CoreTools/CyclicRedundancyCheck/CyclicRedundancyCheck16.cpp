// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 16:50)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheck16.h"
#include "CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)

CoreTools::CyclicRedundancyCheck16
	::CyclicRedundancyCheck16(const char* data, int length)
	:m_CyclicRedundancyCheck{ 0 }
{
	Calculation(data, length);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::CyclicRedundancyCheck16
	::Calculation(const char* data, int length)
{
	for (auto i = 0; i < length; ++i)
	{
		// 低4位 
		const auto lower = CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table(m_CyclicRedundancyCheck & 0xF);
		m_CyclicRedundancyCheck = (m_CyclicRedundancyCheck >> 4) & 0x0FFF;
		m_CyclicRedundancyCheck = m_CyclicRedundancyCheck ^ lower ^ CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table(data[i] & 0xF);

		// 高四位 
		const auto upper = CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table(m_CyclicRedundancyCheck & 0xF);
		m_CyclicRedundancyCheck = (m_CyclicRedundancyCheck >> 4) & 0x0FFF;
		m_CyclicRedundancyCheck = m_CyclicRedundancyCheck ^ upper ^ CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table((data[i] >> 4) & 0xF);
	}
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheck16)

uint16_t CoreTools::CyclicRedundancyCheck16
	::GetCyclicRedundancyCheck16() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_CyclicRedundancyCheck;
}


#include STSTEM_WARNING_POP