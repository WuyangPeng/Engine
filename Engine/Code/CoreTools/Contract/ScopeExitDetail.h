///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/02/23 13:35) 

#ifndef CORE_TOOLS_CONTRACT_SCOPE_EXIT_DETAIL_H
#define CORE_TOOLS_CONTRACT_SCOPE_EXIT_DETAIL_H

#include "ScopeExit.h" 
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::ScopeExit<T>::ScopeExit(T function) noexcept(noexcept(T()))
    : function{ function }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::ScopeExit<T>::~ScopeExit() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    try
    {
        function();
    }
    catch (...)
    {
        // 忽略所有异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("ScopeExit 析构抛出异常"));
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::ScopeExit<T>::IsValid() const noexcept
{
    return function != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // CORE_TOOLS_CONTRACT_SCOPE_EXIT_DETAIL_H
