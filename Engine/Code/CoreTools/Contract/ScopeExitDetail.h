/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 16:05)

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
        /// 忽略所有异常
        /// 由于断言库使用这个类，这里不能调用日志库的函数记录错误日志。
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
