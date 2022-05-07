///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 18:15)

#include "Rendering/RenderingExport.h"

#include "Dx9RenderTarget.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::Dx9RenderTarget::Dx9RenderTarget(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const RenderTarget* renderTarget) noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Dx9RenderTarget)

void Rendering::Dx9RenderTarget::Enable(MAYBE_UNUSED Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::Dx9RenderTarget::Disable(MAYBE_UNUSED Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

Rendering::ConstTexture2DSharedPtr Rendering::Dx9RenderTarget::ReadColor(MAYBE_UNUSED int index, MAYBE_UNUSED Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return nullptr;
}
