///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:10)

#ifndef RENDERING_SCENE_GRAPH_SPATIAL_H
#define RENDERING_SCENE_GRAPH_SPATIAL_H

#include "Rendering/RenderingDll.h"

#include "PickRecordContainer.h"
#include "Flags/CullingModeFlags.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Mathematics/Algebra/BoundingSphere.h"
#include "Mathematics/Algebra/TransformDetail.h"
#include "Rendering/Controllers/ControlledObject.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Spatial, SpatialData);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Spatial : public ControlledObject
    {
    public:
        using SpatialImpl = SpatialData;
        COPY_UNSHARED_TYPE_DECLARE(Spatial);
        using ParentType = ControlledObject;
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        using Math = Mathematics::Math<float>;
        using AVector = Mathematics::AVector<float>;
        using APoint = Mathematics::APoint<float>;
        using Matrix = Mathematics::Matrix<float>;

    public:
        explicit Spatial(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Spatial);

        // 更新几何状态和控制器。
        // 函数计算世界转换在遍历向下传递场景图和遍历向上传递世界边界。
        bool Update(double applicationTime = -Mathematics::MathD::maxReal) override;

        // 访问父对象。节点中调用attach/detach在子对象。
        virtual void SetParent(Spatial* aParent) noexcept;

        NODISCARD bool Update(double applicationTime, bool initiator);

        // 访问父对象。
        NODISCARD Spatial* GetParent() noexcept;
        NODISCARD const Spatial* GetParent() const noexcept;

        // 支持分级裁剪。
        void OnGetVisibleSet(Culler& culler, bool noCull);
        virtual void GetVisibleSet(Culler& culler, bool noCull) = 0;

        void SetLocalTransform(const Mathematics::TransformF& transform) noexcept;
        void SetWorldTransform(const Mathematics::TransformF& transform) noexcept;
        void SetWorldBound(const Mathematics::BoundingSphereF& bound) noexcept;
        void SetCullingMode(CullingMode culling) noexcept;

        NODISCARD Mathematics::TransformF GetLocalTransform() const noexcept;
        NODISCARD Mathematics::TransformF GetWorldTransform() const noexcept;
        NODISCARD Mathematics::BoundingSphereF GetWorldBound() const noexcept;
        NODISCARD CullingMode GetCullingMode() const noexcept;

        void SetLocalTransformTranslate(const APoint& translate) noexcept;
        void SetLocalTransformRotate(const Matrix& rotate) noexcept;

        NODISCARD virtual PickRecordContainer ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const;

        virtual ControllerSharedPtr Clone() const = 0;

    protected:
        void InitWorldBound();
        void BoundGrowToContain(const Mathematics::BoundingSphereF& worldBound);

        // 对几何更新的支持。
        virtual bool UpdateWorldData(double applicationTime);

        NODISCARD bool GetWorldBoundIsCurrent() const noexcept;
        void SetWorldTransformOnUpdate(const Mathematics::TransformF& transform) noexcept;

    private:
        // 对几何更新的支持。
        virtual void UpdateWorldBound() = 0;
        void PropagateBoundToRoot();

    private:
        // 支持层次场景图。Spatial提供父指针。Node提供了子指针。
        Spatial* parent;

        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Spatial);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Spatial);
}

#endif  // RENDERING_SCENE_GRAPH_SPATIAL_H
