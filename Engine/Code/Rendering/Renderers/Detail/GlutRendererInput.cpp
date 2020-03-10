// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 17:26)

#include "Rendering/RenderingExport.h"

#include "GlutRendererInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering:: GlutRendererInput
	:: GlutRendererInput()
	:ParentType{}, m_WindowID{ 0 }, m_DisableVerticalSync{ true }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering:: GlutRendererInput
	:: ~GlutRendererInput()
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}


CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GlutRendererInput)
 
void Rendering:: GlutRendererInput
	::SetWindowID(int windowID)
{
	m_WindowID  = windowID;
}

void Rendering:: GlutRendererInput
	::SetWindowHandle(HWnd windowID)
{
	SetWindowID(static_cast<int>(reinterpret_cast<size_t>(windowID)));
}

Rendering::RendererTypes Rendering:: GlutRendererInput
	::GetRendererType() const
{
	return RendererTypes::Glut;
}

