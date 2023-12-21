/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:26)

#include "GameServer/GameServerMiddleLayer/GameServerMiddleLayerExport.h"

#include "GameServer/GameServerMiddleLayer/Helper/GameServerMiddleLayerClassInvariantMacro.h"
#include "GUIManager.h"

GameServerMiddleLayer::GUIManager::GUIManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    GAME_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameServerMiddleLayer, GUIManager)
