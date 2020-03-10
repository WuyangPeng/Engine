// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:22)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_DETAIL_H

#include "MethodPropertyGetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template<typename ConstReference, typename Container, ptrdiff_t(*FO)(), ConstReference(Container::*FG)() const>
CoreTools::MethodPropertyGetExternal<ConstReference, Container, FO, FG>
	::operator ConstReferenceType() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	auto offset = (*FO)();
	auto thisPtr = reinterpret_cast<const ContainerType*>(reinterpret_cast<const uint8_t*>(this) - offset);

	return (thisPtr->*FG)();
}

#ifdef OPEN_CLASS_INVARIANT
template<typename ConstReference, typename Container, ptrdiff_t(*FO)(), ConstReference(Container::*FG)() const>
bool CoreTools::MethodPropertyGetExternal<ConstReference, Container, FO, FG>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT 

#endif // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_DETAIL_H