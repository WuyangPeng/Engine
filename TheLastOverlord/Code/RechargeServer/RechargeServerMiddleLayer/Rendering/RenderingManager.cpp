// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 18:18)

#include "RechargeServer/RechargeServerMiddleLayer/RechargeServerMiddleLayerExport.h"

#include "RenderingManager.h" 
#include "RechargeServer/RechargeServerMiddleLayer/Macro/RechargeServerMiddleLayerClassInvariantMacro.h"

RechargeServerMiddleLayer::RenderingManager
	::RenderingManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	RECHARGE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

RechargeServerMiddleLayer::RenderingManager
	::~RenderingManager()
{
	RECHARGE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RechargeServerMiddleLayer, RenderingManager)

 


