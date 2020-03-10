// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:24)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_BASE_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_BASE_DETAIL_H

#include "PropertyBase.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template<typename ID, typename T>
CoreTools::PropertyBase<ID, T>
	::~PropertyBase()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template<typename ID, typename T>
T* CoreTools::PropertyBase<ID, T>
	::Holder()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, Holder);
}

template<typename ID, typename T>
const T* CoreTools::PropertyBase<ID, T>
	::Holder() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return reinterpret_cast<const T*>(reinterpret_cast<const uint8_t*>(this) - m_Offset);
}

#ifdef OPEN_CLASS_INVARIANT
template<typename ID, typename T>
bool CoreTools::PropertyBase<ID, T>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

#endif // CORE_TOOLS_PROPERTIES_PROPERTY_BASE_DETAIL_H