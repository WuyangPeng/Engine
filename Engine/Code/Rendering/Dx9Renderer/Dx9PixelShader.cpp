///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:49)

#include "Rendering/RenderingExport.h"

#include "Dx9PixelShader.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::Dx9PixelShader::Dx9PixelShader(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const PixelShader* pshader) noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::Dx9PixelShader::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::Dx9PixelShader::Enable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const PixelShader* pshader, MAYBE_UNUSED const ShaderParameters* parameters) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::Dx9PixelShader::Disable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const PixelShader* pshader, MAYBE_UNUSED const ShaderParameters* parameters) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}
