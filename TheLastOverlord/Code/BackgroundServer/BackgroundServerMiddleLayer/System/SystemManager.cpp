// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 18:12)

#include "BackgroundServer/BackgroundServerMiddleLayer/BackgroundServerMiddleLayerExport.h"

#include "SystemManager.h" 
#include "BackgroundServer/BackgroundServerMiddleLayer/Macro/BackgroundServerMiddleLayerClassInvariantMacro.h"

BackgroundServerMiddleLayer::SystemManager
	::SystemManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	BACKGROUND_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

BackgroundServerMiddleLayer::SystemManager
	::~SystemManager()
{
	BACKGROUND_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BackgroundServerMiddleLayer, SystemManager)

 


