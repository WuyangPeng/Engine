///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/21 15:45)

#include "Rendering/RenderingExport.h"

#include "OverlayEffect.h"
#include "Detail/OverlayEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, OverlayEffect)

Rendering::OverlayEffect::OverlayEffect(int windowWidth, int windowHeight)
    : impl{ windowHeight, windowWidth }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OverlayEffect::OverlayEffect(ProgramFactory& factory, int windowWidth, int windowHeight, int textureWidth, int textureHeight, SamplerStateFilter filter, SamplerStateMode mode0, SamplerStateMode mode1, bool useColorPShader)
    : impl{ factory, windowHeight, windowWidth, textureWidth, textureHeight, filter, mode0, mode1, useColorPShader }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OverlayEffect::OverlayEffect(ProgramFactory& factory, int windowWidth, int windowHeight, int textureWidth, int textureHeight, const std::string& pixelShaderFile)
    : impl{ factory, windowHeight, windowWidth, textureWidth, textureHeight, pixelShaderFile }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OverlayEffect)

Rendering::OverlayEffect::ConstVertexBufferSharedPtr Rendering::OverlayEffect::GetVertexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetVertexBuffer();
}

Rendering::OverlayEffect::ConstIndexBufferSharedPtr Rendering::OverlayEffect::GetIndexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIndexBuffer();
}

Rendering::OverlayEffect::ConstVisualProgramSharedPtr Rendering::OverlayEffect::GetProgram() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetProgram();
}

Rendering::OverlayEffect::ConstVisualEffectSharedPtr Rendering::OverlayEffect::GetEffect() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetEffect();
}

void Rendering::OverlayEffect::SetOverlayRectangle(const RectangleType& rectangle)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetOverlayRectangle(rectangle);
}

Rendering::OverlayEffect::RectangleType Rendering::OverlayEffect::GetOverlayRectangle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOverlayRectangle();
}

void Rendering::OverlayEffect::SetTextureRectangle(const RectangleType& rectangle)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetTextureRectangle(rectangle);
}

Rendering::OverlayEffect::RectangleType Rendering::OverlayEffect::GetTextureRectangle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTextureRectangle();
}

void Rendering::OverlayEffect::SetRectangles(const RectangleType& overlayRectangle, const RectangleType& textureRectangle)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetRectangles(overlayRectangle, textureRectangle);
}

bool Rendering::OverlayEffect::Contains(int x, int y) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->Contains(x, y);
}

void Rendering::OverlayEffect::SetTexture(const Texture2DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetTexture(texture);
}

void Rendering::OverlayEffect::SetTexture(std::string const& textureName, const Texture2DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetTexture(textureName, texture);
}

void Rendering::OverlayEffect::SetNormalizedZ(float z)
{
    RENDERING_CLASS_IS_VALID_9;
    
    return impl->SetNormalizedZ(z);
}
