/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/12/17 20:09)

#include "PlayerServer/PlayerServerMiddleLayer/PlayerServerMiddleLayerExport.h"

#include "PlayerServer/PlayerServerMiddleLayer/Helper/PlayerServerMiddleLayerClassInvariantMacro.h"
#include "ArtificialIntelligenceManager.h"

PlayerServerMiddleLayer::ArtificialIntelligenceManager::ArtificialIntelligenceManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    PLAYER_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(PlayerServerMiddleLayer, ArtificialIntelligenceManager)