///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 16:35)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_DETAIL_H

#include "IncrementScope.h"
#include "SimpleDecrementerDetail.h"
#include "SimpleIncrementerDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T, typename Aquire, typename Release>
CoreTools::IncrementScope<T, Aquire, Release>::IncrementScope(Reference value) noexcept
    : value{ value }
{
    AquireType()(value);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T, typename Aquire, typename Release>
CoreTools::IncrementScope<T, Aquire, Release>::~IncrementScope()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    ReleaseType()(value);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, typename Aquire, typename Release>
bool CoreTools::IncrementScope<T, Aquire, Release>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_DETAIL_H
