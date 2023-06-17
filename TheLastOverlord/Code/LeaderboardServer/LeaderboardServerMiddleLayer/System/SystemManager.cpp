///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/26 21:20)

#include "LeaderboardServer/LeaderboardServerMiddleLayer/LeaderboardServerMiddleLayerExport.h"

#include "LeaderboardServer/LeaderboardServerMiddleLayer/Macro/LeaderboardServerMiddleLayerClassInvariantMacro.h"
#include "SystemManager.h"

LeaderboardServerMiddleLayer::SystemManager::SystemManager(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform,environmentDirectory }
{
    LEADERBOARD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LeaderboardServerMiddleLayer, SystemManager)
