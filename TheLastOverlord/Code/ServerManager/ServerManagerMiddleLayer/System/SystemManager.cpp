// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 16:53)

#include "ServerManager/ServerManagerMiddleLayer/ServerManagerMiddleLayerExport.h"

#include "SystemManager.h" 
#include "ServerManager/ServerManagerMiddleLayer/Macro/ServerManagerMiddleLayerClassInvariantMacro.h"

ServerManagerMiddleLayer::SystemManager
	::SystemManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

ServerManagerMiddleLayer::SystemManager
	::~SystemManager()
{
	SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ServerManagerMiddleLayer, SystemManager)

 


