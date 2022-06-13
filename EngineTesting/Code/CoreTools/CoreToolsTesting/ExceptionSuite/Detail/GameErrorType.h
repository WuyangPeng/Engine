///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 13:38)

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
