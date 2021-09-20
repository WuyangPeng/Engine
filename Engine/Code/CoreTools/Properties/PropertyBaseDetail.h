//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 13:38)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_BASE_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_BASE_DETAIL_H

#include "PropertyBase.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "System/Helper/PragmaWarning.h"
template <typename ID, typename T>
T* CoreTools::PropertyBase<ID, T>::Holder() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, Holder);
}
#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)
template <typename ID, typename T>
const T* CoreTools::PropertyBase<ID, T>::Holder() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return reinterpret_cast<const T*>(reinterpret_cast<const uint8_t*>(this) - m_Offset);
}
#include STSTEM_WARNING_POP
#ifdef OPEN_CLASS_INVARIANT
template <typename ID, typename T>
bool CoreTools::PropertyBase<ID, T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_BASE_DETAIL_H