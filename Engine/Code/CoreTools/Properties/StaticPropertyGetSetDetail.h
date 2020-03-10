// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:26)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_DETAIL_H

#include "StaticPropertyGetSet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template<typename Value, typename GetReference, typename SetReference, typename Container,
		 GetReference(*FG)(void), void(*FS)(SetReference)>
CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, FG, FS>
	::StaticPropertyGetSet()
	:m_Value{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template<typename Value, typename GetReference, typename SetReference, typename Container,
		 GetReference(*FG)(void), void(*FS)(SetReference)>
CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, FG, FS>
	::StaticPropertyGetSet(SetReferenceType value)
	:m_Value{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template<typename Value, typename GetReference, typename SetReference, typename Container,
		 GetReference(*FG)(void), void(*FS)(SetReference)>
bool CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, FG, FS>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template<typename Value, typename GetReference, typename SetReference, typename Container,
		 GetReference(*FG)(void), void(*FS)(SetReference)>
CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, FG, FS>
	::operator GetReferenceType() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return (*FG)();
}

template<typename Value, typename GetReference, typename SetReference, typename Container,
		 GetReference(*FG)(void), void(*FS)(SetReference)>
CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, FG, FS>& CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, FG, FS>
	::operator=(SetReferenceType value)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	(*FS)(value);

	return *this;
}

#endif // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_DETAIL_H