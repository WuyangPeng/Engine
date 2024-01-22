/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 16:37)

#ifndef FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_IMPL_H
#define FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_IMPL_H

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreDll.h"

#include "Mathematics/Algebra/AxesAlignBoundingBox3.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/State/StateFwd.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

namespace DistanceAlignedBoxes
{
    class DISTANCE_ALIGNED_BOXES_CORE_HIDDEN_DECLARE ResourceManagerImpl final
    {
    public:
        using ClassType = ResourceManagerImpl;

        using AxesAlignBoundingBox3 = Mathematics::AxesAlignBoundingBox3F;
        using Visual = Rendering::Visual;
        using BlendState = Rendering::BlendState;
        using RasterizerState = Rendering::RasterizerState;
        using ConstantColorEffect = Rendering::ConstantColorEffect;
        using VisualSharedPtr = Rendering::VisualSharedPtr;
        using BlendStateSharedPtr = Rendering::BlendStateSharedPtr;
        using RasterizerStateSharedPtr = Rendering::RasterizerStateSharedPtr;
        using ConstantColorEffectSharedPtr = Rendering::ConstantColorEffectSharedPtr;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        explicit ResourceManagerImpl(const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD RasterizerStateSharedPtr GetNoCullStater() noexcept;

    private:
        RasterizerStateSharedPtr noCullState;
        RasterizerStateSharedPtr noCullWireState;
        BlendStateSharedPtr blendState;
        VisualSharedPtr box0Mesh;
        VisualSharedPtr box1Mesh;
        ConstantColorEffectSharedPtr redEffect;
        ConstantColorEffectSharedPtr blueEffect;
        VisualSharedPtr sgment;
        VisualSharedPtr point0;
        VisualSharedPtr point1;
        AxesAlignBoundingBox3 box0;
        AxesAlignBoundingBox3 box1;
    };
}

#endif  // FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_IMPL_H
