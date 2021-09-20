//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/26 13:40)

#ifndef CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_DETAIL_H

#include "SimplePropertySetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
template <typename Value, typename Reference>
CoreTools::SimplePropertySetExternal<Value, Reference>::SimplePropertySetExternal(ValueType& value) noexcept
    : m_Value{ value }
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Value, typename Reference>
CoreTools::SimplePropertySetExternal<Value, Reference>& CoreTools::SimplePropertySetExternal<Value, Reference>::operator=(ReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Value = value;

    return *this;
}
#include STSTEM_WARNING_POP
#endif  // CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_DETAIL_H