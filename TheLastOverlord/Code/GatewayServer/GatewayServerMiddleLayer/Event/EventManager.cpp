// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 11:01)

#include "GatewayServer/GatewayServerMiddleLayer/GatewayServerMiddleLayerExport.h"

#include "EventManager.h" 
#include "GatewayServer/GatewayServerMiddleLayer/Macro/GatewayServerMiddleLayerClassInvariantMacro.h"

GatewayServerMiddleLayer::EventManager
	::EventManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	GATEWAY_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

GatewayServerMiddleLayer::EventManager
	::~EventManager()
{
	GATEWAY_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GatewayServerMiddleLayer, EventManager)

 


