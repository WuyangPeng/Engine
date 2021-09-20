// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 18:27)

#include "Rendering/RenderingExport.h"

#include "TrianglePosition.h"
#include "Detail/TrianglePositionImpl.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::TrianglePosition
	::TrianglePosition(const APoint& firstPosition,const APoint& secondPosition, const APoint& thirdPosition)
	:impl{ firstPosition,secondPosition,thirdPosition }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,TrianglePosition)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TrianglePosition, GetFirstPosition, const Rendering::TrianglePosition::APoint)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TrianglePosition, GetSecondPosition, const Rendering::TrianglePosition::APoint)
									
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TrianglePosition, GetThirdPosition, const Rendering::TrianglePosition::APoint)