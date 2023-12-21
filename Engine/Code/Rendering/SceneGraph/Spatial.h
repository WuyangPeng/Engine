/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/07 10:27)

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

/// 支持对象的空间层次结构。类Spatial有一个父指针。
/// 从Spatial派生的类Node有一个子指针数组。
/// 层次结构的叶节点要么是图形的，要么是听觉的。
/// 类Visual派生自Spatial，表示图形数据。
/// 类Audial派生自Spatial，表示声音数据。
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

        /// 几何状态的更新。
        /// 该函数在场景图遍历的向下过程中计算世界变换，在遍历的向上过程中计算世界边界体积。
        /// 调用更新的对象是启动器。更新期间访问的其他对象不是启动器。
        /// 应用程序时间以毫秒为单位。
        NODISCARD bool Update(double applicationTime, bool initiator);

        // 访问父对象。该对象对于层次结构的根为空对象。
        NODISCARD SpatialSharedPtr GetParent();
        NODISCARD ConstSpatialSharedPtr GetParent() const;

        // 支持分级裁剪。
        void OnGetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull);
        virtual void GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) = 0;

        NODISCARD bool Update(double applicationTime = -Mathematics::MathD::maxReal) override;

        // 访问父对象。节点中调用attach/detach在子对象。
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

        // 对几何更新的支持。
        virtual bool UpdateWorldData(double applicationTime);

        NODISCARD bool GetWorldBoundIsCurrent() const noexcept;
        void SetWorldTransformOnUpdate(const Transform& transform) noexcept;

    private:
        // 对几何更新的支持。
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
