///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 16:00)

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
