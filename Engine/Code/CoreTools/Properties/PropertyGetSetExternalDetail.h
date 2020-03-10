// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:25)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_DETAIL_H

#include "PropertyGetSetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template<typename T, typename GetReference, GetReference(T::*FG)(void) const,
		 typename SetReference, void (T::*FS)(SetReference)	>
CoreTools::PropertyGetSetExternal<T, GetReference, FG, SetReference, FS>
	::PropertyGetSetExternal(T& object)
	:m_Object{ object }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template<typename T, typename GetReference, GetReference(T::*FG)(void) const,
		 typename SetReference, void (T::*FS)(SetReference)	>
bool CoreTools::PropertyGetSetExternal<T, GetReference, FG, SetReference, FS>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template<typename T, typename GetReference, GetReference(T::*FG)(void) const,
		 typename SetReference, void (T::*FS)(SetReference)	>
CoreTools::PropertyGetSetExternal<T, GetReference, FG, SetReference, FS>
	::operator GetReferenceType () const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return (m_Object.*FG)();
}

template<typename T, typename GetReference, GetReference(T::*FG)(void) const,
		 typename SetReference, void (T::*FS)(SetReference)	>
CoreTools::PropertyGetSetExternal<T, GetReference, FG, SetReference, FS>& CoreTools::PropertyGetSetExternal<T, GetReference, FG, SetReference, FS>
	::operator=(SetReferenceType value)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	(m_Object.*FS)(value);

	return *this;
}

#endif // CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_DETAIL_H