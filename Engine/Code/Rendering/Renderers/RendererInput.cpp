// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:29)

#include "Rendering/RenderingExport.h"

#include "RendererInput.h"
#include "RendererFactory.h"
#include "Detail/RendererInputImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RendererInput
	::RendererInput(RendererTypes type)
	:m_Impl{ RendererFactory::CreateInput(type) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,RendererInput)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, RendererInput,SetWindowID, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, RendererInput,SetWindowHandle, HWnd, void)