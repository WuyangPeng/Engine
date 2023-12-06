///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:07)

#ifndef RENDERING_SCENE_GRAPH_SPATIAL_DATA_H
#define RENDERING_SCENE_GRAPH_SPATIAL_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Transform.h"
#include "Mathematics/Algebra/BoundingSphere.h"
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
        using Bound = Mathematics::BoundingSphere<float>;

    public:
        SpatialData() noexcept;

        CLASS_INVARIANT_DECLARE;

        void DirectSetWorldTransform(const Mathematics::TransformF& transform) noexcept;
        void DirectSetWorldBound(const Bound& bound) noexcept;

        void SetLocalTransform(const Mathematics::TransformF& transform) noexcept;
        void SetCullingMode(CullingMode aCulling) noexcept;

        void SetLocalTransformTranslate(const APoint& translate) noexcept;
        void SetLocalTransformRotate(const Matrix& rotate) noexcept;

        void SetLocalTransformToWorldTransform(const Mathematics::TransformF& aWorldTransform);
        void SetLocalTransformToWorldTransform() noexcept;

        void InitWorldBound();
        void SetWorldBound(const Bound& aWorldBound);

        NODISCARD bool GetWorldTransformIsCurrent() const noexcept;
        NODISCARD bool GetWorldBoundIsCurrent() const noexcept;

        NODISCARD Mathematics::TransformF GetLocalTransform() const noexcept;
        NODISCARD Mathematics::TransformF GetWorldTransform() const noexcept;
        NODISCARD Bound GetWorldBound() const noexcept;
        NODISCARD CullingMode GetCullingMode() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        void SetWorldTransformOnUpdate(const Mathematics::TransformF& transform) noexcept;

    private:
        // �ֲ�������任����ĳЩ�����,��������Ҫֱ����������任�ƹ�Spatial::Update()���ơ�
        // ���ֱ������m_WorldTransform,m_WorldTransformIsCurrentӦ������Ϊ��true����
        Mathematics::TransformF localTransform;
        Mathematics::TransformF worldTransform;
        bool worldTransformIsCurrent;

        // ����󶨷��ʡ���ĳЩ�����,��������Ҫֱ�����������,�ƹ�Spatial::Update()���ơ�
        // ���ֱ������m_WorldBound,m_WorldBoundIsCurrentӦ������Ϊ��true����
        Bound worldBound;
        bool worldBoundIsCurrent;

        CullingMode culling;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SPATIAL_DATA_H
