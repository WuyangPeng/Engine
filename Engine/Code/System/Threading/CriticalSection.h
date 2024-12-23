/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 17:13)

#ifndef SYSTEM_THREADING_CRITICAL_SECTION_H
#define SYSTEM_THREADING_CRITICAL_SECTION_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/CriticalSectionUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

/// �ٽ���
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE InitializeSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection, WindowsDWord spinCount, CriticalSectionInfo flags) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE InitializeSystemCriticalSectionAndSpinCount(ThreadingCriticalSectionPtr criticalSection, WindowsDWord spinCount) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE InitializeSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;

    void SYSTEM_DEFAULT_DECLARE DeleteSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;

    void SYSTEM_DEFAULT_DECLARE EnterSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;
    void SYSTEM_DEFAULT_DECLARE LeaveSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE TryEnterSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;

    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE SetSystemCriticalSectionSpinCount(ThreadingCriticalSectionPtr criticalSection, WindowsDWord spinCount) noexcept;
}

#endif  // SYSTEM_THREADING_CRITICAL_SECTION_H