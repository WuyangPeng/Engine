// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:41)

#include "PropertyExternal.h"  
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::PropertyExternal ::PropertyExternal() noexcept
    : m_Value{}, m_GetType{ *this }, m_SetType{ *this }, m_GetSetType{ *this }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, PropertyExternal)

const string& CoreTools::PropertyExternal ::GetValue() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Value;
}

void CoreTools::PropertyExternal
	::SetValue(const string& value)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Value = value;
}

