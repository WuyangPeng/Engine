// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:41)

#include "MethodProperty.h"  
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::MethodProperty
	::MethodProperty() noexcept
	:m_FirstValue{ 0 }, m_GetType{}, m_SetType{}, m_GetSetType{}, m_GetExternalType{}, m_SetExternalType{}, m_GetSetExternalType{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MethodProperty)

ptrdiff_t CoreTools::MethodProperty ::FirstValueGetOffset() noexcept
{
	return offsetof(ClassType, m_GetType);
}

ptrdiff_t CoreTools::MethodProperty ::FirstValueSetOffset() noexcept
{
	return offsetof(ClassType, m_SetType);
}

const int& CoreTools::MethodProperty ::GetFirstValue() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_FirstValue;
}

void CoreTools::MethodProperty ::SetFirstValue(const int& value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_FirstValue = value;
}

ptrdiff_t CoreTools::MethodProperty ::FirstValueGetSetOffset() noexcept
{
	return offsetof(ClassType, m_GetSetType);
}

ptrdiff_t CoreTools::MethodProperty ::FirstValueGetExternalOffset() noexcept
{
	return offsetof(ClassType, m_GetExternalType);
}

ptrdiff_t CoreTools::MethodProperty ::FirstValueSetExternalOffset() noexcept
{
	return offsetof(ClassType, m_SetExternalType);
}

ptrdiff_t CoreTools::MethodProperty ::FirstValueGetSetExternalOffset() noexcept
{
	return offsetof(ClassType, m_GetSetExternalType);
}

