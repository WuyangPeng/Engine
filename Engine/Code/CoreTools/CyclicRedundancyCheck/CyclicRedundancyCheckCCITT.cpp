// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:51)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckCCITT.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)

CoreTools::CyclicRedundancyCheckCCITT
	::CyclicRedundancyCheckCCITT(const char* data, int length) noexcept
	:m_CyclicRedundancyCheck{ 0 }
{
	Calculation(data, length);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::CyclicRedundancyCheckCCITT
	::Calculation(const char* data, int length) noexcept
{
	for (auto i = 0; i < length; ++i)
	{
		m_CyclicRedundancyCheck = GetCCITT(m_CyclicRedundancyCheck, data[i]);
	}
}

uint16_t CoreTools::CyclicRedundancyCheckCCITT
	::GetCCITT(uint16_t cyclicRedundancyCheck, uint16_t value) noexcept
{
	constexpr uint32_t bitSize{ 8 };
	value <<= bitSize;

	for (uint32_t i = bitSize; 0 < i; --i)
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

uint16_t CoreTools::CyclicRedundancyCheckCCITT
::GetCyclicRedundancyCheck() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_CyclicRedundancyCheck;
}


#include STSTEM_WARNING_POP