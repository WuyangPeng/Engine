/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:45)

#include "RechargeServer/RechargeServerMiddleLayer/RechargeServerMiddleLayerExport.h"

#include "RechargeServer/RechargeServerMiddleLayer/Helper/RechargeServerMiddleLayerClassInvariantMacro.h"
#include "RenderingManager.h"

RechargeServerMiddleLayer::RenderingManager::RenderingManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    RECHARGE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RechargeServerMiddleLayer, RenderingManager)
