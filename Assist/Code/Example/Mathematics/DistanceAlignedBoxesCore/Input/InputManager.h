///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/26 18:02)

#ifndef DISTANCE_ALIGNED_BOXES_CORE_RENDERING_INPUT_MANAGER_H
#define DISTANCE_ALIGNED_BOXES_CORE_RENDERING_INPUT_MANAGER_H

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreDll.h"

#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/InputManager.h"

namespace DistanceAlignedBoxes
{
    template <typename ApplicationTrait>
    class InputManager : public Framework::InputManager<ApplicationTrait>
    {
    public:
        using ClassType = InputManager<ApplicationTrait>;
        using ParentType = Framework::InputManager<ApplicationTrait>;

        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        InputManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // DISTANCE_ALIGNED_BOXES_CORE_RENDERING_INPUT_MANAGER_H