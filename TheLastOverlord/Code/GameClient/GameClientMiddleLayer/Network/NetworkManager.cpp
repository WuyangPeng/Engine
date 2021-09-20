// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.2.0 (2020/01/09 22:43)

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerExport.h"

#include "NetworkManager.h" 
#include "GameClient/GameClientMiddleLayer/Macro/GameClientMiddleLayerClassInvariantMacro.h"

GameClientMiddleLayer::NetworkManager
	::NetworkManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	GAME_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

GameClientMiddleLayer::NetworkManager
	::~NetworkManager()
{
	GAME_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameClientMiddleLayer, NetworkManager)

 


