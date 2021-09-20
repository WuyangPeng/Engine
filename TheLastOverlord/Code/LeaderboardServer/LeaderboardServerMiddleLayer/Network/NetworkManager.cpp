// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 15:31)

#include "LeaderboardServer/LeaderboardServerMiddleLayer/LeaderboardServerMiddleLayerExport.h"

#include "NetworkManager.h" 
#include "LeaderboardServer/LeaderboardServerMiddleLayer/Macro/LeaderboardServerMiddleLayerClassInvariantMacro.h"

LeaderboardServerMiddleLayer::NetworkManager
	::NetworkManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	LEADERBOARD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

LeaderboardServerMiddleLayer::NetworkManager
	::~NetworkManager()
{
	LEADERBOARD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LeaderboardServerMiddleLayer, NetworkManager)

 


