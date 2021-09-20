// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:11)

#include "BackgroundServer/BackgroundServerMiddleLayer/BackgroundServerMiddleLayerExport.h"

#include "PhysicalModellingManager.h" 
#include "BackgroundServer/BackgroundServerMiddleLayer/Macro/BackgroundServerMiddleLayerClassInvariantMacro.h"

BackgroundServerMiddleLayer::PhysicalModellingManager
	::PhysicalModellingManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	BACKGROUND_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

BackgroundServerMiddleLayer::PhysicalModellingManager
	::~PhysicalModellingManager()
{
	BACKGROUND_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BackgroundServerMiddleLayer, PhysicalModellingManager)

 


