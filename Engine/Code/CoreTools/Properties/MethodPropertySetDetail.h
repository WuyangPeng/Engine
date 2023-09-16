///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 15:05)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_DETAIL_H

#include "MethodPropertySet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename Reference, typename Container, ptrdiff_t (*FunctionOffset)(), void (Container::*FunctionSet)(Reference)>
CoreTools::MethodPropertySet<Value, Reference, Container, FunctionOffset, FunctionSet>::MethodPropertySet() noexcept
    : value{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Value, typename Reference, typename Container, ptrdiff_t (*FunctionOffset)(), void (Container::*FunctionSet)(Reference)>
CoreTools::MethodPropertySet<Value, Reference, Container, FunctionOffset, FunctionSet>::MethodPropertySet(ReferenceType value)
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Value, typename Reference, typename Container, ptrdiff_t (*FunctionOffset)(), void (Container::*FunctionSet)(Reference)>
bool CoreTools::MethodPropertySet<Value, Reference, Container, FunctionOffset, FunctionSet>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Value, typename Reference, typename Container, ptrdiff_t (*FunctionOffset)(), void (Container::*FunctionSet)(Reference)>
CoreTools::MethodPropertySet<Value, Reference, Container, FunctionOffset, FunctionSet>& CoreTools::MethodPropertySet<Value, Reference, Container, FunctionOffset, FunctionSet>::operator=(ReferenceType aValue) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto offset = (*FunctionOffset)();

#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26481)

    auto thisPtr = reinterpret_cast<ContainerType*>(reinterpret_cast<uint8_t*>(this) - offset);

#include SYSTEM_WARNING_POP

    if (thisPtr != nullptr)
    {
        (thisPtr->*FunctionSet)(aValue);
    }

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_DETAIL_H