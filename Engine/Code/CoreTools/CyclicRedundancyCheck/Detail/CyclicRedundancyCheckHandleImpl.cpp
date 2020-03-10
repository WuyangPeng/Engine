// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:50)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckHandleImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"   

CoreTools::CyclicRedundancyCheckHandleImpl
	::CyclicRedundancyCheckHandleImpl()
	:m_CCITT{}, m_Table16{}, m_Table32{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheckHandleImpl)

uint16_t CoreTools::CyclicRedundancyCheckHandleImpl
	::GetCCITT(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_CCITT.GetCCITT(index);
}

uint16_t CoreTools::CyclicRedundancyCheckHandleImpl
	::Get16Table(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Table16.Get16Table(index);
}

uint32_t CoreTools::CyclicRedundancyCheckHandleImpl
	::Get32Table(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Table32.Get32Table(index);
}

