///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.2 (2021/08/30 16:57)

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
