//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:39)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_DETAIL_H

#include "PropertyGetSetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T, typename GetReference, GetReference (T::*FG)(void) const,
          typename SetReference, void (T::*FS)(SetReference)>
CoreTools::PropertyGetSetExternal<T, GetReference, FG, SetReference, FS>::PropertyGetSetExternal(T& object)
    : m_Object{ object }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T, typename GetReference, GetReference (T::*FG)(void) const,
          typename SetReference, void (T::*FS)(SetReference)>
bool CoreTools::PropertyGetSetExternal<T, GetReference, FG, SetReference, FS>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T, typename GetReference, GetReference (T::*FG)(void) const,
          typename SetReference, void (T::*FS)(SetReference)>
CoreTools::PropertyGetSetExternal<T, GetReference, FG, SetReference, FS>::operator GetReferenceType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (m_Object.*FG)();
}

template <typename T, typename GetReference, GetReference (T::*FG)(void) const,
          typename SetReference, void (T::*FS)(SetReference)>
CoreTools::PropertyGetSetExternal<T, GetReference, FG, SetReference, FS>& CoreTools::PropertyGetSetExternal<T, GetReference, FG, SetReference, FS>::operator=(SetReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    (m_Object.*FS)(value);

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_DETAIL_H