///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 11:18)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_DETAIL_H

#include "IncrementScope.h"
#include "SimpleDecrementerDetail.h"
#include "SimpleIncrementerDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T, typename Aquire, typename Release>
CoreTools::IncrementScope<T, Aquire, Release>::IncrementScope(Reference value) noexcept
    : vaule{ value }
{
    AquireType()(vaule);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T, typename Aquire, typename Release>
CoreTools::IncrementScope<T, Aquire, Release>::~IncrementScope()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    ReleaseType()(vaule);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, typename Aquire, typename Release>
bool CoreTools::IncrementScope<T, Aquire, Release>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_DETAIL_H
