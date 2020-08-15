// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 17:27)

#include "Rendering/RenderingExport.h"

#include "OpenGLESRendererInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26472)
Rendering:: OpenGLESRendererInput
	:: OpenGLESRendererInput() noexcept
	:ParentType{}, m_WindowHandle{ nullptr }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

 


CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLESRendererInput)
 

void Rendering::OpenGLESRendererInput ::SetWindowID(int windowID) noexcept
{
	SetWindowHandle(reinterpret_cast<HWnd>(static_cast<size_t>(windowID)));

}

void Rendering:: OpenGLESRendererInput 
	::SetWindowHandle(HWnd windowID) noexcept
{ 
	m_WindowHandle  = windowID;
}

Rendering::RendererTypes Rendering::OpenGLESRendererInput ::GetRendererType() const noexcept
{
	return RendererTypes::OpenGLES;
}

#include STSTEM_WARNING_POP