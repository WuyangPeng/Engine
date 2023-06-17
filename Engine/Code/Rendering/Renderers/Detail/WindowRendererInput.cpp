///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:45)

#include "Rendering/RenderingExport.h"

#include "WindowRendererInput.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <gsl/util>

Rendering::WindowRendererInput::WindowRendererInput() noexcept
    : ParentType{}, windowHandle{ nullptr }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, WindowRendererInput)

void Rendering::WindowRendererInput::SetWindowID(int windowID) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    SetWindowHandle(reinterpret_cast<HWnd>(gsl::narrow_cast<size_t>(windowID)));

#include STSTEM_WARNING_POP
}

void Rendering::WindowRendererInput::SetWindowHandle(HWnd windowID) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    windowHandle = windowID;
}

Rendering::RendererTypes Rendering::WindowRendererInput::GetRendererType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return RendererTypes::Windows;
}
