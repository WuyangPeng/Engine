///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 14:40)

#ifndef FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_DETAIL_H

#include "InputManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename ApplicationTrait>
Framework::InputManager<ApplicationTrait>::InputManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_DETAIL_H
