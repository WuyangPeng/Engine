///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:58)

#ifndef RENDERING_CURVES_SURFACES_SURFACE_PATCH_FRAME_IMPL_H
#define RENDERING_CURVES_SURFACES_SURFACE_PATCH_FRAME_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SurfacePatchFrameImpl
    {
    public:
        using ClassType = SurfacePatchFrameImpl;
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;

    public:
        SurfacePatchFrameImpl(const APoint& position, const AVector& tangent0, const AVector& tangent1, const AVector& normal) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD APoint GetPosition() const noexcept;
        NODISCARD AVector GetTangent0() const noexcept;
        NODISCARD AVector GetTangent1() const noexcept;
        NODISCARD AVector GetNormal() const noexcept;

    private:
        APoint position;
        AVector tangent0;
        AVector tangent1;
        AVector normal;
    };
}

#endif  // RENDERING_CURVES_SURFACES_SURFACE_PATCH_FRAME_IMPL_H
