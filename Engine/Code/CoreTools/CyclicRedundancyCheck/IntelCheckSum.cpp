// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:52)

#include "CoreTools/CoreToolsExport.h"

#include "IntelCheckSum.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::IntelCheckSum
	::IntelCheckSum(const char* data, int length)
	:m_IntelCheckSum{ 0 }
{
	Calculation(data, length);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, IntelCheckSum)

int CoreTools::IntelCheckSum
	::GetIntelCheckSum() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_IntelCheckSum;
}

// private
void CoreTools::IntelCheckSum
	::Calculation(const char* data, int length)
{
	auto sum = 0;
	for (auto i = 0; i < length; ++i)
	{
		sum += data[i];
	}

	m_IntelCheckSum = -sum;
}
