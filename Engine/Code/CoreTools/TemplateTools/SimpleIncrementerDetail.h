///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 11:33)

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
