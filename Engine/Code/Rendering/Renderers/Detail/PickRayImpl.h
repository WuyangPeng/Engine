// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.3.0 (2020/03/27 10:01)

#ifndef RENDERING_RENDERERS_PICKRAY_IMPL_H
#define RENDERING_RENDERERS_PICKRAY_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h" 

#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"

#include <boost/noncopyable.hpp> 

namespace Rendering
{
	// 根据指定的左手屏幕坐标（x，y）并使用当前相机来计算光线。 
	// 输出的“原点”是相机位置，而“方向”是单位长度矢量。 
	// 两者都在世界坐标中。 如果（x，y）在当前视口中的则返回值为'true'。
	class RENDERING_HIDDEN_DECLARE PickRayImpl
	{
	public:
		using ClassType = PickRayImpl;

	public:
		PickRayImpl();
		PickRayImpl(bool result, const Mathematics::APointf& origin, const Mathematics::AVectorf& direction);
	
		CLASS_INVARIANT_DECLARE;

		bool IsResult() const noexcept;
		Mathematics::APointf GetOrigin() const;
		Mathematics::AVectorf GetDirection() const;

	private:
		bool m_Result;
		Mathematics::APointf m_Origin;
		Mathematics::AVectorf m_Direction;
	};
}

#endif // RENDERING_RENDERERS_PICKRAY_IMPL_H



