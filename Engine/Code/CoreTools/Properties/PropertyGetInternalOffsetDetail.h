///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 18:53)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_DETAIL_H

#include "PropertyGetInternalOffset.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T, typename V, typename Reference, Reference (T::*PF)() const, ptrdiff_t (*FO)()>
CoreTools::PropertyGetInternalOffset<T, V, Reference, PF, FO>::PropertyGetInternalOffset(ReferenceType value)
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, typename V, typename Reference, Reference (T::*PF)() const, ptrdiff_t (*FO)()>
bool CoreTools::PropertyGetInternalOffset<T, V, Reference, PF, FO>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, typename V, typename Reference, Reference (T::*PF)() const, ptrdiff_t (*FO)()>
CoreTools::PropertyGetInternalOffset<T, V, Reference, PF, FO>& CoreTools::PropertyGetInternalOffset<T, V, Reference, PF, FO>::operator=(ReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = value;

    return *this;
}

template <typename T, typename V, typename Reference, Reference (T::*PF)() const, ptrdiff_t (*FO)()>
void CoreTools::PropertyGetInternalOffset<T, V, Reference, PF, FO>::SetValue(ReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = value;
}

template <typename T, typename V, typename Reference, Reference (T::*PF)() const, ptrdiff_t (*FO)()>
typename CoreTools::PropertyGetInternalOffset<T, V, Reference, PF, FO>::ReferenceType CoreTools::PropertyGetInternalOffset<T, V, Reference, PF, FO>::GetValue() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

template <typename T, typename V, typename Reference, Reference (T::*PF)() const, ptrdiff_t (*FO)()>
CoreTools::PropertyGetInternalOffset<T, V, Reference, PF, FO>::operator ReferenceType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto offset = (*FO)();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    auto thisPtr = reinterpret_cast<const T*>(reinterpret_cast<const uint8_t*>(this) - offset);

#include STSTEM_WARNING_POP

    return (thisPtr->*PF)();
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_DETAIL_H