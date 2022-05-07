// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:44)

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
