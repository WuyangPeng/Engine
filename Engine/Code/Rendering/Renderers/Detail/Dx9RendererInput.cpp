///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 11:07)

#include "Rendering/RenderingExport.h"

#include "Dx9RendererInput.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <gsl/util>

Rendering::Dx9RendererInput::Dx9RendererInput() noexcept
    : ParentType{}, windowHandle{ nullptr }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Dx9RendererInput)

void Rendering::Dx9RendererInput::SetWindowID(int windowID) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    SetWindowHandle(reinterpret_cast<HWnd>(gsl::narrow_cast<size_t>(windowID)));

#include STSTEM_WARNING_POP
}

void Rendering::Dx9RendererInput::SetWindowHandle(HWnd windowID) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    windowHandle = windowID;
}

Rendering::RendererTypes Rendering::Dx9RendererInput::GetRendererType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return RendererTypes::Dx11;
}
