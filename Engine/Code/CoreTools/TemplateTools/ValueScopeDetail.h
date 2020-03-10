// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:44)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H  

#include "ValueScope.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
template <typename V>
CoreTools::ValueScope<T>
	::ValueScope(Reference value, V const& set)
	:m_Value{ value }, m_Revert{ value }
{
	m_Value = set;

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
template <typename V1, typename V2>
CoreTools::ValueScope<T>
	::ValueScope(Reference value, V1 const& set, V2 const& revert)
	:m_Value{ value }, m_Revert{ revert }
{
	m_Value = set;

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::ValueScope<T>
	::~ValueScope()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	m_Value = m_Revert;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::ValueScope<T>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

#endif //  CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H

