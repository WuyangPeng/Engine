/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:12)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_DETAIL_H

#include "MethodPropertyGetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename ConstReference, typename Container, ptrdiff_t (*FunctionOffset)(), ConstReference (Container::*FunctionGet)() const>
CoreTools::MethodPropertyGetExternal<ConstReference, Container, FunctionOffset, FunctionGet>::operator ConstReferenceType() const noexcept
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

#ifdef OPEN_CLASS_INVARIANT

template <typename ConstReference, typename Container, ptrdiff_t (*FunctionOffset)(), ConstReference (Container::*FunctionGet)() const>
bool CoreTools::MethodPropertyGetExternal<ConstReference, Container, FunctionOffset, FunctionGet>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_DETAIL_H