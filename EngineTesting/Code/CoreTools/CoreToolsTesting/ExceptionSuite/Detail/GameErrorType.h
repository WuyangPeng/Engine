///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/03/01 15:02)

#ifndef CORE_TOOLS_EXCEPTION_SUITE_GAME_ERROR_TYPE_H
#define CORE_TOOLS_EXCEPTION_SUITE_GAME_ERROR_TYPE_H

#include "CoreTools/Helper/UserMacro.h"

namespace CoreTools
{
    enum class GameErrorType
    {
        Info,
        Warn,
        Error,
    };
}

#endif  // CORE_TOOLS_EXCEPTION_SUITE_GAME_ERROR_TYPE_H
