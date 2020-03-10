// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:24)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_DETAIL_H

#include "PropertyGetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template<typename T, typename ConstReference, ConstReference(T::*PF)() const>
CoreTools::PropertyGetExternal<T, ConstReference, PF>
	::PropertyGetExternal(const T& object)
	:m_Object{ object }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template<typename T, typename ConstReference, ConstReference(T::*PF)() const>
bool CoreTools::PropertyGetExternal<T, ConstReference, PF>
	::IsValid() const  noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template<typename T, typename ConstReference, ConstReference(T::*PF)() const>
CoreTools::PropertyGetExternal<T, ConstReference, PF>
	::operator ConstReferenceType () const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return (m_Object.*PF)();
}

#endif // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_DETAIL_H