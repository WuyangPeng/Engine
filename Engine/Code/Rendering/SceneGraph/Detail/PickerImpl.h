// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 19:22)

#ifndef RENDERING_SCENE_GRAPH_PICKER_IMPL_H
#define RENDERING_SCENE_GRAPH_PICKER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Spatial.h"
#include "Rendering/SceneGraph/PickRecordContainer.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE PickerImpl
	{
	public:
		using ClassType = PickerImpl;
		using APoint = Mathematics::APoint<float>;
		using AVector = Mathematics::AVector<float>;

	public:
		// 线性参数化的成分是P + t * D，
		// P是一个点的成分(P是原点),D是一个单位长度方向,
		// t是一个在区间[tmin,tmax]的标量，其中 tmin < tmax。
		// P和D值必须在世界坐标。tmin和tmax的选择如下
		// 直线:  tmin = -Mathf::sm_MaxReal, tmax = Mathf::sm_MaxReal
		// 射线:  tmin = 0, tmax = Mathematics::Mathf::sm_MaxReal
		// 线段:  tmin = 0, tmax > 0;
		PickerImpl(const ConstSpatialSharedPtr& scene, const APoint& origin,const AVector& direction, float tMin, float tMax);

		CLASS_INVARIANT_DECLARE;

		bool IsRecordsExist() const noexcept;
		
		// 以下三个函数返回满足约束的记录。
		// 他们应该在0 < m_Records.GetSize()时调用。

		// 定位记录中最小绝对值的T值。
		const PickRecord GetClosestToZero () const;
		
		// 定位记录最接近零的与非负值的T值。
		const PickRecord GetClosestNonnegative () const;
		
		// 定位记录最接近零的与非正值的T值。
		const PickRecord GetClosestNonpositive () const;    
		
	private:
		// 选择发生递归遍历的输入场景。
		void ExecuteRecursive(const ConstSpatialSharedPtr& object);
		
		APoint m_Origin;
		AVector m_Direction;
		float m_TMin;
		float m_TMax;
		
		// 访问所有的记录在选择操作。
		PickRecordContainer m_Records;
	};
}

#endif // RENDERING_SCENE_GRAPH_PICKER_IMPL_H
