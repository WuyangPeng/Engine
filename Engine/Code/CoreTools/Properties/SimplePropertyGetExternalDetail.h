/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:07)

#ifndef CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_DETAIL_H

#include "SimplePropertyGetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename ConstReference>
requires(std::is_const_v<std::remove_reference_t<ConstReference>> && std::is_reference_v<ConstReference>)
CoreTools::SimplePropertyGetExternal<Value, ConstReference>::SimplePropertyGetExternal(const ValueType& value) noexcept
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Value, typename ConstReference>
requires(std::is_const_v<std::remove_reference_t<ConstReference>> && std::is_reference_v<ConstReference>)
bool CoreTools::SimplePropertyGetExternal<Value, ConstReference>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Value, typename ConstReference>
requires(std::is_const_v<std::remove_reference_t<ConstReference>> && std::is_reference_v<ConstReference>)
CoreTools::SimplePropertyGetExternal<Value, ConstReference>::operator ConstReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

#endif  // CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_DETAIL_H