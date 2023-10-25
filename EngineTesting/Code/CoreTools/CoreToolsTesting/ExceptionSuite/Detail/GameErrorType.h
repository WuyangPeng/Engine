///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 17:29)

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
