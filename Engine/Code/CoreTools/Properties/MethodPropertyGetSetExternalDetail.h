/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:08)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_DETAIL_H

#include "MethodPropertyGetSetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename GetReference,
          typename SetReference,
          typename Container,
          ptrdiff_t (*FunctionOffset)(),
          GetReference (Container::*FunctionGet)() const,
          void (Container::*FunctionSet)(SetReference)>
CoreTools::MethodPropertyGetSetExternal<GetReference, SetReference, Container, FunctionOffset, FunctionGet, FunctionSet>::operator GetReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto offset = (*FunctionOffset)();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    auto thisPtr = reinterpret_cast<const ContainerType*>(reinterpret_cast<const uint8_t*>(this) - offset);

#include SYSTEM_WARNING_POP

    return (thisPtr->*FunctionGet)();
}

template <typename GetReference,
          typename SetReference,
          typename Container,
          ptrdiff_t (*FunctionOffset)(),
          GetReference (Container::*FunctionGet)() const,
          void (Container::*FunctionSet)(SetReference)>
CoreTools::MethodPropertyGetSetExternal<GetReference, SetReference, Container, FunctionOffset, FunctionGet, FunctionSet>& CoreTools::MethodPropertyGetSetExternal<GetReference, SetReference, Container, FunctionOffset, FunctionGet, FunctionSet>::operator=(SetReferenceType value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto offset = (*FunctionOffset)();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    auto thisPtr = reinterpret_cast<ContainerType*>(reinterpret_cast<uint8_t*>(this) - offset);

#include SYSTEM_WARNING_POP

    if (thisPtr != nullptr)
    {
        (thisPtr->*FunctionSet)(value);
    }

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename GetReference,
          typename SetReference,
          typename Container,
          ptrdiff_t (*FunctionOffset)(),
          GetReference (Container::*FunctionGet)() const,
          void (Container::*FunctionSet)(SetReference)>
bool CoreTools::MethodPropertyGetSetExternal<GetReference, SetReference, Container, FunctionOffset, FunctionGet, FunctionSet>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_DETAIL_H