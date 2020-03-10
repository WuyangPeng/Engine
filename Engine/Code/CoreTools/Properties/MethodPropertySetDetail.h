// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:23)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_DETAIL_H

#include "MethodPropertySet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template<typename Value, typename Reference, typename Container, ptrdiff_t(*FO)(), void (Container::*FS)(Reference)>
CoreTools::MethodPropertySet<Value, Reference, Container, FO, FS>
	::MethodPropertySet()
	:m_Value{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template<typename Value, typename Reference, typename Container, ptrdiff_t(*FO)(), void (Container::*FS)(Reference)>
CoreTools::MethodPropertySet<Value, Reference, Container, FO, FS>
	::MethodPropertySet(ReferenceType value)
	:m_Value{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template<typename Value, typename Reference, typename Container, ptrdiff_t(*FO)(), void (Container::*FS)(Reference)>
bool CoreTools::MethodPropertySet<Value, Reference, Container, FO, FS>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT 

template<typename Value, typename Reference, typename Container, ptrdiff_t(*FO)(), void (Container::*FS)(Reference)>
CoreTools::MethodPropertySet<Value, Reference, Container, FO, FS>& CoreTools::MethodPropertySet<Value, Reference, Container, FO, FS>
	::operator=(ReferenceType value)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	auto offset = (*FO)();
	auto thisPtr = reinterpret_cast<ContainerType*>(reinterpret_cast<uint8_t*>(this) - offset);

	(thisPtr->*FS)(value);

	return *this;
}

#endif // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_DETAIL_H