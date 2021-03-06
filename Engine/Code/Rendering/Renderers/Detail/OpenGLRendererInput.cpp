// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 17:28)

#include "Rendering/RenderingExport.h"

#include "OpenGLRendererInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26472)
    // The pixelFormat variable is used to support creation of a window that
    // supports multisampling.  This process requires creating a normal window,
    // and then querying whether the renderer supports multisampling.  The
    // renderer creates a device context for the window which we then need to
    // create a second window that supports multisampling.  The device context
    // rendererDC is set by the renderer during the process.
Rendering:: OpenGLRendererInput
	:: OpenGLRendererInput() noexcept
	:ParentType{}, m_WindowHandle{ nullptr }, m_RendererDC{ nullptr }, m_PixelFormat{ 0 }, m_DisableVerticalSync{ true }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLRendererInput)
 

void Rendering::OpenGLRendererInput ::SetWindowID(int windowID) noexcept
{
	SetWindowHandle(reinterpret_cast<HWnd>(static_cast<size_t>(windowID)));
}

void Rendering::OpenGLRendererInput ::SetWindowHandle(HWnd windowID) noexcept
{
	m_WindowHandle  = windowID;
}

Rendering::RendererTypes Rendering::OpenGLRendererInput ::GetRendererType() const noexcept
{
	return RendererTypes::OpenGL;
}

#include STSTEM_WARNING_POP