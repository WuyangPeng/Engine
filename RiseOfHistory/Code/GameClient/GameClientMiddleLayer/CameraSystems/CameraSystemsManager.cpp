///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	��ʷ������汾��0.8.1.0 (2022/08/03 11:24)

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerExport.h"

#include "CameraSystemsManager.h"
#include "GameClient/GameClientMiddleLayer/Helper/GameClientMiddleLayerClassInvariantMacro.h"

GameClientMiddleLayer::CameraSystemsManager::CameraSystemsManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    GAME_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameClientMiddleLayer, CameraSystemsManager)
