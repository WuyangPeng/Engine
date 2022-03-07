// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.3.0 (2020/03/27 10:01)

#include "Rendering/RenderingExport.h" 

#include "PickRay.h"
#include "Detail/PickRayImpl.h"  
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
using std::make_shared;
#include "System/Helper/PragmaWarning.h" 
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Rendering::PickRay
	::PickRay(bool result, const Mathematics::APointF& origin, const Mathematics::AVectorF& direction)
	:impl{ result,origin,direction }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PickRay
	::PickRay()
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRay)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRay, IsResult, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRay, GetOrigin, Mathematics::APointF)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRay, GetDirection, Mathematics::AVectorF) 

#include STSTEM_WARNING_POP