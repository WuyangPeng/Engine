///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/19 13:44)

#ifndef RENDERING_SORTING_BSP_NODE_H
#define RENDERING_SORTING_BSP_NODE_H

#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Plane.h"
#include "Rendering/RenderingDll.h"
#include "Rendering/SceneGraph/Node.h"

namespace Rendering
{
    class BspNode : public Node
    {
    public:
        using ClassType = BspNode;
        using ParentType = Node;
        using BspNodeSharedPtr = std::shared_ptr<BspNode>;

    public:
        NODISCARD static BspNodeSharedPtr Create();

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BspNode);

    public:
        explicit BspNode(NodeCreate nodeCreate);
        explicit BspNode(const Mathematics::PlaneF& modelPlane);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD SpatialSharedPtr AttachPositiveChild(const SpatialSharedPtr& child);
        NODISCARD SpatialSharedPtr AttachCoplanarChild(const SpatialSharedPtr& child);
        NODISCARD SpatialSharedPtr AttachNegativeChild(const SpatialSharedPtr& child);
        NODISCARD SpatialSharedPtr DetachPositiveChild();
        NODISCARD SpatialSharedPtr DetachCoplanarChild();
        NODISCARD SpatialSharedPtr DetachNegativeChild();
        NODISCARD SpatialSharedPtr GetPositiveChild();
        NODISCARD SpatialSharedPtr GetCoplanarChild();
        NODISCARD SpatialSharedPtr GetNegativeChild();

        NODISCARD const Mathematics::PlaneF& GetWorldPlane() const noexcept;

        NODISCARD SpatialSharedPtr GetContainingNode(const Mathematics::APointF& point);
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        NODISCARD bool UpdateWorldData(double applicationTime) override;

        void GetVisibleSet(Culler& culler, bool noCull) override;

    private:
        Mathematics::PlaneF modelPlane;
        Mathematics::PlaneF worldPlane;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(BspNode);
}

#endif  // RENDERING_SORTING_BSP_NODE_H
