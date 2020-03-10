// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 14:49)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "CoreTools/Helper/ExportMacro.h"

RENDERING_EXPORT_SHARED_PTR(TrianglePositionImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE TrianglePosition
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(TrianglePosition);
		using APoint = Mathematics::APointf;
			
	public:		
		TrianglePosition(const APoint& firstPosition,const APoint& secondPosition,const APoint& thirdPosition);

		CLASS_INVARIANT_DECLARE;

		const APoint GetFirstPosition() const;
		const APoint GetSecondPosition() const;
		const APoint GetThirdPosition() const;

	private:
		IMPL_TYPE_DECLARE(TrianglePosition);
	};	 
}

#endif // RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_H
