// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 17:43)

#include "GameServer/GameServerMiddleLayer/GameServerMiddleLayerExport.h"

#include "RenderingManager.h" 
#include "GameServer/GameServerMiddleLayer/Macro/GameServerMiddleLayerClassInvariantMacro.h"

GameServerMiddleLayer::RenderingManager
	::RenderingManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	GAME_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

GameServerMiddleLayer::RenderingManager
	::~RenderingManager()
{
	GAME_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameServerMiddleLayer, RenderingManager)

 

