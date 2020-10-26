//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:38)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_DETAIL_H

#include "MethodPropertySet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename Reference, typename Container, ptrdiff_t (*FO)(), void (Container::*FS)(Reference)>
CoreTools::MethodPropertySet<Value, Reference, Container, FO, FS>::MethodPropertySet()
    : m_Value{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Value, typename Reference, typename Container, ptrdiff_t (*FO)(), void (Container::*FS)(Reference)>
CoreTools::MethodPropertySet<Value, Reference, Container, FO, FS>::MethodPropertySet(ReferenceType value)
    : m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Value, typename Reference, typename Container, ptrdiff_t (*FO)(), void (Container::*FS)(Reference)>
bool CoreTools::MethodPropertySet<Value, Reference, Container, FO, FS>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Value, typename Reference, typename Container, ptrdiff_t (*FO)(), void (Container::*FS)(Reference)>
CoreTools::MethodPropertySet<Value, Reference, Container, FO, FS>& CoreTools::MethodPropertySet<Value, Reference, Container, FO, FS>::operator=(ReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto offset = (*FO)();
    auto thisPtr = reinterpret_cast<ContainerType*>(reinterpret_cast<uint8_t*>(this) - offset);

    (thisPtr->*FS)(value);

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_DETAIL_H