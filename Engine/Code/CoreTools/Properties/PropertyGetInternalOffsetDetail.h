/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:13)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_DETAIL_H

#include "PropertyGetInternalOffset.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T, typename V, typename Reference, Reference (T::*PropertyFunction)() const, ptrdiff_t (*FunctionOffset)()>
CoreTools::PropertyGetInternalOffset<T, V, Reference, PropertyFunction, FunctionOffset>::PropertyGetInternalOffset(ReferenceType value)
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, typename V, typename Reference, Reference (T::*PropertyFunction)() const, ptrdiff_t (*FunctionOffset)()>
bool CoreTools::PropertyGetInternalOffset<T, V, Reference, PropertyFunction, FunctionOffset>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, typename V, typename Reference, Reference (T::*PropertyFunction)() const, ptrdiff_t (*FunctionOffset)()>
CoreTools::PropertyGetInternalOffset<T, V, Reference, PropertyFunction, FunctionOffset>& CoreTools::PropertyGetInternalOffset<T, V, Reference, PropertyFunction, FunctionOffset>::operator=(ReferenceType aValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = aValue;

    return *this;
}

template <typename T, typename V, typename Reference, Reference (T::*PropertyFunction)() const, ptrdiff_t (*FunctionOffset)()>
void CoreTools::PropertyGetInternalOffset<T, V, Reference, PropertyFunction, FunctionOffset>::SetValue(ReferenceType aValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = aValue;
}

template <typename T, typename V, typename Reference, Reference (T::*PropertyFunction)() const, ptrdiff_t (*FunctionOffset)()>
typename CoreTools::PropertyGetInternalOffset<T, V, Reference, PropertyFunction, FunctionOffset>::ReferenceType CoreTools::PropertyGetInternalOffset<T, V, Reference, PropertyFunction, FunctionOffset>::GetValue() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

template <typename T, typename V, typename Reference, Reference (T::*PropertyFunction)() const, ptrdiff_t (*FunctionOffset)()>
CoreTools::PropertyGetInternalOffset<T, V, Reference, PropertyFunction, FunctionOffset>::operator ReferenceType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto offset = (*FunctionOffset)();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    auto thisPtr = reinterpret_cast<const T*>(reinterpret_cast<const uint8_t*>(this) - offset);

#include SYSTEM_WARNING_POP

    return (thisPtr->*PropertyFunction)();
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_DETAIL_H