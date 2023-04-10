///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 15:34)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_BASE_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_BASE_DETAIL_H

#include "PropertyBase.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Id, typename T>
T* CoreTools::PropertyBase<Id, T>::Holder() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, Holder);
}

template <typename Id, typename T>
const T* CoreTools::PropertyBase<Id, T>::Holder() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<const T*>(reinterpret_cast<const uint8_t*>(this) - offset);

#include STSTEM_WARNING_POP
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Id, typename T>
bool CoreTools::PropertyBase<Id, T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_BASE_DETAIL_H