// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:43)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_DETAIL_H  

#include "ReferenceCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::ReferenceCast<T>
	::ReferenceCast(T& value) noexcept
	: m_Value{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::ReferenceCast<T>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename T>
CoreTools::ReferenceCast<T>
	::operator T&() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return const_cast<ClassType*>(this)->m_Value;
}

CoreTools::ReferenceCast<int>
	::ReferenceCast(int value) noexcept
	: m_Value{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ReferenceCast<int>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::ReferenceCast<int>
	::operator int() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return m_Value;
}
#endif //  CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_DETAIL_H

