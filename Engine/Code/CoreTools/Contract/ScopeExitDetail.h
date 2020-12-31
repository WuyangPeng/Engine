//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/10 14:12)

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
        // ���������쳣
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("ScopeExit �����׳��쳣"));
    }
}

#endif  // CORE_TOOLS_CONTRACT_SCOPE_EXIT_DETAIL_H
