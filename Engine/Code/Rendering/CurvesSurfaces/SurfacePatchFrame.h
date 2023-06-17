///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:59)

#ifndef RENDERING_CURVES_SURFACES_SURFACE_PATCH_FRAME_H
#define RENDERING_CURVES_SURFACES_SURFACE_PATCH_FRAME_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(SurfacePatchFrameImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SurfacePatchFrame
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(SurfacePatchFrame);
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;

    public:
        SurfacePatchFrame(const APoint& position, const AVector& tangent0, const AVector& tangent1, const AVector& normal);

        CLASS_INVARIANT_DECLARE;

        NODISCARD APoint GetPosition() const noexcept;
        NODISCARD AVector GetTangent0() const noexcept;
        NODISCARD AVector GetTangent1() const noexcept;
        NODISCARD AVector GetNormal() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_CURVES_SURFACES_SURFACE_PATCH_FRAME_H
