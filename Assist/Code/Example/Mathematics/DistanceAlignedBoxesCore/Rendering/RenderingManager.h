///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/26 17:48)

#ifndef DISTANCE_ALIGNED_BOXES_CORE_RENDERING_RENDERING_MANAGER_H
#define DISTANCE_ALIGNED_BOXES_CORE_RENDERING_RENDERING_MANAGER_H

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreDll.h"

#include "Rendering/State/StateFwd.h"
#include "Framework/MiddleLayer/RenderingManagerInterface.h"

namespace DistanceAlignedBoxes
{
    class DISTANCE_ALIGNED_BOXES_CORE_DEFAULT_DECLARE RenderingManager final : public Framework::RenderingManagerInterface
    {
    public:
        using ClassType = RenderingManager;
        using ParentType = RenderingManagerInterface;

        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using RasterizerState = Rendering::RasterizerState;
        using RasterizerStateSharedPtr = std::shared_ptr<RasterizerState>;

    public:
        NODISCARD static MiddleLayerSharedPtr CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        RenderingManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetRasterizerState(const RasterizerStateSharedPtr& noCullState);
    };
}

#endif  // DISTANCE_ALIGNED_BOXES_CORE_RENDERING_RENDERING_MANAGER_H
