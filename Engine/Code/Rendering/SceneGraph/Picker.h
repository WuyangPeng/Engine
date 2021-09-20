// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 11:32)

#ifndef RENDERING_SCENE_GRAPH_PICKER_H
#define RENDERING_SCENE_GRAPH_PICKER_H

#include "Rendering/RenderingDll.h" 

#include "Spatial.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(Picker,PickerImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE Picker
	{
	public:
            DELAY_COPY_UNSHARED_TYPE_DECLARE(Picker);
		using APoint = Mathematics::APoint<float>;
		using AVector = Mathematics::AVector<float>;

	public:
		Picker(const ConstSpatialSharedPtr& scene, const APoint& origin, const AVector& direction, float tMin, float tMax);

		CLASS_INVARIANT_DECLARE;

		bool IsRecordsExist() const noexcept;
		
		// 以下三个函数返回满足约束的记录。
		// 他们应该在0 < m_Records.GetSize()时调用。

		// 定位记录中最小绝对值的T值。
		const PickRecord GetClosestToZero() const;

		// 定位记录最接近零的与非负值的T值。
		const PickRecord GetClosestNonnegative() const;

		// 定位记录最接近零的与非正值的T值。
		const PickRecord GetClosestNonpositive() const;

	private:
                PackageType impl;
	};
}

#endif // RENDERING_SCENE_GRAPH_PICKER_H
