///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/04/25 13:58)

#ifndef SYSTEM_THREADING_CRITICAL_SECTION_H
#define SYSTEM_THREADING_CRITICAL_SECTION_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/CriticalSectionUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // 临界区

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