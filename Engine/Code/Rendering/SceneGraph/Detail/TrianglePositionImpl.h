// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 19:25)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_IMPL_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE TrianglePositionImpl
	{
	public:
		using ClassType = TrianglePositionImpl;
		using APoint = Mathematics::APointf;
			
	public:		
		TrianglePositionImpl(const APoint& firstPosition,const APoint& secondPosition,const APoint& thirdPosition);
		
		CLASS_INVARIANT_DECLARE;

		const APoint GetFirstPosition() const;
		const APoint GetSecondPosition() const;
		const APoint GetThirdPosition() const;

	private:
		APoint m_FirstPosition;
		APoint m_SecondPosition;
		APoint m_ThirdPosition;
	};	 
}

#endif // RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_IMPL_H
