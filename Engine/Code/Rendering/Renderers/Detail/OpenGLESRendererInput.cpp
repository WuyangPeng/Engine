// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 17:27)

#include "Rendering/RenderingExport.h"

#include "OpenGLESRendererInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering:: OpenGLESRendererInput
	:: OpenGLESRendererInput()
	:ParentType{}, m_WindowHandle{ nullptr }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering:: OpenGLESRendererInput
	:: ~ OpenGLESRendererInput()
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}


CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLESRendererInput)
 

void Rendering:: OpenGLESRendererInput
	::SetWindowID(int windowID)
{
	SetWindowHandle(reinterpret_cast<HWnd>(static_cast<size_t>(windowID)));

}

void Rendering:: OpenGLESRendererInput
	::SetWindowHandle(HWnd windowID)
{
	m_WindowHandle  = windowID;
}

Rendering::RendererTypes Rendering:: OpenGLESRendererInput
	::GetRendererType() const
{
	return RendererTypes::OpenGLES;
}

