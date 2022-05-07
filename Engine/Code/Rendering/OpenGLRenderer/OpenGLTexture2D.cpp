///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 22:23)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture2D.h"
#include "OpenGLTextureDataDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::OpenGLTexture2D::OpenGLTexture2D(MAYBE_UNUSED Renderer* renderer, const Texture2D* texture)
    : openGLTextureData{ texture }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTexture2D)

void Rendering::OpenGLTexture2D::Enable(MAYBE_UNUSED Renderer* renderer, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_9;

    openGLTextureData.Enable(textureUnit);
}

void Rendering::OpenGLTexture2D::Disable(MAYBE_UNUSED Renderer* renderer, int textureUnit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    openGLTextureData.Disable(textureUnit);
}

void* Rendering::OpenGLTexture2D::Lock(int level, BufferLocking mode) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return openGLTextureData.Lock(level, mode);
}

void Rendering::OpenGLTexture2D::Unlock(int level)
{
    RENDERING_CLASS_IS_VALID_9;

    openGLTextureData.Unlock(level);
}

System::OpenGLUInt Rendering::OpenGLTexture2D::GetTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return openGLTextureData.GetTexture();
}
