/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 16:13)

#include "Rendering/RenderingExport.h"

#include "RendererClear.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RendererClear::RendererClear() noexcept
    : clearColor{ 1.0f, 1.0f, 1.0f, 1.0f },
      clearDepth{ 0.0f },
      clearStencil{ 0 }

{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererClear)

void Rendering::RendererClear::SetClearColor(const ColourType& aClearColor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    clearColor = aClearColor;
}

Rendering::RendererClear::ColourType Rendering::RendererClear::GetClearColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return clearColor;
}

void Rendering::RendererClear::SetClearDepth(float aClearDepth) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    clearDepth = aClearDepth;
}

float Rendering::RendererClear::GetClearDepth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return clearDepth;
}

void Rendering::RendererClear::SetClearStencil(int aClearStencil) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    clearStencil = aClearStencil;
}

int Rendering::RendererClear::GetClearStencil() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return clearStencil;
}