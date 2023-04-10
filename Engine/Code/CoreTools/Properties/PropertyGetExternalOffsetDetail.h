///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 15:36)

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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    auto thisPtr = reinterpret_cast<const T*>(reinterpret_cast<const uint8_t*>(this) - offset);

#include STSTEM_WARNING_POP

    return (thisPtr->*PropertyFunction)();
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_DETAIL_H