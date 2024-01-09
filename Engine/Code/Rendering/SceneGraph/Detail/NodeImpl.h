/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:42)

#ifndef RENDERING_SCENE_GRAPH_NODE_IMPL_H
#define RENDERING_SCENE_GRAPH_NODE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/BoundingSphere.h"
#include "Rendering/SceneGraph/Spatial.h"
#include "Rendering/Visibility/Culler.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE NodeImpl
    {
    public:
        using ClassType = NodeImpl;

        using Object = CoreTools::Object;
        using ObjectLink = CoreTools::ObjectLink;
        using ObjectRegister = CoreTools::ObjectRegister;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;
        using BoundingSphere = Mathematics::BoundingSphereF;

    public:
        NodeImpl() noexcept;
        ~NodeImpl() noexcept;
        NodeImpl(NodeImpl&& rhs) = default;
        NodeImpl& operator=(NodeImpl&& rhs) = default;
        NodeImpl(const NodeImpl& rhs) noexcept = default;
        NodeImpl& operator=(const NodeImpl& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        NODISCARD int GetNumChildren() const;
        NODISCARD int AttachChild(const SpatialSharedPtr& child, const SpatialSharedPtr& self);
        NODISCARD int DetachChild(const SpatialSharedPtr& child);
        NODISCARD SpatialSharedPtr DetachChildAt(int index);
        void DetachAllChildren();
        NODISCARD SpatialSharedPtr SetChild(int index, const SpatialSharedPtr& child, const SpatialSharedPtr& self);
        NODISCARD SpatialSharedPtr GetChild(int index);
        NODISCARD ConstSpatialSharedPtr GetConstChild(int index) const;

        NODISCARD bool UpdateWorldData(double applicationTime);
        NODISCARD BoundingSphere GetWorldBound() const;

        void GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull);

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;
        void Register(ObjectRegister& target) const;
        void Link(ObjectLink& source);

        void Clear() noexcept;

        NODISCARD PickRecordContainer ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax, int numThreads, float maxDistance) const;

    private:
        using ObjectAssociated = CoreTools::ObjectAssociated<Spatial>;
        using SpatialContainer = std::vector<ObjectAssociated>;

    private:
        NODISCARD int GetFirstNullIndex() const noexcept;

    private:
        // 子节点指针。
        SpatialContainer spatialChild;
    };
}

#endif  // RENDERING_SCENE_GRAPH_NODE_IMPL_H
