// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 16:59)

#include "GameServer/GameServerMiddleLayer/GameServerMiddleLayerExport.h"

#include "AudioManager.h" 
#include "GameServer/GameServerMiddleLayer/Macro/GameServerMiddleLayerClassInvariantMacro.h"

GameServerMiddleLayer::AudioManager
 ::AudioManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	GAME_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

GameServerMiddleLayer::AudioManager
	::~AudioManager()
{
	GAME_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameServerMiddleLayer, AudioManager)

 


