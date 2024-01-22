/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:14)

#ifndef CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_DETAIL_H

#include "SimplePropertySetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename Reference>
CoreTools::SimplePropertySetExternal<Value, Reference>::SimplePropertySetExternal(ValueType& value) noexcept
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Value, typename Reference>
bool CoreTools::SimplePropertySetExternal<Value, Reference>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Value, typename Reference>
CoreTools::SimplePropertySetExternal<Value, Reference>& CoreTools::SimplePropertySetExternal<Value, Reference>::operator=(ReferenceType aValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = aValue;

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_DETAIL_H