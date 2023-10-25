///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:43)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_DETAIL_H

#include "SimpleIncrementer.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::SimpleIncrementer<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
void CoreTools::SimpleIncrementer<T>::operator()(T& value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ++value;
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_DETAIL_H
