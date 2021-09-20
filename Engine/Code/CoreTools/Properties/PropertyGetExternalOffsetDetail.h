//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 13:39)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_DETAIL_H

#include "PropertyGetExternalOffset.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#ifdef OPEN_CLASS_INVARIANT
template <typename T, typename ConstReference, ConstReference (T::*PF)() const, ptrdiff_t (*FO)()>
bool CoreTools::PropertyGetExternalOffset<T, ConstReference, PF, FO>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)
template <typename T, typename ConstReference, ConstReference (T::*PF)() const, ptrdiff_t (*FO)()>
CoreTools::PropertyGetExternalOffset<T, ConstReference, PF, FO>::operator ConstReferenceType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto offset = (*FO)();
    auto thisPtr = reinterpret_cast<const T*>(reinterpret_cast<const uint8_t*>(this) - offset);

    return (thisPtr->*PF)();
}
#include STSTEM_WARNING_POP
#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_DETAIL_H