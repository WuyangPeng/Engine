// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 14:49)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(TrianglePositionImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE TrianglePosition
	{
	public:
		PERFORMANCE_UNSHARED_TYPE_DECLARE(TrianglePosition);
		using APoint = Mathematics::APointF;
			
	public:		
		TrianglePosition(const APoint& firstPosition,const APoint& secondPosition,const APoint& thirdPosition);

		CLASS_INVARIANT_DECLARE;

		const APoint GetFirstPosition() const noexcept;
                const APoint GetSecondPosition() const noexcept;
                const APoint GetThirdPosition() const noexcept;

	private:
                PackageType impl;
	};	 
}

#endif // RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_H
