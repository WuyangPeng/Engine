///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 18:46)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_DETAIL_H

#include "Property.h"
#include "PropertyBaseDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename ID, typename T, typename V, typename R, void (T::*FS)(R), R (T::*FG)() const>
CoreTools::Property<ID, T, V, R, FS, FG>::Property() noexcept
    : m_Value{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename ID, typename T, typename V, typename R, void (T::*FS)(R), R (T::*FG)() const>
CoreTools::Property<ID, T, V, R, FS, FG>::Property(V value)
    : ParentType{}, m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ID, typename T, typename V, typename R, void (T::*FS)(R), R (T::*FG)() const>
bool CoreTools::Property<ID, T, V, R, FS, FG>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename ID, typename T, typename V, typename R, void (T::*FS)(R), R (T::*FG)() const>
CoreTools::Property<ID, T, V, R, FS, FG>& CoreTools::Property<ID, T, V, R, FS, FG>::operator=(R value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    (ParentType::Holder()->*FS)(value);

    return *this;
}

template <typename ID, typename T, typename V, typename R, void (T::*FS)(R), R (T::*FG)() const>
CoreTools::Property<ID, T, V, R, FS, FG>::operator R() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (ParentType::Holder()->*FG)();
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_DETAIL_H