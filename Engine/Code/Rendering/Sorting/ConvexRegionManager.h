///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:27)

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
        void GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) override;

    private:
        CRMCuller crmCuller;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(ConvexRegionManager);
}

#endif  // RENDERING_SORTING_CONVEX_REGION_MANAGER_H
