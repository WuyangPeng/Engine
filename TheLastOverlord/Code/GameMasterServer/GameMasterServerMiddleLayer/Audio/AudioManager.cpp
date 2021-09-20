// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 15:47)

#include "GameMasterServer/GameMasterServerMiddleLayer/GameMasterServerMiddleLayerExport.h"

#include "AudioManager.h" 
#include "GameMasterServer/GameMasterServerMiddleLayer/Macro/GameMasterServerMiddleLayerClassInvariantMacro.h"

GameMasterServerMiddleLayer::AudioManager
 ::AudioManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	GAME_MASTER_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

GameMasterServerMiddleLayer::AudioManager
	::~AudioManager()
{
	GAME_MASTER_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameMasterServerMiddleLayer, AudioManager)

 


