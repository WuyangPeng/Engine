// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 18:10)

#include "RechargeServer/RechargeServerMiddleLayer/RechargeServerMiddleLayerExport.h"

#include "CameraSystemsManager.h" 
#include "RechargeServer/RechargeServerMiddleLayer/Macro/RechargeServerMiddleLayerClassInvariantMacro.h"

RechargeServerMiddleLayer::CameraSystemsManager
	::CameraSystemsManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	RECHARGE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

RechargeServerMiddleLayer::CameraSystemsManager
	::~CameraSystemsManager()
{
	RECHARGE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RechargeServerMiddleLayer, CameraSystemsManager)

 


