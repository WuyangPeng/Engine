///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:06)

#ifndef RENDERING_SCENE_GRAPH_CULLER_IMPL_H
#define RENDERING_SCENE_GRAPH_CULLER_IMPL_H

#include "CameraFrustum.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Plane.h"
#include "Rendering/RenderingDll.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/VisibleSet.h"
#include "Rendering/SceneGraph/Visual.h"

#include <boost/noncopyable.hpp>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CullerImpl : private boost::noncopyable
    {
    public:
        using ClassType = CullerImpl;
        using Plane = Mathematics::Plane<float>;
        using APoint = Mathematics::APoint<float>;
        using Math = Mathematics::Math<float>;
        using AVector = Mathematics::AVector<float>;
        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
        using VisualContainer = std::vector<VisualSharedPtr>;
        using VisualContainerIter = VisualContainer::iterator;

    public:
        // 裁剪需要相机模型。如果需要修改相机，
        // 你应该在使用ComputeVisibleSet之前，调用SetCamera。
        explicit CullerImpl(const ConstCameraSharedPtr& camera);

        CLASS_INVARIANT_DECLARE;

        // 访问相机，复制的平截头体和潜在可见集。
        void SetCamera(const ConstCameraSharedPtr& aCamera) noexcept;
        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;
        void SetFrustum(const float* aFrustum);
        NODISCARD const float* GetFrustum() const noexcept;

        // 基类的行为是可见的对象附加到可见集(存储为一个数组)。
        void Insert(const VisualSharedPtr& visible);

        NODISCARD int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        NODISCARD int GetPlaneQuantity() const noexcept;
        NODISCARD const Plane* GetPlanes() const noexcept;
        void SetPlaneState(int aPlaneState) noexcept;
        NODISCARD int GetPlaneState() const noexcept;
        void PushPlane(const Plane& aPlane) noexcept;
        void PopPlane() noexcept;

        // 比较对象的世界边界对立的裁剪平面。只有Spatial调用这个函数。
        NODISCARD bool IsVisible(const BoundF& bound) noexcept;

        // 支持在 Portal::GetVisibleSet.
        NODISCARD bool IsVisible(int numVertices, const APoint* vertices, bool ignoreNearPlane) const noexcept;

        // 支持在 BspNode::GetVisibleSet.
        // 确定视图平截头体是否完全在平面的一侧。
        // 平面的“正面”在半空间到平面法线的点。“负面”是另外一半空间。
        // 函数返回+1如果视图平截头体完全在平面的正面上,
        // 函数返回-1如果视图平截头体完全在平面的负面上，
        // 或者0，如果视图平截头体位于平面。
        // 输入平面在世界坐标系和世界相机坐标系用于测试。
        NODISCARD NumericalValueSymbol WhichSide(const Plane& aPlane) const noexcept;

        // 这是你应该使用的主要函数中使用的在场景图裁剪。
        // 遍历场景图,构建潜在可见集相对于世界平面。
        void Clear() noexcept;

        NODISCARD VisualContainerIter begin() noexcept;
        NODISCARD VisualContainerIter end() noexcept;

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
        std::array<Plane, MaxPlaneQuantity> plane;
        int planeState;

        // 可能可见设置调用GetVisibleSet。
        VisibleSet visibleSet;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CULLER_IMPL_H
