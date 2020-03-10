// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:42)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_DETAIL_H 

#include "ExplicitCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::ExplicitCast<T>
	::ExplicitCast(T value)
	:m_Value{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::ExplicitCast<T>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename T>
CoreTools::ExplicitCast<T>
	::operator ValueType () const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Value;
}

template <typename T>
CoreTools::ExplicitCast<T const&>
	::ExplicitCast(T const& value)
	:m_Value{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::ExplicitCast<T const&>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename T>
CoreTools::ExplicitCast<T const&>
	::operator T const&() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Value;
}

template <typename T>
CoreTools::ExplicitCast<T const*>
	::ExplicitCast(T const* value)
	:m_Value{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::ExplicitCast<T const*>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename T>
CoreTools::ExplicitCast<T const*>
	::operator T const*() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Value;
}

#endif //  CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_DETAIL_H

