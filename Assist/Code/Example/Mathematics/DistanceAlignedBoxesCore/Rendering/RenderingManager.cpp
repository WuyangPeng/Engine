///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/26 17:48)

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreExport.h"

#include "RenderingManager.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Rendering/RendererEngine/BaseRenderer.h"

Framework::RenderingManagerInterface::MiddleLayerSharedPtr DistanceAlignedBoxes::RenderingManager::CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
{
    return std::make_shared<ClassType>(middleLayerPlatform, environmentDirectory);
}

DistanceAlignedBoxes::RenderingManager::RenderingManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DistanceAlignedBoxes, RenderingManager)

void DistanceAlignedBoxes::RenderingManager::SetRasterizerState(const RasterizerStateSharedPtr& noCullState)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    GetRenderer()->SetRasterizerState(noCullState);
}
