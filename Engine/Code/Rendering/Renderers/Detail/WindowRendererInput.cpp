// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:12)

#include "Rendering/RenderingExport.h"

#include "WindowRendererInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering:: WindowRendererInput
	:: WindowRendererInput()
	:ParentType{}, m_WindowHandle{ nullptr }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering:: WindowRendererInput
	:: ~ WindowRendererInput()
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, WindowRendererInput)


void Rendering:: WindowRendererInput
	::SetWindowID(int windowID)
{
	SetWindowHandle(reinterpret_cast<HWnd>(static_cast<size_t>(windowID)));
}

void Rendering:: WindowRendererInput
	::SetWindowHandle(HWnd windowID)
{
	m_WindowHandle  = windowID;
}

Rendering::RendererTypes Rendering:: WindowRendererInput
	::GetRendererType() const
{
	return RendererTypes::Window;
}

