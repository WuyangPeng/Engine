///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 21:06)

#include "Rendering/RenderingExport.h"

#include "Dx9Texture2D.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::Dx9Texture2D::Dx9Texture2D(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const Texture2D* texture) noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Dx9Texture2D::Dx9Texture2D(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED bool isColortexture, MAYBE_UNUSED const Texture2D* texture, MAYBE_UNUSED bool autoGenMipMap) noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Dx9Texture2D)

void Rendering::Dx9Texture2D::Enable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED int textureUnit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::Dx9Texture2D::Disable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED int textureUnit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void* Rendering::Dx9Texture2D::Lock(MAYBE_UNUSED int level, MAYBE_UNUSED BufferLocking mode) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return nullptr;
}

void Rendering::Dx9Texture2D::Unlock(MAYBE_UNUSED int level) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

System::OpenGLUInt Rendering::Dx9Texture2D::GetTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return 0;
}
