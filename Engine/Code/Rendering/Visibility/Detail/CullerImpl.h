/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 15:40)

#ifndef RENDERING_VISIBILITY_CULLER_IMPL_H
#define RENDERING_VISIBILITY_CULLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Plane.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Detail/CameraFrustum.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/Visibility/VisibleSet.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CullerImpl
    {
    public:
        using ClassType = CullerImpl;

        using Plane = Mathematics::PlaneF;
        using APoint = Mathematics::APointF;
        using Math = Mathematics::MathF;
        using AVector = Mathematics::AVectorF;
        using BoundingSphere = Mathematics::BoundingSphereF;

        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
        using VisualContainer = std::vector<VisualSharedPtr>;
        using VisualContainerIter = VisualContainer::iterator;

        static constexpr auto quantity = System::EnumCastUnderlying(ViewFrustum::Quantity);

        using Container = std::array<float, quantity>;

    public:
        // 裁剪需要相机模型。如果需要修改相机，
        // 你应该在使用ComputeVisibleSet之前，调用SetCamera。
        explicit CullerImpl(ConstCameraSharedPtr camera);
        ~CullerImpl() noexcept = default;
        CullerImpl(const CullerImpl& rhs);
        CullerImpl& operator=(const CullerImpl& rhs);
        CullerImpl(CullerImpl&& rhs) noexcept;
        CullerImpl& operator=(CullerImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 访问相机，复制的平截头体和潜在可见集。
        void SetCamera(const ConstCameraSharedPtr& aCamera) noexcept;
        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;
        void SetFrustum(const Container& aFrustum);
        NODISCARD Container GetFrustum() const noexcept;

        // 基类的行为是可见的对象附加到可见集(存储为一个数组)。
        void Insert(const VisualSharedPtr& visible);

        NODISCARD int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        NODISCARD int GetPlaneQuantity() const noexcept;
        NODISCARD Plane GetPlane(int index) const;
        void SetPlaneState(uint32_t aPlaneState) noexcept;
        NODISCARD uint32_t GetPlaneState() const noexcept;
        void PushPlane(const Plane& aPlane) noexcept;
        void PopPlane() noexcept;

        // 比较对象的世界边界对立的裁剪平面。只有Spatial调用这个函数。
        NODISCARD bool IsVisible(const BoundingSphere& bound) noexcept;

        /// 支持在 BspNode::GetVisibleSet.
        /// 确定视图平截头体是否完全在平面的一侧。
        /// 平面的“正面”在半空间到平面法线的点。“负面”是另外一半空间。
        /// 函数返回+1如果视图平截头体完全在平面的正面上,
        /// 函数返回-1如果视图平截头体完全在平面的负面上，
        /// 或者0，如果视图平截头体位于平面。
        /// 输入平面在世界坐标系和世界相机坐标系用于测试。
        NODISCARD NumericalValueSymbol WhichSide(const Plane& aPlane) const;

        // 这是你应该使用的主要函数中使用的在场景图裁剪。
        // 遍历场景图,构建潜在可见集相对于世界平面。
        void Clear();

        NODISCARD VisualContainerIter begin();
        NODISCARD VisualContainerIter end();

        void PushViewFrustumPlanes(const Camera& aCamera);

    private:
        using PlaneContainer = std::array<Plane, quantity>;

    private:
        // 输入相机信息,可能需要裁剪场景。
        ConstCameraSharedPtr camera;

        // 复制视图平截头体的输入相机。这允许各种子系统改变在裁剪的平截头体参数(例如,门户系统)而不影响相机,
        // 渲染器的初始状态是必要的。
        CameraFrustum frustum;

        // 世界裁剪平面对应视图平截头体加任何额外的用户定义的裁剪平面。
        // 成员m_PlaneState代表位标志在裁剪系统存储平面是否活跃。
        // 1意味着平面是活跃的,否则平面是不活跃的。
        // 一个活跃的平面相比,计算边界卷,而不是一个不活动的平面。这支持了一种有效的裁剪的层次结构。
        // 例如,如果一个节点的边界体积内的左平面视图平截头体,
        // 则设置左平面节点的不活跃的,因为子节点都自动在离开平面。
        int planeQuantity;
        PlaneContainer plane;
        uint32_t planeState;

        // 可能可见设置调用GetVisibleSet。
        VisibleSet visibleSet;
    };
}

#endif  // RENDERING_VISIBILITY_CULLER_IMPL_H
