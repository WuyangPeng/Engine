/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.2.0 (2025/01/06 10:41)

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerExport.h"

#include "GameClient/GameClientMiddleLayer/Helper/GameClientMiddleLayerClassInvariantMacro.h"
#include "SystemManager.h"

GameClientMiddleLayer::SystemManager::SystemManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    GAME_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameClientMiddleLayer, SystemManager)