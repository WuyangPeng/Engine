// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.3.0 (2020/03/27 10:01)

#include "Rendering/RenderingExport.h" 

#include "PickRay.h"
#include "Detail/PickRayImpl.h"  
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::PickRay
	::PickRay(bool result, const Mathematics::APointf& origin, const Mathematics::AVectorf& direction)
	:m_Impl{ make_shared<ImplType>(result,origin,direction) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PickRay
	::PickRay()
	:m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, PickRay)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRay, IsResult, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PickRay, GetOrigin, Mathematics::APointf)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PickRay, GetDirection, Mathematics::AVectorf) 