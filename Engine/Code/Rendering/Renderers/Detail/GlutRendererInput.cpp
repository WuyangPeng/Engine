// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 17:26)

#include "Rendering/RenderingExport.h"

#include "GlutRendererInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26490)
Rendering::GlutRendererInput ::GlutRendererInput() noexcept
    : ParentType{}, m_WindowID{ 0 }, m_DisableVerticalSync{ true }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

 


CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GlutRendererInput)
 
void Rendering:: GlutRendererInput
	::SetWindowID(int windowID) noexcept
{
	m_WindowID  = windowID;
}

void Rendering::GlutRendererInput ::SetWindowHandle(HWnd windowID) noexcept
{
	SetWindowID(static_cast<int>(reinterpret_cast<size_t>(windowID)));
}

Rendering::RendererTypes Rendering::GlutRendererInput ::GetRendererType() const noexcept
{
	return RendererTypes::Glut;
}

#include STSTEM_WARNING_POP