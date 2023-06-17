///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:50)

#include "Rendering/RenderingExport.h"

#include "Dx9VertexShader.h"
#include "CoreTools/Contract/Noexcept.h"

using namespace Rendering;

Dx9VertexShader::Dx9VertexShader(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const VertexShader* vshader) noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Dx9VertexShader)

void Dx9VertexShader::Enable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const VertexShader* vshader, MAYBE_UNUSED const ShaderParameters* parameters) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void Dx9VertexShader::Disable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const VertexShader* vshader, MAYBE_UNUSED const ShaderParameters* parameters) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}
