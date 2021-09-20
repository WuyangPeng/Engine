// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 17:56)

#include "Rendering/RenderingExport.h"

#include "SurfacePatchFrame.h"
#include "Detail/SurfacePatchFrameImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::SurfacePatchFrame ::SurfacePatchFrame(const APoint& position, const AVector& tangent0,
                                                 const AVector& tangent1, const AVector& normal)
    : impl(position, tangent0, tangent1, normal)
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SurfacePatchFrame)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatchFrame, GetPosition, const Rendering::SurfacePatchFrame::APoint)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatchFrame, GetTangent0, const Rendering::SurfacePatchFrame::AVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatchFrame, GetTangent1, const Rendering::SurfacePatchFrame::AVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatchFrame, GetNormal, const Rendering::SurfacePatchFrame::AVector)