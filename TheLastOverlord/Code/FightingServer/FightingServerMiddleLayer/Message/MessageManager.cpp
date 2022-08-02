///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/25 16:04)

#include "FightingServer/FightingServerMiddleLayer/FightingServerMiddleLayerExport.h"

#include "FightingServer/FightingServerMiddleLayer/Macro/FightingServerMiddleLayerClassInvariantMacro.h"
#include "MessageManager.h"

FightingServerMiddleLayer::MessageManager::MessageManager(Framework::MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }
{
    FIGHTING_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(FightingServerMiddleLayer, MessageManager)
