// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:26)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_DETAIL_H

#include "StaticPropertySetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT
template<typename Reference, void(*PF)(Reference)>
bool CoreTools::StaticPropertySetExternal<Reference, PF>
	::IsValid() const  noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT


template<typename Reference, void(*PF)(Reference)>
CoreTools::StaticPropertySetExternal<Reference, PF>& CoreTools::StaticPropertySetExternal<Reference, PF>
	::operator=(ReferenceType value)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	(*PF)(value);

	return *this;
}

#endif // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_DETAIL_H