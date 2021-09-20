// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 17:00)

#include "GameServer/GameServerMiddleLayer/GameServerMiddleLayerExport.h"

#include "CameraSystemsManager.h" 
#include "GameServer/GameServerMiddleLayer/Macro/GameServerMiddleLayerClassInvariantMacro.h"

GameServerMiddleLayer::CameraSystemsManager
	::CameraSystemsManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	GAME_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

GameServerMiddleLayer::CameraSystemsManager
	::~CameraSystemsManager()
{
	GAME_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameServerMiddleLayer, CameraSystemsManager)

 


