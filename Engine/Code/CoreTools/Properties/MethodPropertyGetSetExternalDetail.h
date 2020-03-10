// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:23)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_DETAIL_H

#include "MethodPropertyGetSetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template<typename GetReference, typename SetReference, typename Container,
		 ptrdiff_t(*FO)(), GetReference(Container::*FG)() const, void (Container::*FS)(SetReference)>
CoreTools::MethodPropertyGetSetExternal<GetReference, SetReference, Container, FO, FG, FS>
	::operator GetReferenceType() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	auto offset = (*FO)();
	auto thisPtr = reinterpret_cast<const ContainerType*>(reinterpret_cast<const uint8_t*>(this) - offset);

	return (thisPtr->*FG)();
}

template<typename GetReference, typename SetReference, typename Container,
		 ptrdiff_t(*FO)(), GetReference(Container::*FG)() const, void (Container::*FS)(SetReference)>
CoreTools::MethodPropertyGetSetExternal<GetReference, SetReference, Container, FO, FG, FS>& CoreTools::MethodPropertyGetSetExternal<GetReference, SetReference, Container, FO, FG, FS>
	::operator=(SetReferenceType value)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	auto offset = (*FO)();
	auto thisPtr = reinterpret_cast<ContainerType*>(reinterpret_cast<uint8_t*>(this) - offset);

	(thisPtr->*FS)(value);

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template<typename GetReference, typename SetReference, typename Container,
		 ptrdiff_t(*FO)(), GetReference(Container::*FG)() const, void (Container::*FS)(SetReference)>
bool CoreTools::MethodPropertyGetSetExternal<GetReference, SetReference, Container, FO, FG, FS>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT 

#endif // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_DETAIL_H