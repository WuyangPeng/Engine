/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/07 10:27)

#ifndef RENDERING_SCENE_GRAPH_SPATIAL_H
#define RENDERING_SCENE_GRAPH_SPATIAL_H

#include "Rendering/RenderingDll.h"

#include "PickRecordContainer.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Mathematics/Algebra/BoundingSphere.h"
#include "Mathematics/Algebra/Transform.h"
#include "Rendering/Controllers/ControlledObject.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Spatial, SpatialImpl);

/// ֧�ֶ���Ŀռ��νṹ����Spatial��һ����ָ�롣
/// ��Spatial��������Node��һ����ָ�����顣
/// ��νṹ��Ҷ�ڵ�Ҫô��ͼ�εģ�Ҫô�������ġ�
/// ��Visual������Spatial����ʾͼ�����ݡ�
/// ��Audial������Spatial����ʾ�������ݡ�
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Spatial : public ControlledObject
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Spatial);
        using ParentType = ControlledObject;

        using Math = Mathematics::MathF;
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;
        using Matrix = Mathematics::MatrixF;
        using Transform = Mathematics::TransformF;
        using BoundingSphere = Mathematics::BoundingSphereF;

        using CameraSharedPtr = std::shared_ptr<Camera>;
        using SpatialSharedPtr = std::shared_ptr<Spatial>;
        using ConstSpatialSharedPtr = std::shared_ptr<const Spatial>;

    public:
        explicit Spatial(const std::string& name);
        Spatial(const std::string& name, bool isNull);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Spatial);

        /// ����״̬�ĸ��¡�
        /// �ú����ڳ���ͼ���������¹����м�������任���ڱ��������Ϲ����м�������߽������
        /// ���ø��µĶ������������������ڼ���ʵ�������������������
        /// Ӧ�ó���ʱ���Ժ���Ϊ��λ��
        NODISCARD bool Update(double applicationTime, bool initiator);

        // ���ʸ����󡣸ö�����ڲ�νṹ�ĸ�Ϊ�ն���
        NODISCARD SpatialSharedPtr GetParent();
        NODISCARD ConstSpatialSharedPtr GetParent() const;

        // ֧�ַּ��ü���
        void OnGetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull);
        virtual void GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) = 0;

        NODISCARD bool Update(double applicationTime = -Mathematics::MathD::maxReal) override;

        // ���ʸ����󡣽ڵ��е���attach/detach���Ӷ���
        void SetParent(const SpatialSharedPtr& parent);

        void SetLocalTransform(const Transform& transform) noexcept;
        void SetWorldTransform(const Transform& transform) noexcept;
        void SetWorldBound(const BoundingSphere& bound) noexcept;
        void SetCullingMode(CullingMode culling) noexcept;

        NODISCARD Transform GetLocalTransform() const noexcept;
        NODISCARD Transform GetWorldTransform() const noexcept;
        NODISCARD BoundingSphere GetWorldBound() const noexcept;
        NODISCARD CullingMode GetCullingMode() const noexcept;

        void SetLocalTransformTranslate(const APoint& translate) noexcept;
        void SetLocalTransformRotate(const Matrix& rotate) noexcept;

        NODISCARD virtual PickRecordContainer ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const;

        NODISCARD ControllerSharedPtr Clone() const override = 0;

        NODISCARD static const SpatialSharedPtr& GetNullObject();

    protected:
        void InitWorldBound();
        void BoundGrowToContain(const BoundingSphere& worldBound);

        // �Լ��θ��µ�֧�֡�
        virtual bool UpdateWorldData(double applicationTime);

        NODISCARD bool GetWorldBoundIsCurrent() const noexcept;
        void SetWorldTransformOnUpdate(const Transform& transform) noexcept;

    private:
        // �Լ��θ��µ�֧�֡�
        virtual void UpdateWorldBound() = 0;
        void PropagateBoundToRoot();

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Spatial);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Spatial);
}

#endif  // RENDERING_SCENE_GRAPH_SPATIAL_H
