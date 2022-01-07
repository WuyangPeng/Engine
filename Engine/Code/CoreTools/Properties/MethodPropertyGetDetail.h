///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 18:13)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_DETAIL_H

#include "MethodPropertyGet.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename ConstReference, typename Container, ptrdiff_t (*FO)(), ConstReference (Container::*FG)() const>
CoreTools::MethodPropertyGet<Value, ConstReference, Container, FO, FG>::MethodPropertyGet() noexcept
    : m_Value{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Value, typename ConstReference, typename Container, ptrdiff_t (*FO)(), ConstReference (Container::*FG)() const>
CoreTools::MethodPropertyGet<Value, ConstReference, Container, FO, FG>::MethodPropertyGet(ConstReferenceType value)
    : m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Value, typename ConstReference, typename Container, ptrdiff_t (*FO)(), ConstReference (Container::*FG)() const>
bool CoreTools::MethodPropertyGet<Value, ConstReference, Container, FO, FG>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Value, typename ConstReference, typename Container, ptrdiff_t (*FO)(), ConstReference (Container::*FG)() const>
CoreTools::MethodPropertyGet<Value, ConstReference, Container, FO, FG>::operator ConstReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto offset = (*FO)();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26481)

    auto thisPtr = reinterpret_cast<const ContainerType*>(reinterpret_cast<const uint8_t*>(this) - offset);

#include STSTEM_WARNING_POP

    return (thisPtr->*FG)();
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_DETAIL_H