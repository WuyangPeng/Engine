///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.9.0.12 (2022/07/28 22:24)

#include "GameMasterServer/GameMasterServerMiddleLayer/GameMasterServerMiddleLayerExport.h"

#include "GameMasterServer/GameMasterServerMiddleLayer/Macro/GameMasterServerMiddleLayerClassInvariantMacro.h"
#include "MessageManager.h"

GameMasterServerMiddleLayer::MessageManager::MessageManager(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform,environmentDirectory }
{
    GAME_MASTER_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameMasterServerMiddleLayer, MessageManager)
