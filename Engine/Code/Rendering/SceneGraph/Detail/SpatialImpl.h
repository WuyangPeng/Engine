/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/07 10:24)

#ifndef RENDERING_SCENE_GRAPH_SPATIAL_IMPL_H
#define RENDERING_SCENE_GRAPH_SPATIAL_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/BoundingSphere.h"
#include "Mathematics/Algebra/Transform.h"
#include "Rendering/SceneGraph/SceneGraphInternalFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SpatialImpl
    {
    public:
        using ClassType = SpatialImpl;
        using FactoryType = SpatialFactory;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

        using APoint = Mathematics::APointF;
        using Matrix = Mathematics::MatrixF;
        using Transform = Mathematics::TransformF;
        using BoundingSphere = Mathematics::BoundingSphereF;

        using SpatialSharedPtr = std::shared_ptr<Spatial>;
        using ConstSpatialSharedPtr = std::shared_ptr<const Spatial>;
        using SpatialWeakPtr = std::weak_ptr<Spatial>;

        using SpatialImplSharedPtr = std::shared_ptr<SpatialImpl>;

    public:
        explicit SpatialImpl(CullingMode cullingMode) noexcept;
        virtual ~SpatialImpl() noexcept = default;
        SpatialImpl(const SpatialImpl& rhs) = default;
        SpatialImpl& operator=(const SpatialImpl& rhs) = default;
        SpatialImpl(SpatialImpl&& rhs) noexcept = default;
        SpatialImpl& operator=(SpatialImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void SetWorldBound(const BoundingSphere& bound) noexcept;

        void DirectSetWorldTransform(const Transform& transform) noexcept;
        void DirectSetWorldBound(const BoundingSphere& bound) noexcept;

        void SetLocalTransform(const Transform& transform) noexcept;
        void SetCullingMode(CullingMode aCulling) noexcept;

        void SetLocalTransformTranslate(const APoint& translate) noexcept;
        void SetLocalTransformRotate(const Matrix& rotate) noexcept;

        void SetLocalTransformToWorldTransform(const Transform& aWorldTransform);
        void SetLocalTransformToWorldTransform() noexcept;

        void InitWorldBound();
        void GrowToContain(const BoundingSphere& aWorldBound);

        NODISCARD bool GetWorldTransformIsCurrent() const noexcept;
        NODISCARD bool GetWorldBoundIsCurrent() const noexcept;

        NODISCARD Transform GetLocalTransform() const noexcept;
        NODISCARD Transform GetWorldTransform() const noexcept;
        NODISCARD BoundingSphere GetWorldBound() const noexcept;
        NODISCARD CullingMode GetCullingMode() const noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        void SetWorldTransformOnUpdate(const Transform& transform) noexcept;

        virtual void SetParent(const SpatialSharedPtr& aParent) = 0;
        NODISCARD virtual SpatialSharedPtr GetParent() = 0;
        NODISCARD virtual ConstSpatialSharedPtr GetParent() const = 0;

        NODISCARD virtual SpatialImplSharedPtr Clone() const = 0;

    private:
        // 局部和世界变换。在某些情况下,您可能需要直接设置世界变换绕过Spatial::Update()机制。
        // 如果直接设置worldTransform，worldTransformIsCurrent应该设置为“true”。
        Transform localTransform;
        Transform worldTransform;
        bool worldTransformIsCurrent;

        // 世界绑定访问。在某些情况下,您可能想要直接设置世界绑定,绕过Spatial::Update()机制。
        // 如果直接设置worldBound，worldBoundIsCurrent应该设置为“true”。
        BoundingSphere worldBound;
        bool worldBoundIsCurrent;

        CullingMode culling;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SPATIAL_IMPL_H
