//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 15:18)

#ifndef SYSTEM_THREADING_CRITICAL_SECTION_H
#define SYSTEM_THREADING_CRITICAL_SECTION_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/CriticalSectionUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 临界区

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE InitializeSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection, WindowDWord spinCount, CriticalSectionInfo flags) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE InitializeSystemCriticalSectionAndSpinCount(ThreadingCriticalSectionPtr criticalSection, WindowDWord spinCount) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE InitializeSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;
    void SYSTEM_DEFAULT_DECLARE DeleteSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;
    void SYSTEM_DEFAULT_DECLARE EnterSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;
    void SYSTEM_DEFAULT_DECLARE LeaveSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE TryEnterSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE SetSystemCriticalSectionSpinCount(ThreadingCriticalSectionPtr criticalSection, WindowDWord spinCount) noexcept;
}

#endif  // SYSTEM_THREADING_CRITICAL_SECTION_H