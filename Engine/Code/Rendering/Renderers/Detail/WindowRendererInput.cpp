// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:12)

#include "Rendering/RenderingExport.h"

#include "WindowRendererInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26472)
Rendering:: WindowRendererInput
	:: WindowRendererInput() noexcept
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
	::SetWindowID(int windowID) noexcept
{
	SetWindowHandle(reinterpret_cast<HWnd>(static_cast<size_t>(windowID)));
}

void Rendering:: WindowRendererInput
	::SetWindowHandle(HWnd windowID) noexcept
{
	m_WindowHandle  = windowID;
}

Rendering::RendererTypes Rendering:: WindowRendererInput
	::GetRendererType() const noexcept
{
	return RendererTypes::Window;
}
#include STSTEM_WARNING_POP