// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:24)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_DETAIL_H

#include "Property.h"
#include "PropertyBaseDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template<typename ID, typename T, typename V, typename R, void (T::*FS)(R), R(T::*FG)() const>
CoreTools::Property<ID, T, V, R, FS, FG>
	::Property()
	:m_Value{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template<typename ID, typename T, typename V, typename R, void (T::*FS)(R), R(T::*FG)() const>
CoreTools::Property<ID, T, V, R, FS, FG>
	::Property(V value)
	:ParentType{}, m_Value{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template<typename ID, typename T, typename V, typename R, void (T::*FS)(R), R(T::*FG)() const>
bool CoreTools::Property<ID, T, V, R, FS, FG>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template<typename ID, typename T, typename V, typename R, void (T::*FS)(R), R(T::*FG)() const>
CoreTools::Property<ID, T, V, R, FS, FG>& CoreTools::Property<ID, T, V, R, FS, FG>
	::operator=(R value)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	(ParentType::Holder()->*FS)(value);

	return *this;
}

template<typename ID, typename T, typename V, typename R, void (T::*FS)(R), R(T::*FG)() const>
CoreTools::Property<ID, T, V, R, FS, FG>
	::operator R() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return (ParentType::Holder()->*FG)();
}

#endif // CORE_TOOLS_PROPERTIES_PROPERTY_DETAIL_H