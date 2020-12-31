//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:37)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_DETAIL_H

#include "MethodPropertyGet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename ConstReference, typename Container, ptrdiff_t (*FO)(), ConstReference (Container::*FG)() const>
CoreTools::MethodPropertyGet<Value, ConstReference, Container, FO, FG>::MethodPropertyGet()
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
CoreTools::MethodPropertyGet<Value, ConstReference, Container, FO, FG>::operator ConstReferenceType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto offset = (*FO)();
    auto thisPtr = reinterpret_cast<const ContainerType*>(reinterpret_cast<const uint8_t*>(this) - offset);

    return (thisPtr->*FG)();
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_DETAIL_H