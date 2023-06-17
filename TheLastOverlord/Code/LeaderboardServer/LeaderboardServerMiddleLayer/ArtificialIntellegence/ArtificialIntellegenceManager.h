///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/26 21:26)

#ifndef LEADERBOARD_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
#define LEADERBOARD_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H

#include "LeaderboardServer/LeaderboardServerMiddleLayer/LeaderboardServerMiddleLayerDll.h"

#include "LeaderboardServer/LeaderboardServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/ArtificialIntellegenceInterface.h"

namespace LeaderboardServerMiddleLayer
{
    class LEADERBOARD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ArtificialIntellegenceManager : public Framework::ArtificialIntellegenceInterface
    {
    public:
        using ClassType = ArtificialIntellegenceManager;
        using ParentType = Framework::ArtificialIntellegenceInterface;

    public:
        explicit ArtificialIntellegenceManager(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // LEADERBOARD_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
