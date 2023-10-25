///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/26 18:02)

#ifndef DISTANCE_ALIGNED_BOXES_CORE_RENDERING_INPUT_MANAGER_DETAIL_H
#define DISTANCE_ALIGNED_BOXES_CORE_RENDERING_INPUT_MANAGER_DETAIL_H

#include "InputManager.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename ApplicationTrait>
DistanceAlignedBoxes::InputManager<ApplicationTrait>::InputManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool DistanceAlignedBoxes::InputManager<ApplicationTrait>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // DISTANCE_ALIGNED_BOXES_CORE_RENDERING_INPUT_MANAGER_DETAIL_H
