// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 13:10)

#include "WorldServer/WorldServerMiddleLayer/WorldServerMiddleLayerExport.h"

#include "GUIManager.h" 
#include "WorldServer/WorldServerMiddleLayer/Macro/WorldServerMiddleLayerClassInvariantMacro.h"

WorldServerMiddleLayer::GUIManager
	::GUIManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	WORLD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

WorldServerMiddleLayer::GUIManager
	::~GUIManager()
{
	WORLD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(WorldServerMiddleLayer, GUIManager)

 


