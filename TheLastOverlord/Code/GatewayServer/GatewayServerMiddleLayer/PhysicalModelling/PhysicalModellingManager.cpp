///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/23 13:49)

#include "GatewayServer/GatewayServerMiddleLayer/GatewayServerMiddleLayerExport.h"

#include "GatewayServer/GatewayServerMiddleLayer/Macro/GatewayServerMiddleLayerClassInvariantMacro.h"
#include "PhysicalModellingManager.h"

GatewayServerMiddleLayer::PhysicalModellingManager::PhysicalModellingManager(Framework::MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }
{
    GATEWAY_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GatewayServerMiddleLayer, PhysicalModellingManager)
