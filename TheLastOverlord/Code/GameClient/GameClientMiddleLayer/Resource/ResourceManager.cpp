// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.2.0 (2020/01/09 22:44)

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerExport.h"

#include "ResourceManager.h" 
#include "GameClient/GameClientMiddleLayer/Macro/GameClientMiddleLayerClassInvariantMacro.h"

GameClientMiddleLayer::ResourceManager
	::ResourceManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	GAME_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

GameClientMiddleLayer::ResourceManager
	::~ResourceManager()
{
	GAME_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameClientMiddleLayer, ResourceManager)

 


