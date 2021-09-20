// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 16:00)

#ifndef RENDERING_CURVES_SURFACES_SURFACE_PATCH_FRAME_H
#define RENDERING_CURVES_SURFACES_SURFACE_PATCH_FRAME_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(SurfacePatchFrameImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE SurfacePatchFrame  
	{
	public:
            PERFORMANCE_UNSHARED_TYPE_DECLARE(SurfacePatchFrame);
		using AVector = Mathematics::FloatAVector;
		using APoint = Mathematics::FloatAPoint;

	public:
		SurfacePatchFrame(const APoint& position, const AVector& tangent0, const AVector& tangent1, const  AVector& normal);	 

		CLASS_INVARIANT_DECLARE;

		const APoint GetPosition() const noexcept;
		const AVector GetTangent0() const noexcept;
		const AVector GetTangent1() const noexcept;
		const AVector GetNormal() const noexcept;

	private:
                PackageType impl;
	};

}

#endif // RENDERING_CURVES_SURFACES_SURFACE_PATCH_FRAME_H
