// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 17:28)

#include "Rendering/RenderingExport.h"

#include "OpenGLRendererInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

    // The pixelFormat variable is used to support creation of a window that
    // supports multisampling.  This process requires creating a normal window,
    // and then querying whether the renderer supports multisampling.  The
    // renderer creates a device context for the window which we then need to
    // create a second window that supports multisampling.  The device context
    // rendererDC is set by the renderer during the process.
Rendering:: OpenGLRendererInput
	:: OpenGLRendererInput()
	:ParentType{}, m_WindowHandle{ nullptr }, m_RendererDC{ nullptr }, m_PixelFormat{ 0 }, m_DisableVerticalSync{ true }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering:: OpenGLRendererInput
	:: ~ OpenGLRendererInput()
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}


CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLRendererInput)
 

void Rendering:: OpenGLRendererInput
	::SetWindowID(int windowID)
{
	SetWindowHandle(reinterpret_cast<HWnd>(static_cast<size_t>(windowID)));
}

void Rendering:: OpenGLRendererInput
	::SetWindowHandle(HWnd windowID)
{
	m_WindowHandle  = windowID;
}

Rendering::RendererTypes Rendering:: OpenGLRendererInput
	::GetRendererType() const
{
	return RendererTypes::OpenGL;
}

