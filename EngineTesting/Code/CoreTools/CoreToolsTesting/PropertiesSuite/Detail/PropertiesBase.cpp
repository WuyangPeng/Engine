// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:41)

#include "PropertiesBase.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

#include <string>

using std::string;

CoreTools::PropertiesBase ::PropertiesBase() noexcept
    : m_FifthValue{ 0 }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, PropertiesBase)

int CoreTools::PropertiesBase ::GetFifthValue() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_FifthValue;
}

void CoreTools::PropertiesBase ::SetFifthValue(int value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_FifthValue = value;
}

namespace CoreTools
{
	const ptrdiff_t CoreTools::PropertyBase<PropertiesBase::PropFifthValue, PropertiesBase>::m_Offset = offsetof(PropertiesBase, FifthValue);
}
