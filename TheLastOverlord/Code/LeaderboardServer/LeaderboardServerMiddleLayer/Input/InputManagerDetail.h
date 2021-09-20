// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 15:30)

#ifndef LEADERBOARD_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H
#define LEADERBOARD_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H

#include "InputManager.h" 
#include "LeaderboardServer/LeaderboardServerMiddleLayer/Macro/LeaderboardServerMiddleLayerClassInvariantMacro.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"

template <typename ApplicationTrait>
LeaderboardServerMiddleLayer::InputManager<ApplicationTrait>
	::InputManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	LEADERBOARD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

template <typename ApplicationTrait>
LeaderboardServerMiddleLayer::InputManager<ApplicationTrait>
	::~InputManager()
{
	LEADERBOARD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait>
bool LeaderboardServerMiddleLayer::InputManager<ApplicationTrait>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

#endif / /LEADERBOARD_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H
 