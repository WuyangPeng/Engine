/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.2.0 (2025/01/06 10:45)

#ifndef GAME_CLIENT_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H
#define GAME_CLIENT_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H

#include "GameClient/GameClientMiddleLayer/Helper/GameClientMiddleLayerClassInvariantMacro.h"
#include "InputManager.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"

template <typename ApplicationTrait>
GameClientMiddleLayer::InputManager<ApplicationTrait>::InputManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    GAME_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool GameClientMiddleLayer::InputManager<ApplicationTrait>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // GAME_CLIENT_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H
