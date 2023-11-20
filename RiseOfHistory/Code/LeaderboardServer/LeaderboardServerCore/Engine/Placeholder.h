/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/19 00:20)

#ifndef LEADERBOARD_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define LEADERBOARD_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "LeaderboardServer/LeaderboardServerCore/LeaderboardServerCoreDll.h"

#include "LeaderboardServer/LeaderboardServerCore/Helper/ExportMacro.h"

namespace LeaderboardServerCore
{
    class LEADERBOARD_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // LEADERBOARD_SERVER_CORE_ENGINE_PLACEHOLDER_H