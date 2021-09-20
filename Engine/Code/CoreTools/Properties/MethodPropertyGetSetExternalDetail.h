//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 13:38)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_DETAIL_H

#include "MethodPropertyGetSetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26440)
template <typename GetReference, typename SetReference, typename Container,
          ptrdiff_t (*FO)(), GetReference (Container::*FG)() const, void (Container::*FS)(SetReference)>
CoreTools::MethodPropertyGetSetExternal<GetReference, SetReference, Container, FO, FG, FS>::operator GetReferenceType() const  
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto offset = (*FO)();
    auto thisPtr = reinterpret_cast<const ContainerType*>(reinterpret_cast<const uint8_t*>(this) - offset);

    return (thisPtr->*FG)();
}
 

template <typename GetReference, typename SetReference, typename Container,
          ptrdiff_t (*FO)(), GetReference (Container::*FG)() const, void (Container::*FS)(SetReference)>
CoreTools::MethodPropertyGetSetExternal<GetReference, SetReference, Container, FO, FG, FS>& CoreTools::MethodPropertyGetSetExternal<GetReference, SetReference, Container, FO, FG, FS>::operator=(SetReferenceType value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto offset = (*FO)();
    auto thisPtr = reinterpret_cast<ContainerType*>(reinterpret_cast<uint8_t*>(this) - offset);

    if (thisPtr != nullptr)
    {
        (thisPtr->*FS)(value);
    }

    return *this;
}
#include STSTEM_WARNING_POP
#ifdef OPEN_CLASS_INVARIANT
template <typename GetReference, typename SetReference, typename Container,
          ptrdiff_t (*FO)(), GetReference (Container::*FG)() const, void (Container::*FS)(SetReference)>
bool CoreTools::MethodPropertyGetSetExternal<GetReference, SetReference, Container, FO, FG, FS>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_DETAIL_H