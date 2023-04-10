///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 15:34)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_DETAIL_H

#include "Property.h"
#include "PropertyBaseDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Id, typename T, typename V, typename R, void (T::*FunctionSet)(R), R (T::*FunctionGet)() const>
CoreTools::Property<Id, T, V, R, FunctionSet, FunctionGet>::Property() noexcept
    : value{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Id, typename T, typename V, typename R, void (T::*FunctionSet)(R), R (T::*FunctionGet)() const>
CoreTools::Property<Id, T, V, R, FunctionSet, FunctionGet>::Property(V value)
    : ParentType{}, value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Id, typename T, typename V, typename R, void (T::*FunctionSet)(R), R (T::*FunctionGet)() const>
bool CoreTools::Property<Id, T, V, R, FunctionSet, FunctionGet>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Id, typename T, typename V, typename R, void (T::*FunctionSet)(R), R (T::*FunctionGet)() const>
CoreTools::Property<Id, T, V, R, FunctionSet, FunctionGet>& CoreTools::Property<Id, T, V, R, FunctionSet, FunctionGet>::operator=(R aValue) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    (ParentType::Holder()->*FunctionSet)(aValue);

    return *this;
}

#include STSTEM_WARNING_POP

template <typename Id, typename T, typename V, typename R, void (T::*FunctionSet)(R), R (T::*FunctionGet)() const>
CoreTools::Property<Id, T, V, R, FunctionSet, FunctionGet>::operator R() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (ParentType::Holder()->*FunctionGet)();
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_DETAIL_H