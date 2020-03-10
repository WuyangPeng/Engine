// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:50)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheck32.h"
#include "CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

CoreTools::CyclicRedundancyCheck32
	::CyclicRedundancyCheck32(const char* data, int length)
	:m_CyclicRedundancyCheck{ 0 }
{
	Calculation(data, length);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::CyclicRedundancyCheck32
	::Calculation(const char* data, int length)
{
	for (auto i = 0; i < length; ++i)
	{
		auto value = (m_CyclicRedundancyCheck ^ data[i]) & 0x000000FFL;
		m_CyclicRedundancyCheck = ((m_CyclicRedundancyCheck >> 8) & 0x00FFFFFFL) ^ CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get32Table(value);
	}
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheck32)

uint32_t CoreTools::CyclicRedundancyCheck32
	::GetCyclicRedundancyCheck32() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_CyclicRedundancyCheck;
}


