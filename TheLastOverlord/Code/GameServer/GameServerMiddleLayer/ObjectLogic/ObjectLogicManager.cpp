// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 17:43)

#include "GameServer/GameServerMiddleLayer/GameServerMiddleLayerExport.h"

#include "ObjectLogicManager.h" 
#include "GameServer/GameServerMiddleLayer/Macro/GameServerMiddleLayerClassInvariantMacro.h"

GameServerMiddleLayer::ObjectLogicManager
	::ObjectLogicManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	GAME_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

GameServerMiddleLayer::ObjectLogicManager
	::~ObjectLogicManager()
{
	GAME_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameServerMiddleLayer, ObjectLogicManager)

 


