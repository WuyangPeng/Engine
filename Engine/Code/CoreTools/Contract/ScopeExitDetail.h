//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/10 14:12)

#ifndef CORE_TOOLS_CONTRACT_SCOPE_EXIT_DETAIL_H
#define CORE_TOOLS_CONTRACT_SCOPE_EXIT_DETAIL_H

#include "ScopeExit.h"
#include "System/Helper/PragmaWarning.h"
#include "System/SystemOutput/OutputDebugString.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
template <typename T>
CoreTools::ScopeExit<T>::ScopeExit(T function) noexcept
    : m_Function{ function }
{
}
#include STSTEM_WARNING_POP

template <typename T>
CoreTools::ScopeExit<T>::~ScopeExit() noexcept
{
    try
    {
        m_Function();
    }
    catch (...)
    {
        // 忽略所有异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("ScopeExit 析构抛出异常"));
    }
}

#endif  // CORE_TOOLS_CONTRACT_SCOPE_EXIT_DETAIL_H
