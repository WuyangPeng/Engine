// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 09:45)

#include "FightingServer/FightingServerMiddleLayer/FightingServerMiddleLayerExport.h"

#include "EventManager.h" 
#include "FightingServer/FightingServerMiddleLayer/Macro/FightingServerMiddleLayerClassInvariantMacro.h"

FightingServerMiddleLayer::EventManager
	::EventManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	FIGHTING_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

FightingServerMiddleLayer::EventManager
	::~EventManager()
{
	FIGHTING_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(FightingServerMiddleLayer, EventManager)

 


