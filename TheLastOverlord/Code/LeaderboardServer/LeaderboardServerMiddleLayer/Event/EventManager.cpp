// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 15:30)

#include "LeaderboardServer/LeaderboardServerMiddleLayer/LeaderboardServerMiddleLayerExport.h"

#include "EventManager.h" 
#include "LeaderboardServer/LeaderboardServerMiddleLayer/Macro/LeaderboardServerMiddleLayerClassInvariantMacro.h"

LeaderboardServerMiddleLayer::EventManager
	::EventManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	LEADERBOARD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

LeaderboardServerMiddleLayer::EventManager
	::~EventManager()
{
	LEADERBOARD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LeaderboardServerMiddleLayer, EventManager)

 


