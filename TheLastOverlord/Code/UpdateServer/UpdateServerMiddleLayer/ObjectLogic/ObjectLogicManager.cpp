// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 19:01)

#include "UpdateServer/UpdateServerMiddleLayer/UpdateServerMiddleLayerExport.h"

#include "ObjectLogicManager.h" 
#include "UpdateServer/UpdateServerMiddleLayer/Macro/UpdateServerMiddleLayerClassInvariantMacro.h"

UpdateServerMiddleLayer::ObjectLogicManager
	::ObjectLogicManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	UPDATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

UpdateServerMiddleLayer::ObjectLogicManager
	::~ObjectLogicManager()
{
	UPDATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(UpdateServerMiddleLayer, ObjectLogicManager)

 


