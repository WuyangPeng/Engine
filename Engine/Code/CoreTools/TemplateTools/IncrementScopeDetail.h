//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:33)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_DETAIL_H

#include "IncrementScope.h"
#include "SimpleDecrementerDetail.h"
#include "SimpleIncrementerDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T, typename Aquire, typename Release>
CoreTools::IncrementScope<T, Aquire, Release>::IncrementScope(Reference value)
    : m_Vaule{ value }
{
    AquireType()(m_Vaule);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T, typename Aquire, typename Release>
CoreTools::IncrementScope<T, Aquire, Release>::~IncrementScope()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    ReleaseType()(m_Vaule);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T, typename Aquire, typename Release>
bool CoreTools::IncrementScope<T, Aquire, Release>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_DETAIL_H
