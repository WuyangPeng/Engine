// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 09:50)

#include "FightingServer/FightingServerMiddleLayer/FightingServerMiddleLayerExport.h"

#include "RenderingManager.h" 
#include "FightingServer/FightingServerMiddleLayer/Macro/FightingServerMiddleLayerClassInvariantMacro.h"

FightingServerMiddleLayer::RenderingManager
	::RenderingManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	FIGHTING_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

FightingServerMiddleLayer::RenderingManager
	::~RenderingManager()
{
	FIGHTING_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(FightingServerMiddleLayer, RenderingManager)

 


