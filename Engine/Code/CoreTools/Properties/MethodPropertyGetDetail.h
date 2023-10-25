///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:09)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_DETAIL_H

#include "MethodPropertyGet.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename ConstReference, typename Container, ptrdiff_t (*FunctionOffset)(), ConstReference (Container::*FunctionGet)() const>
CoreTools::MethodPropertyGet<Value, ConstReference, Container, FunctionOffset, FunctionGet>::MethodPropertyGet() noexcept
    : value{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Value, typename ConstReference, typename Container, ptrdiff_t (*FunctionOffset)(), ConstReference (Container::*FunctionGet)() const>
CoreTools::MethodPropertyGet<Value, ConstReference, Container, FunctionOffset, FunctionGet>::MethodPropertyGet(ConstReferenceType value)
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Value, typename ConstReference, typename Container, ptrdiff_t (*FunctionOffset)(), ConstReference (Container::*FunctionGet)() const>
bool CoreTools::MethodPropertyGet<Value, ConstReference, Container, FunctionOffset, FunctionGet>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Value, typename ConstReference, typename Container, ptrdiff_t (*FunctionOffset)(), ConstReference (Container::*FunctionGet)() const>
CoreTools::MethodPropertyGet<Value, ConstReference, Container, FunctionOffset, FunctionGet>::operator ConstReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto offset = (*FunctionOffset)();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26481)

    auto thisPtr = reinterpret_cast<const ContainerType*>(reinterpret_cast<const uint8_t*>(this) - offset);

#include SYSTEM_WARNING_POP

    return (thisPtr->*FunctionGet)();
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_DETAIL_H