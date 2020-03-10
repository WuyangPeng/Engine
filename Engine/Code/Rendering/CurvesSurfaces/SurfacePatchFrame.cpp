// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 17:56)

#include "Rendering/RenderingExport.h"

#include "SurfacePatchFrame.h"
#include "Detail/SurfacePatchFrameImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
 

Rendering::SurfacePatchFrame
	::SurfacePatchFrame(const APoint& position, const AVector& tangent0,
			            const AVector& tangent1, const  AVector& normal )
	:m_Impl(new ImplType(position,tangent0,tangent1,normal))
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, SurfacePatchFrame)
#endif // OPEN_CLASS_INVARIANT

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SurfacePatchFrame,GetPosition, const Rendering::SurfacePatchFrame::APoint)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SurfacePatchFrame,GetTangent0,const Rendering::SurfacePatchFrame::AVector)
 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SurfacePatchFrame,GetTangent1,const Rendering::SurfacePatchFrame::AVector)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SurfacePatchFrame,GetNormal,const Rendering::SurfacePatchFrame::AVector)