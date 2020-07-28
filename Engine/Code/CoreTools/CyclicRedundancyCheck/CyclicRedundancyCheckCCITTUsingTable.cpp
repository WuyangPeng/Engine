// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:51)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckCCITTUsingTable.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 
#include "CyclicRedundancyCheckHandle.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
CoreTools::CyclicRedundancyCheckCCITTUsingTable
	::CyclicRedundancyCheckCCITTUsingTable(const char* data, int length)
	:m_CyclicRedundancyCheck{ 0 }
{
	Calculation(data, length);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::CyclicRedundancyCheckCCITTUsingTable
	::Calculation(const char* data, int length)
{
	for (auto i = 0; i < length; ++i)
	{
		m_CyclicRedundancyCheck = GetCCITT(m_CyclicRedundancyCheck, data[i]);
	}
}

uint16_t CoreTools::CyclicRedundancyCheckCCITTUsingTable
	::GetCCITT(uint16_t cyclicRedundancyCheck, uint16_t value)
{
	return (cyclicRedundancyCheck << 8) ^ CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.GetCCITT((cyclicRedundancyCheck >> 8) ^ value);
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheckCCITTUsingTable)

uint16_t CoreTools::CyclicRedundancyCheckCCITTUsingTable
	::GetCyclicRedundancyCheck() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_CyclicRedundancyCheck;
}


#include STSTEM_WARNING_POP