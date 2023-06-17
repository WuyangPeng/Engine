///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/29 17:18)

#include "UpdateServer/UpdateServerMiddleLayer/UpdateServerMiddleLayerExport.h"

#include "EventManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/Macro/UpdateServerMiddleLayerClassInvariantMacro.h"

UpdateServerMiddleLayer::EventManager::EventManager(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform,environmentDirectory }
{
    UPDATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(UpdateServerMiddleLayer, EventManager)
