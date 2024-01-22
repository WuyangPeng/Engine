/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:10)

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
