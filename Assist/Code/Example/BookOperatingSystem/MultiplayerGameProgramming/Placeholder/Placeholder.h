///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.0 (2021/07/18 18:43)

#ifndef MULTIPLAYER_GAME_PROGRAMMING_PLACEHOLDER_H
#define MULTIPLAYER_GAME_PROGRAMMING_PLACEHOLDER_H

#include "Example/BookOperatingSystem/MultiplayerGameProgramming/MultiplayerGameProgrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace MultiplayerGameProgramming
{
    class MULTIPLAYER_GAME_PROGRAMMING_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // MULTIPLAYER_GAME_PROGRAMMING_PLACEHOLDER_H
