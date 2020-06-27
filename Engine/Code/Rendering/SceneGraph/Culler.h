// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 11:20)

#ifndef RENDERING_SCENE_GRAPH_CULLER_H
#define RENDERING_SCENE_GRAPH_CULLER_H

#include "Rendering/RenderingDll.h"

#include "Camera.h"
#include "Spatial.h"
#include "VisibleSet.h"
#include "Mathematics/Algebra/Plane.h"
#include "Mathematics/Algebra/APoint.h"

#include <boost/noncopyable.hpp>


RENDERING_EXPORT_SHARED_PTR(CullerImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Culler: private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(Culler);
        using Plane = Mathematics::Plane<float>;
        using APoint = Mathematics::APoint<float>;
		using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
		using VisualContainer = std::vector<VisualSmartPointer>;
		using VisualContainerIter = VisualContainer::iterator;

    public:
        // 裁剪需要相机模型。如果需要修改相机，
        // 你应该在使用ComputeVisibleSet之前，调用SetCamera。
		explicit Culler(const ConstCameraSmartPointer& camera);
        
		CLASS_INVARIANT_DECLARE;

        // 访问相机，复制的平截头体和潜在可见集。
		void SetCamera(const ConstCameraSmartPointer& camera);
		ConstCameraSmartPointer GetCamera() const;
        void SetFrustum (const float* frustum);
        const float* GetFrustum () const; 

        // 基类的行为是可见的对象附加到可见集(存储为一个数组)。
        // 派生类可能会覆盖此行为。
        // 例如,数组排序数组可能保持最小化渲染状态改变或者
        // 也可能是/维护作为一个独特的门户系统的对象列表。
		virtual void Insert(const VisualSmartPointer& visible);

        int GetNumVisible () const;
		const ConstVisualSmartPointer GetVisible(int index) const;

        int GetPlaneQuantity () const;
        const Plane* GetPlanes () const;
        void SetPlaneState (unsigned int planeState);
        unsigned int GetPlaneState () const;
        void PushPlane (const Plane& plane);
        void PopPlane ();

        // 比较对象的世界边界对立的裁剪平面。只有Spatial调用这个函数。
        bool IsVisible (const Bound& bound);

        // 支持在 Portal::GetVisibleSet.
        bool IsVisible (int numVertices, const APoint* vertices,bool ignoreNearPlane) const;

        // 支持在 BspNode::GetVisibleSet.
        // 确定视图平截头体是否完全在平面的一侧。
        // 平面的“正面”在半空间到平面法线的点。“负面”是另外一半空间。
        // 函数返回+1如果视图平截头体完全在平面的正面上,
        // 函数返回-1如果视图平截头体完全在平面的负面上，
        // 或者0，如果视图平截头体位于平面。
        // 输入平面在世界坐标系和世界相机坐标系用于测试。
        NumericalValueSymbol WhichSide (const Plane& plane) const;
        
        // 这是你应该使用的主要函数中使用的在场景图裁剪。
        // 遍历场景图,构建潜在可见集相对于世界平面。
		void ComputeVisibleSet(SpatialSmartPointer& scene);

		VisualContainerIter begin();
		VisualContainerIter end();

    private:
        IMPL_TYPE_DECLARE(VisibleSet);
    };
}

#endif // RENDERING_SCENE_GRAPH_CULLER_H
