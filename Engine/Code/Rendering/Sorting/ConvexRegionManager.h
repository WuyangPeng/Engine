///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/19 16:02)

#ifndef RENDERING_SORTING_CONVEX_REGION_MANAGER_H
#define RENDERING_SORTING_CONVEX_REGION_MANAGER_H

#include "Rendering/RenderingDll.h"

#include "BspNode.h"
#include "CRMCuller.h"
#include "ConvexRegion.h"

namespace Rendering
{
    class ConvexRegionManager : public BspNode
    {
    public:
        using ClassType = ConvexRegionManager;
        using ParentType = BspNode;
        using ConvexRegionManagerSharedPtr = std::shared_ptr<ConvexRegionManager>;

    public:
        NODISCARD static ConvexRegionManagerSharedPtr Create();

    private:
        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ConvexRegionManager);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    public:
        explicit ConvexRegionManager(NodeCreate nodeCreate);
        explicit ConvexRegionManager(const Mathematics::PlaneF& modelPlane);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        SpatialSharedPtr AttachOutside(SpatialSharedPtr outside);
        SpatialSharedPtr DetachOutside();
        SpatialSharedPtr GetOutside();

        ConvexRegionSharedPtr GetContainingRegion(const Mathematics::APointF& point);

    protected:
        void GetVisibleSet(Culler& culler, bool noCull) override;

    private:
        CRMCuller crmCuller;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(ConvexRegionManager);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ConvexRegionManager);
}

#endif  // RENDERING_SORTING_CONVEX_REGION_MANAGER_H
