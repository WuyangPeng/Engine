//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 15:17)

#ifndef SYSTEM_THREADING_CONDITION_VARIABLE_H
#define SYSTEM_THREADING_CONDITION_VARIABLE_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ConditionVariableUsing.h"
#include "Using/CriticalSectionUsing.h"
#include "Using/SlimReaderWriterUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 条件变量

    void SYSTEM_DEFAULT_DECLARE InitializeSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SleepConditionVariableSlimReaderWriter(ConditionVariablePtr conditionVariable, SlimReaderWriterLockPtr slimReaderWriterLock,
                                                                                     WindowDWord milliseconds, ConditionVariableLockMode flags) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SleepConditionVariableCriticalSection(ConditionVariablePtr conditionVariable, ThreadingCriticalSectionPtr criticalSection, WindowDWord milliseconds) noexcept;
    void SYSTEM_DEFAULT_DECLARE WakeSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept;
    void SYSTEM_DEFAULT_DECLARE WakeAllSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept;
}

#endif  // SYSTEM_THREADING_CONDITION_VARIABLE_H