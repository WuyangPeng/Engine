// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:09)

#include "BackgroundServer/BackgroundServerMiddleLayer/BackgroundServerMiddleLayerExport.h"

#include "CameraSystemsManager.h" 
#include "BackgroundServer/BackgroundServerMiddleLayer/Macro/BackgroundServerMiddleLayerClassInvariantMacro.h"

BackgroundServerMiddleLayer::CameraSystemsManager
	::CameraSystemsManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	BACKGROUND_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

BackgroundServerMiddleLayer::CameraSystemsManager
	::~CameraSystemsManager()
{
	BACKGROUND_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BackgroundServerMiddleLayer, CameraSystemsManager)

 


