/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#ifndef BACKGROUND_CLIENT_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H
#define BACKGROUND_CLIENT_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H

#include "BackgroundClient/BackgroundClientMiddleLayer/Helper/BackgroundClientMiddleLayerClassInvariantMacro.h"
#include "InputManager.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename ApplicationTrait>
BackgroundClientMiddleLayer::InputManager<ApplicationTrait>::InputManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    BACKGROUND_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool BackgroundClientMiddleLayer::InputManager<ApplicationTrait>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // BACKGROUND_CLIENT_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H
