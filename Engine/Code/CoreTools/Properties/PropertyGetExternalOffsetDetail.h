// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:25)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_DETAIL_H

#include "PropertyGetExternalOffset.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT
template<typename T, typename ConstReference, ConstReference(T::*PF)() const, ptrdiff_t(*FO)()>
bool CoreTools::PropertyGetExternalOffset<T, ConstReference, PF, FO>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template<typename T, typename ConstReference, ConstReference(T::*PF)() const, ptrdiff_t(*FO)()>
CoreTools::PropertyGetExternalOffset<T, ConstReference, PF, FO>
	::operator ConstReferenceType() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	auto offset = (*FO)();
	auto thisPtr = reinterpret_cast<const T*>(reinterpret_cast<const uint8_t*>(this) - offset);

	return (thisPtr->*PF)();
}

#endif // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_DETAIL_H