///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 18:30)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_DETAIL_H

#include "MethodPropertyGetSet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value,
          typename GetReference,
          typename SetReference,
          typename Container,
          ptrdiff_t (*FO)(),
          GetReference (Container::*FG)() const,
          void (Container::*FS)(SetReference)>
CoreTools::MethodPropertyGetSet<Value, GetReference, SetReference, Container, FO, FG, FS>::MethodPropertyGetSet() noexcept
    : m_Value{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Value,
          typename GetReference,
          typename SetReference,
          typename Container,
          ptrdiff_t (*FO)(),
          GetReference (Container::*FG)() const,
          void (Container::*FS)(SetReference)>
CoreTools::MethodPropertyGetSet<Value, GetReference, SetReference, Container, FO, FG, FS>::MethodPropertyGetSet(SetReferenceType value)
    : m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Value,
          typename GetReference,
          typename SetReference,
          typename Container,
          ptrdiff_t (*FO)(),
          GetReference (Container::*FG)() const,
          void (Container::*FS)(SetReference)>
bool CoreTools::MethodPropertyGetSet<Value, GetReference, SetReference, Container, FO, FG, FS>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Value,
          typename GetReference,
          typename SetReference,
          typename Container,
          ptrdiff_t (*FO)(),
          GetReference (Container::*FG)() const,
          void (Container::*FS)(SetReference)>
CoreTools::MethodPropertyGetSet<Value, GetReference, SetReference, Container, FO, FG, FS>::operator GetReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto offset = (*FO)();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    auto thisPtr = reinterpret_cast<const ContainerType*>(reinterpret_cast<const uint8_t*>(this) - offset);

#include STSTEM_WARNING_POP

    return (thisPtr->*FG)();
}

template <typename Value,
          typename GetReference,
          typename SetReference,
          typename Container,
          ptrdiff_t (*FO)(),
          GetReference (Container::*FG)() const,
          void (Container::*FS)(SetReference)>
CoreTools::MethodPropertyGetSet<Value, GetReference, SetReference, Container, FO, FG, FS>& CoreTools::MethodPropertyGetSet<Value, GetReference, SetReference, Container, FO, FG, FS>::operator=(SetReferenceType value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto offset = (*FO)();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    auto thisPtr = reinterpret_cast<ContainerType*>(reinterpret_cast<uint8_t*>(this) - offset);

#include STSTEM_WARNING_POP

    if (thisPtr != nullptr)
    {
        (thisPtr->*FS)(value);
    }

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_DETAIL_H