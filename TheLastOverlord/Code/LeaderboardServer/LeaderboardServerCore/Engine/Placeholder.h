///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/26 21:14)

#ifndef LEADERBOARD_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define LEADERBOARD_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "LeaderboardServer/LeaderboardServerCore/LeaderboardServerCoreDll.h"

#include "LeaderboardServer/LeaderboardServerCore/Macro/ExportMacro.h"

namespace LeaderboardServerCore
{
    class LEADERBOARD_SERVER_CORE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // LEADERBOARD_SERVER_CORE_ENGINE_PLACEHOLDER_H
