///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/26 17:48)

#ifndef DISTANCE_ALIGNED_BOXES_CORE_RESOURCE_RESOURCE_MANAGER_H
#define DISTANCE_ALIGNED_BOXES_CORE_RESOURCE_RESOURCE_MANAGER_H

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"

EXPORT_SHARED_PTR(DistanceAlignedBoxes, ResourceManagerImpl, DISTANCE_ALIGNED_BOXES_CORE_DEFAULT_DECLARE);
EXPORT_NON_COPY(DistanceAlignedBoxes, ResourceManagerImpl, DISTANCE_ALIGNED_BOXES_CORE_DEFAULT_DECLARE);

namespace DistanceAlignedBoxes
{
    class DISTANCE_ALIGNED_BOXES_CORE_DEFAULT_DECLARE ResourceManager final : public Framework::ResourceManagerInterface
    {
    public:
        NON_COPY_TYPE_DECLARE(ResourceManager);
        using ParentType = ResourceManagerInterface;

        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        ResourceManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Initialize() override;

    private:
        PackageType impl;
    };
}

#endif  // DISTANCE_ALIGNED_BOXES_CORE_RESOURCE_RESOURCE_MANAGER_H
