/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 17:08)

#ifndef SYSTEM_THREADING_CONDITION_VARIABLE_USING_H
#define SYSTEM_THREADING_CONDITION_VARIABLE_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ConditionVariable = CONDITION_VARIABLE;
    using ConditionVariablePtr = PCONDITION_VARIABLE;

#else  // !SYSTEM_PLATFORM_WIN32

    struct ConditionVariable
    {
        void* Ptr;
    };
    using ConditionVariablePtr = ConditionVariable*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_CONDITION_VARIABLE_USING_H