///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 17:01)

#ifndef RENDERING_SCENE_GRAPH_SPATIAL_DATA_H
#define RENDERING_SCENE_GRAPH_SPATIAL_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Rendering/DataTypes/Bound.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/SceneGraph/Flags/CullingModeFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SpatialData
    {
    public:
        using ClassType = SpatialData;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using APoint = Mathematics::APoint<float>;
        using Matrix = Mathematics::Matrix<float>;
        using Bound = Bound<float>;

    public:
        SpatialData() noexcept;

        CLASS_INVARIANT_DECLARE;

        void DirectSetWorldTransform(const TransformF& transform) noexcept;
        void DirectSetWorldBound(const Bound& bound) noexcept;

        void SetLocalTransform(const TransformF& transform) noexcept;
        void SetCullingMode(CullingMode aCulling) noexcept;

        void SetLocalTransformTranslate(const APoint& translate) noexcept;
        void SetLocalTransformRotate(const Matrix& rotate) noexcept;

        void SetLocalTransformToWorldTransform(const TransformF& aWorldTransform);
        void SetLocalTransformToWorldTransform() noexcept;

        void InitWorldBound();
        void SetWorldBound(const Bound& aWorldBound);

        NODISCARD bool GetWorldTransformIsCurrent() const noexcept;
        NODISCARD bool GetWorldBoundIsCurrent() const noexcept;

        NODISCARD TransformF GetLocalTransform() const noexcept;
        NODISCARD TransformF GetWorldTransform() const noexcept;
        NODISCARD Bound GetWorldBound() const noexcept;
        NODISCARD CullingMode GetCullingMode() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        void SetWorldTransformOnUpdate(const TransformF& transform) noexcept;

    private:
        // 局部和世界变换。在某些情况下,您可能需要直接设置世界变换绕过Spatial::Update()机制。
        // 如果直接设置m_WorldTransform,m_WorldTransformIsCurrent应该设置为“true”。
        TransformF localTransform;
        TransformF worldTransform;
        bool worldTransformIsCurrent;

        // 世界绑定访问。在某些情况下,您可能想要直接设置世界绑定,绕过Spatial::Update()机制。
        // 如果直接设置m_WorldBound,m_WorldBoundIsCurrent应该设置为“true”。
        Bound worldBound;
        bool worldBoundIsCurrent;

        CullingMode culling;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SPATIAL_DATA_H
