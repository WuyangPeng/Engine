///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 11:20)

#include "Rendering/RenderingExport.h"

#include "GlutRendererInput.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <gsl/util>

Rendering::GlutRendererInput::GlutRendererInput() noexcept
    : ParentType{}, windowID{ 0 }, disableVerticalSync{ true }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GlutRendererInput)

void Rendering::GlutRendererInput::SetWindowID(int aWindowID) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    windowID = aWindowID;
}

void Rendering::GlutRendererInput::SetWindowHandle(HWnd aWindowID) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    SetWindowID(gsl::narrow_cast<int>(reinterpret_cast<size_t>(aWindowID)));

#include STSTEM_WARNING_POP
}

Rendering::RendererTypes Rendering::GlutRendererInput::GetRendererType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return RendererTypes::Glut;
}
