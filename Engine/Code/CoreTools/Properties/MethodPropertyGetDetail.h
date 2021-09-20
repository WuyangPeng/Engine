//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 13:37)

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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26447)
template <typename Value, typename ConstReference, typename Container, ptrdiff_t (*FO)(), ConstReference (Container::*FG)() const>
CoreTools::MethodPropertyGet<Value, ConstReference, Container, FO, FG>::operator ConstReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto offset = (*FO)();
    auto thisPtr = reinterpret_cast<const ContainerType*>(reinterpret_cast<const uint8_t*>(this) - offset);

    return (thisPtr->*FG)();
}
#include STSTEM_WARNING_POP
#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_DETAIL_H