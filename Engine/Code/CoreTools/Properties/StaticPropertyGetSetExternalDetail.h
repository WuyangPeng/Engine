// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:26)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_DETAIL_H

#include "StaticPropertyGetSetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT
template<typename GetReference, typename SetReference, GetReference(*FG)(void), void(*FS)(SetReference)>
bool CoreTools::StaticPropertyGetSetExternal<GetReference, SetReference, FG, FS>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template<typename GetReference, typename SetReference, GetReference(*FG)(void), void(*FS)(SetReference)>
CoreTools::StaticPropertyGetSetExternal<GetReference, SetReference, FG, FS>
	::operator GetReferenceType() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return (*FG)();
}

template<typename GetReference, typename SetReference, GetReference(*FG)(void), void(*FS)(SetReference)>
CoreTools::StaticPropertyGetSetExternal<GetReference, SetReference, FG, FS>& CoreTools::StaticPropertyGetSetExternal<GetReference, SetReference, FG, FS>
	::operator=(SetReferenceType value)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	(*FS)(value);

	return *this;
}

#endif // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_DETAIL_H