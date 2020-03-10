// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 13:35)

#include "CoreTools/CoreToolsExport.h"

#include "Memory.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Memory
	::Memory(const FunctionDescribed& functionDescribe)
	:m_FunctionDescribed{ functionDescribe }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Memory)

const CoreTools::FunctionDescribed& CoreTools::Memory
	::GetFunctionDescribed() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_FunctionDescribed;
}
