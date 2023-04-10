///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 15:34)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_DETAIL_H

#include "MethodPropertySetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Reference, typename Container, ptrdiff_t (*FunctionOffset)(), void (Container::*FunctionSet)(Reference)>
CoreTools::MethodPropertySetExternal<Reference, Container, FunctionOffset, FunctionSet>& CoreTools::MethodPropertySetExternal<Reference, Container, FunctionOffset, FunctionSet>::operator=(ReferenceType value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto offset = (*FunctionOffset)();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    auto thisPtr = reinterpret_cast<ContainerType*>(reinterpret_cast<uint8_t*>(this) - offset);

#include STSTEM_WARNING_POP

    if (thisPtr != nullptr)
    {
        (thisPtr->*FunctionSet)(value);
    }

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Reference, typename Container, ptrdiff_t (*FunctionOffset)(), void (Container::*FunctionSet)(Reference)>
bool CoreTools::MethodPropertySetExternal<Reference, Container, FunctionOffset, FunctionSet>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_DETAIL_H