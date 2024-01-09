/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 16:02)

#ifndef SYSTEM_THREADING_CONDITION_VARIABLE_H
#define SYSTEM_THREADING_CONDITION_VARIABLE_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ConditionVariableUsing.h"
#include "Using/CriticalSectionUsing.h"
#include "Using/SlimReaderWriterUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// ��������
namespace System
{
    void SYSTEM_DEFAULT_DECLARE InitializeSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SleepConditionVariableSlimReaderWriter(ConditionVariablePtr conditionVariable,
                                                                                 SlimReaderWriterLockPtr slimReaderWriterLock,
                                                                                 WindowsDWord milliseconds,
                                                                                 ConditionVariableLockMode flags) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SleepConditionVariableCriticalSection(ConditionVariablePtr conditionVariable,
                                                                                ThreadingCriticalSectionPtr criticalSection,
                                                                                WindowsDWord milliseconds) noexcept;
    void SYSTEM_DEFAULT_DECLARE WakeSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept;
    void SYSTEM_DEFAULT_DECLARE WakeAllSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept;
}

#endif  // SYSTEM_THREADING_CONDITION_VARIABLE_H