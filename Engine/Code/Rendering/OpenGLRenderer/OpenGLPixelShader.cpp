///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:22)

#include "Rendering/RenderingExport.h"

#include "OpenGLPixelShader.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::PdrPixelShader::PdrPixelShader(MAYBE_UNUSED BaseRenderer* renderer) noexcept
    : ParentType{}, shader{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PdrPixelShader)

void Rendering::PdrPixelShader::Enable(MAYBE_UNUSED BaseRenderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::PdrPixelShader::Disable(MAYBE_UNUSED BaseRenderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}
