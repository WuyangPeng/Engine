/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:07)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_DETAIL_H

#include "PropertyGetExternalOffset.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename T, typename ConstReference, ConstReference (T::*PropertyFunction)() const, ptrdiff_t (*FunctionOffset)()>
bool CoreTools::PropertyGetExternalOffset<T, ConstReference, PropertyFunction, FunctionOffset>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, typename ConstReference, ConstReference (T::*PropertyFunction)() const, ptrdiff_t (*FunctionOffset)()>
CoreTools::PropertyGetExternalOffset<T, ConstReference, PropertyFunction, FunctionOffset>::operator ConstReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto offset = (*FunctionOffset)();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    auto thisPtr = reinterpret_cast<const T*>(reinterpret_cast<const uint8_t*>(this) - offset);

#include SYSTEM_WARNING_POP

    return (thisPtr->*PropertyFunction)();
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_DETAIL_H