/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 16:37)

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreExport.h"

#include "RenderingManager.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Rendering/RendererEngine/BaseRenderer.h"

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
