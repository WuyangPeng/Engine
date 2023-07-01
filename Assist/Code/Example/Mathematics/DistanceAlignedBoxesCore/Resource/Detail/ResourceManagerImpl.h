///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/26 18:13)

#ifndef FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_IMPL_H
#define FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_IMPL_H

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreDll.h"

#include "Rendering/State/StateFwd.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

namespace DistanceAlignedBoxes
{
    class DISTANCE_ALIGNED_BOXES_CORE_HIDDEN_DECLARE ResourceManagerImpl final
    {
    public:
        using ClassType = ResourceManagerImpl;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using RasterizerState = Rendering::RasterizerState;
        using RasterizerStateSharedPtr = std::shared_ptr<RasterizerState>;

    public:
        explicit ResourceManagerImpl(const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD RasterizerStateSharedPtr GetNoCullStater() noexcept;

    private:
        RasterizerStateSharedPtr noCullState;
        RasterizerStateSharedPtr noCullWireState;
    };
}

#endif  // FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_IMPL_H
