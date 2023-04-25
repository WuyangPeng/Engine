///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 20:50)

#ifndef CORE_TOOLS_HELPER_SUITE_PROPERTIES_FRIEND_TEMPLATE_DETAIL_H
#define CORE_TOOLS_HELPER_SUITE_PROPERTIES_FRIEND_TEMPLATE_DETAIL_H

#include "PropertiesFriendTemplate.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::PropertiesFriendTemplate<T>::PropertiesFriendTemplate() noexcept
    : value{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::PropertiesFriendTemplate<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // CORE_TOOLS_HELPER_SUITE_PROPERTIES_FRIEND_TEMPLATE_DETAIL_H