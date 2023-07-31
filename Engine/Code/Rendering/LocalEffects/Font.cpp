///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:44)

#include "Rendering/RenderingExport.h"

#include "Font.h"
#include "Detail/FontFactory.h"
#include "Detail/FontImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, Font)

Rendering::Font::Font(FontType fontType, ProgramFactory& factory, const std::string& shaderExtendName, int maxMessageLength)
    : impl{ CoreTools::ImplCreateUseFactory::Default, fontType, factory, shaderExtendName, maxMessageLength }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Font::ConstVertexBufferSharedPtr Rendering::Font::GetVertexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetVertexBuffer();
}

Rendering::Font::ConstIndexBufferSharedPtr Rendering::Font::GetIndexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIndexBuffer();
}

Rendering::Font::ConstTextEffectSharedPtr Rendering::Font::GetTextEffect() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTextEffect();
}

int Rendering::Font::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetHeight();
}

int Rendering::Font::GetWidth(const std::string& message) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWidth(message);
}

void Rendering::Font::Typeset(int viewportWidth, int viewportHeight, int x, int y, const Colour& color, const std::string& message) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->Typeset(viewportWidth, viewportHeight, x, y, color, message);
}

Rendering::Font::VertexBufferSharedPtr Rendering::Font::GetVertexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetVertexBuffer();
}

Rendering::Font::IndexBufferSharedPtr Rendering::Font::GetIndexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetIndexBuffer();
}

Rendering::Font::TextEffectSharedPtr Rendering::Font::GetTextEffect() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetTextEffect();
}
