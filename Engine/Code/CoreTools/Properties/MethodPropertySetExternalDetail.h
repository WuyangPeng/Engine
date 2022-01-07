///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 18:45)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_DETAIL_H

#include "MethodPropertySetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Reference, typename Container, ptrdiff_t (*FO)(), void (Container::*FS)(Reference)>
CoreTools::MethodPropertySetExternal<Reference, Container, FO, FS>& CoreTools::MethodPropertySetExternal<Reference, Container, FO, FS>::operator=(ReferenceType value) noexcept
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

#ifdef OPEN_CLASS_INVARIANT

template <typename Reference, typename Container, ptrdiff_t (*FO)(), void (Container::*FS)(Reference)>
bool CoreTools::MethodPropertySetExternal<Reference, Container, FO, FS>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_DETAIL_H