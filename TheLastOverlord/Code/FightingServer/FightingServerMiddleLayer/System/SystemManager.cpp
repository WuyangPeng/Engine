///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/25 15:57)

#include "FightingServer/FightingServerMiddleLayer/FightingServerMiddleLayerExport.h"

#include "FightingServer/FightingServerMiddleLayer/Macro/FightingServerMiddleLayerClassInvariantMacro.h"
#include "SystemManager.h"

FightingServerMiddleLayer::SystemManager::SystemManager(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform,environmentDirectory }
{
    FIGHTING_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(FightingServerMiddleLayer, SystemManager)
