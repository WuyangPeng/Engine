// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 15:51)

#include "GameMasterServer/GameMasterServerMiddleLayer/GameMasterServerMiddleLayerExport.h"

#include "ResourceManager.h" 
#include "GameMasterServer/GameMasterServerMiddleLayer/Macro/GameMasterServerMiddleLayerClassInvariantMacro.h"

GameMasterServerMiddleLayer::ResourceManager
	::ResourceManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	GAME_MASTER_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

GameMasterServerMiddleLayer::ResourceManager
	::~ResourceManager()
{
	GAME_MASTER_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameMasterServerMiddleLayer, ResourceManager)

 


