///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/26 17:48)

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