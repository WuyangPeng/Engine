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
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <stdexcept>

std::shared_ptr<const Rendering::VertexBuffer> Rendering::Font::GetVertexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

std::shared_ptr<const Rendering::IndexBuffer> Rendering::Font::GetIndexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

std::shared_ptr<const Rendering::TextEffect> Rendering::Font::GetTextEffect() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

std::shared_ptr<Rendering::VertexBuffer> Rendering::Font::GetVertexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return nullptr;
}

std::shared_ptr<Rendering::IndexBuffer> Rendering::Font::GetIndexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return nullptr;
}

std::shared_ptr<Rendering::TextEffect> Rendering::Font::GetTextEffect() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return nullptr;
}

void Rendering::Font::Typeset(MAYBE_UNUSED int getWidth, MAYBE_UNUSED int getHeight, MAYBE_UNUSED int i, MAYBE_UNUSED int y, MAYBE_UNUSED const Colour<float>& color, MAYBE_UNUSED const std::string& string) noexcept
{
}
