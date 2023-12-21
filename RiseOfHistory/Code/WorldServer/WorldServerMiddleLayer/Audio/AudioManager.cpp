/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#include "WorldServer/WorldServerMiddleLayer/WorldServerMiddleLayerExport.h"

#include "WorldServer/WorldServerMiddleLayer/Helper/WorldServerMiddleLayerClassInvariantMacro.h"
#include "AudioManager.h"

WorldServerMiddleLayer::AudioManager::AudioManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    WORLD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(WorldServerMiddleLayer, AudioManager)
