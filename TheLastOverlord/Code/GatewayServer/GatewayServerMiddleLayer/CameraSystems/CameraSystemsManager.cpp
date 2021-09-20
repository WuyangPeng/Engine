// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 11:00)

#include "GatewayServer/GatewayServerMiddleLayer/GatewayServerMiddleLayerExport.h"

#include "CameraSystemsManager.h" 
#include "GatewayServer/GatewayServerMiddleLayer/Macro/GatewayServerMiddleLayerClassInvariantMacro.h"

GatewayServerMiddleLayer::CameraSystemsManager
	::CameraSystemsManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	GATEWAY_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

GatewayServerMiddleLayer::CameraSystemsManager
	::~CameraSystemsManager()
{
	GATEWAY_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GatewayServerMiddleLayer, CameraSystemsManager)

 


