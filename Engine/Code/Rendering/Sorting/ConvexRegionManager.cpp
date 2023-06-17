///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:28)

#include "Rendering/RenderingExport.h"

#include "ConvexRegionManager.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ConvexRegionManager);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ConvexRegionManager);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ConvexRegionManager);

Rendering::ConvexRegionManager::ConvexRegionManager(LoadConstructor value)
    : ParentType{ value }, crmCuller{ nullptr }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ConvexRegionManager::ConvexRegionManagerSharedPtr Rendering::ConvexRegionManager::Create()
{
    return std::make_shared<ClassType>(NodeCreate::Init);
}

Rendering::ConvexRegionManager::ConvexRegionManager(NodeCreate nodeCreate)
    : ParentType{ nodeCreate }, crmCuller{ nullptr }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ConvexRegionManager::ConvexRegionManager(const Mathematics::PlaneF& modelPlane)
    : ParentType{ modelPlane }, crmCuller{ nullptr }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ConvexRegionManager)

Rendering::SpatialSharedPtr Rendering::ConvexRegionManager::AttachOutside(SpatialSharedPtr outside)
{
    RENDERING_CLASS_IS_VALID_1;

    AttachChild(outside);

    return outside;
}

Rendering::SpatialSharedPtr Rendering::ConvexRegionManager::DetachOutside()
{
    RENDERING_CLASS_IS_VALID_1;

    return DetachChildAt(1);
}

Rendering::SpatialSharedPtr Rendering::ConvexRegionManager::GetOutside()
{
    RENDERING_CLASS_IS_VALID_1;

    return GetChild(1);
}

Rendering::ConvexRegionSharedPtr Rendering::ConvexRegionManager::GetContainingRegion(const Mathematics::APointF& point)
{
    RENDERING_CLASS_IS_VALID_1;

    return boost::polymorphic_pointer_cast<ConvexRegion>(GetContainingNode(point));
}

void Rendering::ConvexRegionManager::GetVisibleSet(Culler& culler, bool noCull)
{
    RENDERING_CLASS_IS_VALID_1;

    auto region = GetContainingRegion(culler.GetCamera()->GetPosition());

    if (region)
    {
        crmCuller.SetCamera(culler.GetCamera());
        crmCuller.SetFrustum(culler.GetFrustum());
        crmCuller.ComputeVisibleSet(region);

        for (auto& value : crmCuller)
        {
            culler.Insert(value);
        }
    }
    else
    {
        if (GetOutside())
        {
            GetOutside()->GetVisibleSet(culler, noCull);
        }
    }
}
