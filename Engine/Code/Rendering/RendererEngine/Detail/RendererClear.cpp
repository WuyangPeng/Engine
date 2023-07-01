///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 15:01)

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

void Rendering::RendererClear::SetClearColor(const Colour& aClearColor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    clearColor = aClearColor;
}

Rendering::RendererClear::Colour Rendering::RendererClear::GetClearColor() const noexcept
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