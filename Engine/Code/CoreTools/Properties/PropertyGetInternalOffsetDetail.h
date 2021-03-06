//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:39)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_DETAIL_H

#include "PropertyGetInternalOffset.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T, typename V, typename Reference, Reference (T::*PF)() const, ptrdiff_t (*FO)()>
CoreTools::PropertyGetInternalOffset<T, V, Reference, PF, FO>::PropertyGetInternalOffset(ReferenceType value)
    : m_Value{ value }
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

    m_Value = value;

    return *this;
}

template <typename T, typename V, typename Reference, Reference (T::*PF)() const, ptrdiff_t (*FO)()>
void CoreTools::PropertyGetInternalOffset<T, V, Reference, PF, FO>::SetValue(ReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Value = value;
}

template <typename T, typename V, typename Reference, Reference (T::*PF)() const, ptrdiff_t (*FO)()>
typename CoreTools::PropertyGetInternalOffset<T, V, Reference, PF, FO>::ReferenceType CoreTools::PropertyGetInternalOffset<T, V, Reference, PF, FO>::GetValue() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Value;
}

template <typename T, typename V, typename Reference, Reference (T::*PF)() const, ptrdiff_t (*FO)()>
CoreTools::PropertyGetInternalOffset<T, V, Reference, PF, FO>::operator ReferenceType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto offset = (*FO)();
    auto thisPtr = reinterpret_cast<const T*>(reinterpret_cast<const uint8_t*>(this) - offset);

    return (thisPtr->*PF)();
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_DETAIL_H