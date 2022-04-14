// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/22 11:45)

#ifndef RENDERING_SCENE_GRAPH_SPATIAL_H
#define RENDERING_SCENE_GRAPH_SPATIAL_H

#include "Rendering/RenderingDll.h"

#include "PickRecordContainer.h"
#include "Flags/CullingModeFlags.h"
#include "Rendering/Controllers/ControlledObject.h"
#include "Rendering/DataTypes/Bound.h"
#include "Rendering/DataTypes/TransformDetail.h"

namespace Rendering
{
    class SpatialData;
}

EXPORT_SHARED_PTR(Rendering, SpatialData, RENDERING_DEFAULT_DECLARE);

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
}
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class Culler;

    class RENDERING_DEFAULT_DECLARE Spatial : public ControlledObject
    {
    public:
        using ClassType = Spatial;
        using ParentType = ControlledObject;
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        using Math = Mathematics::Math<float>;
        using AVector = Mathematics::AVector<float>;
        using APoint = Mathematics::APoint<float>;
        using Matrix = Mathematics::Matrix<float>;

    public:
        Spatial();
        ~Spatial();

        Spatial(const Spatial& rhs);
        Spatial& operator=(const Spatial& rhs);
        Spatial(Spatial&& rhs) = default;
        Spatial& operator=(Spatial&& rhs) = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Spatial);

        // 更新几何状态和控制器。
        // 函数计算世界转换在遍历向下传递场景图和遍历向上传递世界边界。
        bool Update(double applicationTime = -Mathematics::MathD::maxReal) override;

        // 访问父对象。节点中调用attach/detach在子对象。
        virtual void SetParent(Spatial* parent) noexcept;

        bool Update(double applicationTime, bool initiator);

        // 访问父对象。
        Spatial* GetParent() noexcept;
        const Spatial* GetParent() const noexcept;

        // 支持分级裁剪。
        void OnGetVisibleSet(Culler& culler, bool noCull);
        virtual void GetVisibleSet(Culler& culler, bool noCull) = 0;

        void SetLocalTransform(const TransformF& transform) noexcept;
        void SetWorldTransform(const TransformF& transform) noexcept;
        void SetWorldBound(const BoundF& bound) noexcept;
        void SetCullingMode(CullingMode culling) noexcept;

        const TransformF GetLocalTransform() const noexcept;
        const TransformF GetWorldTransform() const noexcept;
        const BoundF GetWorldBound() const noexcept;
        CullingMode GetCullingMode() const noexcept;

        void SetLocalTransformTranslate(const APoint& translate) noexcept;
        void SetLocalTransformRotate(const Matrix& rotate) noexcept;

        virtual PickRecordContainer ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const;

    protected:
        void InitWorldBound();
        void BoundGrowToContain(const BoundF& worldBound);

        // 对几何更新的支持。
        virtual bool UpdateWorldData(double applicationTime);

        bool GetWorldBoundIsCurrent() const noexcept;
        void SetWorldTransformOnUpdate(const TransformF& transform) noexcept;

    private:
        using SpatialDataPtr = std::shared_ptr<SpatialData>;

    private:
        // 对几何更新的支持。
        virtual void UpdateWorldBound() = 0;
        void PropagateBoundToRoot();

    private:
        // 支持层次场景图。Spatial提供父指针。Node提供了子指针。
        Spatial* m_Parent;

        SpatialDataPtr m_SpatialDataPtr;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(Spatial);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE(Spatial);
}
#include STSTEM_WARNING_POP
#endif  // RENDERING_SCENE_GRAPH_SPATIAL_H
