///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 20:50)

#include "Rendering/RenderingExport.h"

#include "OpenGLPixelShader.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::PdrPixelShader::PdrPixelShader(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const PixelShader* pshader) noexcept
    : ParentType{}, shader{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PdrPixelShader)

void Rendering::PdrPixelShader::Enable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const PixelShader* pshader, MAYBE_UNUSED const ShaderParameters* parameters) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::PdrPixelShader::Disable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const PixelShader* pshader, MAYBE_UNUSED const ShaderParameters* parameters) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}
