// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/26 17:25)

#include "Rendering/RenderingExport.h"

#include "Dx9RendererInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

// Create the device for rendering.
Rendering::Dx9RendererInput
	::Dx9RendererInput()
	:ParentType{}, m_WindowHandle{ nullptr }, m_Driver(nullptr/*Direct3DCreate9(D3D_SDK_VERSION)*/)
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Dx9RendererInput
	::~Dx9RendererInput()
{
	if (m_Driver)
	{
		m_Driver->Release();

	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Dx9RendererInput)

void Rendering::Dx9RendererInput
	::SetWindowID(int windowID)
{
	SetWindowHandle(reinterpret_cast<HWnd>(static_cast<size_t>(windowID)));

}

void Rendering::Dx9RendererInput
	::SetWindowHandle(HWnd windowID)
{
	m_WindowHandle = windowID;
}

Rendering::RendererTypes Rendering::Dx9RendererInput
	::GetRendererType() const
{
	return RendererTypes::Dx9;
}

