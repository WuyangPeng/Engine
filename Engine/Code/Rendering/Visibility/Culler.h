/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 16:09)

#ifndef RENDERING_VISIBILITY_CULLER_H
#define RENDERING_VISIBILITY_CULLER_H

#include "Rendering/RenderingDll.h"

#include "VisibleSet.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Plane.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"
#include "Rendering/SceneGraph/Visual.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(Culler, CullerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Culler
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(Culler);

        using Plane = Mathematics::PlaneF;
        using APoint = Mathematics::APointF;
        using BoundingSphere = Mathematics::BoundingSphereF;

        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
        using VisualContainer = std::vector<VisualSharedPtr>;
        using VisualContainerIter = VisualContainer::iterator;

        static constexpr auto quantity = System::EnumCastUnderlying(ViewFrustum::Quantity);

        using Container = std::array<float, quantity>;

    public:
        // 裁剪需要相机模型。如果需要修改相机，
        // 你应该在使用ComputeVisibleSet之前，调用SetCamera。
        explicit Culler(const ConstCameraSharedPtr& camera);
        virtual ~Culler() noexcept = default;
        Culler(const Culler& rhs) = default;
        Culler& operator=(const Culler& rhs) = default;
        Culler(Culler&& rhs) noexcept = default;
        Culler& operator=(Culler&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 访问相机，复制的平截头体和潜在可见集。
        void SetCamera(const ConstCameraSharedPtr& camera);
        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;
        void SetFrustum(const Container& frustum);
        NODISCARD Container GetFrustum() const noexcept;

        // 基类的行为是可见的对象附加到可见集(存储为一个数组)。
        // 派生类可能会覆盖此行为。
        // 例如,数组排序数组可能保持最小化渲染状态改变或者
        // 也可能是/维护作为一个独特的门户系统的对象列表。
        virtual void Insert(const VisualSharedPtr& visible);

        NODISCARD int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        NODISCARD int GetPlaneQuantity() const noexcept;
        NODISCARD Plane GetPlane(int index) const;
        void SetPlaneState(uint32_t planeState);
        NODISCARD uint32_t GetPlaneState() const noexcept;
        void PushPlane(const Plane& plane);
        void PopPlane();

        // 比较对象的世界边界对立的裁剪平面。只有Spatial调用这个函数。
        NODISCARD bool IsVisible(const BoundingSphere& bound);

        /// 支持在 BspNode::GetVisibleSet.
        /// 确定视图平截头体是否完全在平面的一侧。
        /// 平面的“正面”在半空间到平面法线的点。“负面”是另外一半空间。
        /// 函数返回+1如果视图平截头体完全在平面的正面上,
        /// 函数返回-1如果视图平截头体完全在平面的负面上，
        /// 或者0，如果视图平截头体位于平面。
        /// 输入平面在世界坐标系和世界相机坐标系用于测试。
        NODISCARD NumericalValueSymbol WhichSide(const Plane& plane) const;

        /// 这是你应该使用的主要函数中使用的在场景图裁剪。
        /// 遍历场景图,构建潜在可见集相对于世界平面。
        void ComputeVisibleSet(const CameraSharedPtr& camera, const SpatialSharedPtr& scene);

        NODISCARD VisualContainerIter begin();
        NODISCARD VisualContainerIter end();

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_VISIBILITY_CULLER_H
