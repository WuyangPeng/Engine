// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.2.0 (2020/01/09 22:38)

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerExport.h"

#include "ArtificialIntellegenceManager.h" 
#include "GameClient/GameClientMiddleLayer/Macro/GameClientMiddleLayerClassInvariantMacro.h"

GameClientMiddleLayer::ArtificialIntellegenceManager
	::ArtificialIntellegenceManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	GAME_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

GameClientMiddleLayer::ArtificialIntellegenceManager
	::~ArtificialIntellegenceManager()
{
	GAME_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameClientMiddleLayer, ArtificialIntellegenceManager)



