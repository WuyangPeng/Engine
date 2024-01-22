/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 16:36)

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

        using RasterizerState = Rendering::RasterizerState;
        using RasterizerStateSharedPtr = std::shared_ptr<RasterizerState>;

    public:
        RenderingManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetRasterizerState(const RasterizerStateSharedPtr& noCullState);
    };
}

#endif  // DISTANCE_ALIGNED_BOXES_CORE_RENDERING_RENDERING_MANAGER_H
