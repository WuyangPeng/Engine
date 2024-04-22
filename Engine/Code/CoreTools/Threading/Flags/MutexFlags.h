/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 18:02)

#ifndef CORE_TOOLS_THREADING_MUTEX_FLAGS_H
#define CORE_TOOLS_THREADING_MUTEX_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
    enum class MutexCreate
    {
        UseDefault,
        UseCriticalSection,
        UseStd,
        UseStdRecursive,
        UseBoost,
        UseBoostRecursive,
        UseNull,
        UseOriginalStd,
        UseOriginalStdRecursive,
    };
}

#endif  // CORE_TOOLS_THREADING_MUTEX_FLAGS_H
