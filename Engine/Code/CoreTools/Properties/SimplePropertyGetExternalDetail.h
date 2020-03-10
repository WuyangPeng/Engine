// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:25)

#ifndef CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_DETAIL_H

#include "SimplePropertyGetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template<typename Value, typename ConstReference>
CoreTools::SimplePropertyGetExternal<Value, ConstReference>
	::SimplePropertyGetExternal(const ValueType& value)
	:m_Value{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template<typename Value, typename ConstReference>
bool CoreTools::SimplePropertyGetExternal<Value, ConstReference>
	::IsValid() const  noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template<typename Value, typename ConstReference>
CoreTools::SimplePropertyGetExternal<Value, ConstReference>
	::operator ConstReferenceType () const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Value;
}

#endif // CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_DETAIL_H