// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 15:33)

#include "LeaderboardServer/LeaderboardServerMiddleLayer/LeaderboardServerMiddleLayerExport.h"

#include "SystemManager.h" 
#include "LeaderboardServer/LeaderboardServerMiddleLayer/Macro/LeaderboardServerMiddleLayerClassInvariantMacro.h"

LeaderboardServerMiddleLayer::SystemManager
	::SystemManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	LEADERBOARD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

LeaderboardServerMiddleLayer::SystemManager
	::~SystemManager()
{
	LEADERBOARD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LeaderboardServerMiddleLayer, SystemManager)

 


