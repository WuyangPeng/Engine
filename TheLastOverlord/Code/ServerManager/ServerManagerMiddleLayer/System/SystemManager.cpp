// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 16:53)

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

 


