// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 11:37)

#include "GatewayServer/GatewayServerMiddleLayer/GatewayServerMiddleLayerExport.h"

#include "MessageManager.h" 
#include "GatewayServer/GatewayServerMiddleLayer/Macro/GatewayServerMiddleLayerClassInvariantMacro.h"

GatewayServerMiddleLayer::MessageManager
	::MessageManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	GATEWAY_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

GatewayServerMiddleLayer::MessageManager
	::~MessageManager()
{
	GATEWAY_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GatewayServerMiddleLayer, MessageManager)

 


