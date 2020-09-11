// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:51)

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
        using AVector = Mathematics::FloatAVector;
        using APoint = Mathematics::FloatAPoint;

    public:
        SurfacePatchFrameImpl(const APoint& position, const AVector& tangent0, const AVector& tangent1, const AVector& normal) noexcept;

        CLASS_INVARIANT_DECLARE;

        const APoint GetPosition() const noexcept;
        const AVector GetTangent0() const noexcept;
        const AVector GetTangent1() const noexcept;
        const AVector GetNormal() const noexcept;

    private:
        APoint m_Position;
        AVector m_Tangent0;
        AVector m_Tangent1;
        AVector m_Normal;
    };
}

#endif  // RENDERING_CURVES_SURFACES_SURFACE_PATCH_FRAME_IMPL_H
