// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 16:52)

#include "ServerManager/ServerManagerMiddleLayer/ServerManagerMiddleLayerExport.h"

#include "PhysicalModellingManager.h" 
#include "ServerManager/ServerManagerMiddleLayer/Macro/ServerManagerMiddleLayerClassInvariantMacro.h"

ServerManagerMiddleLayer::PhysicalModellingManager
	::PhysicalModellingManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

ServerManagerMiddleLayer::PhysicalModellingManager
	::~PhysicalModellingManager()
{
	SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ServerManagerMiddleLayer, PhysicalModellingManager)

 


