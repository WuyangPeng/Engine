//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:34)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_DECREMENTER_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_DECREMENTER_DETAIL_H

#include "SimpleDecrementer.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::SimpleDecrementer<T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
void CoreTools::SimpleDecrementer<T>::operator()(T& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    --value;
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_DECREMENTER_DETAIL_H
