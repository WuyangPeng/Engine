///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/21 10:07)

#ifndef CORE_TOOLS_CONTRACT_SCOPE_EXIT_DETAIL_H
#define CORE_TOOLS_CONTRACT_SCOPE_EXIT_DETAIL_H

#include "ScopeExit.h"
#include "System/Helper/PragmaWarning.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::ScopeExit<T>::ScopeExit(T function) noexcept(noexcept(T()))
    : Function{ function }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::ScopeExit<T>::~ScopeExit() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    try
    {
        Function();
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
    return Function != nullptr;
}
#endif  // OPEN_CLASS_INVARIANT

#endif  // CORE_TOOLS_CONTRACT_SCOPE_EXIT_DETAIL_H
