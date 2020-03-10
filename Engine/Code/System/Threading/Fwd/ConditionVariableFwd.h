// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:09)

#ifndef SYSTEM_THREADING_CONDITION_VARIABLE_FWD_H 
#define SYSTEM_THREADING_CONDITION_VARIABLE_FWD_H  

#include "ThreadingFlagsFwd.h"
#include "System/Threading/Using/ConditionVariableUsing.h" 

namespace System
{
	void InitializeSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept;
	bool SleepConditionVariableSlimReaderWriter(ConditionVariablePtr conditionVariable, SlimReaderWriterLockPtr slimReaderWriterLock,
												WindowDWord milliseconds, ConditionVariableLockMode flags) noexcept;
	bool SleepConditionVariableCriticalSection(ConditionVariablePtr conditionVariable, ThreadingCriticalSectionPtr criticalSection, WindowDWord milliseconds) noexcept;
	void WakeSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept;
	void WakeAllSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept;
}

#endif // SYSTEM_THREADING_CONDITION_VARIABLE_FWD_H