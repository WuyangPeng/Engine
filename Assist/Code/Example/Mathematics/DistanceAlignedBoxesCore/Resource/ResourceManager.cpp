///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/26 17:48)

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreExport.h"

#include "ResourceManager.h"
#include "Detail/ResourceManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Example/Mathematics/DistanceAlignedBoxesCore/Rendering/RenderingManager.h"

DistanceAlignedBoxes::ResourceManager::ResourceManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ environmentDirectory }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DistanceAlignedBoxes, ResourceManager)

bool DistanceAlignedBoxes::ResourceManager::Initialize()
{
    if (ResourceManagerInterface::Initialize())
    {
        const auto rendering = GetRenderingManager<RenderingManager>();

        rendering->SetRasterizerState(impl->GetNoCullStater());

        return true;
    }

    return false;
}
