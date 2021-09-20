// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 13:12)

#include "WorldServer/WorldServerMiddleLayer/WorldServerMiddleLayerExport.h"

#include "PhysicalModellingManager.h" 
#include "WorldServer/WorldServerMiddleLayer/Macro/WorldServerMiddleLayerClassInvariantMacro.h"

WorldServerMiddleLayer::PhysicalModellingManager
	::PhysicalModellingManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	WORLD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

WorldServerMiddleLayer::PhysicalModellingManager
	::~PhysicalModellingManager()
{
	WORLD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(WorldServerMiddleLayer, PhysicalModellingManager)

 


