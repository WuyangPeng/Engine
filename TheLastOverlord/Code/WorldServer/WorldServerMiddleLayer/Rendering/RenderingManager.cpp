// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 13:12)

#include "WorldServer/WorldServerMiddleLayer/WorldServerMiddleLayerExport.h"

#include "RenderingManager.h" 
#include "WorldServer/WorldServerMiddleLayer/Macro/WorldServerMiddleLayerClassInvariantMacro.h"

WorldServerMiddleLayer::RenderingManager
	::RenderingManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	WORLD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

WorldServerMiddleLayer::RenderingManager
	::~RenderingManager()
{
	WORLD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(WorldServerMiddleLayer, RenderingManager)

 


