///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:22)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture3D.h"
#include "OpenGLTextureDataDetail.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::OpenGLTexture3D::OpenGLTexture3D(MAYBE_UNUSED Renderer* renderer, const Texture3D* texture)
    : openGLTextureData{ texture }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTexture3D)

void Rendering::OpenGLTexture3D::Enable(MAYBE_UNUSED Renderer* renderer, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_9;

    openGLTextureData.Enable(textureUnit);
}

void Rendering::OpenGLTexture3D::Disable(MAYBE_UNUSED Renderer* renderer, int textureUnit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    openGLTextureData.Disable(textureUnit);
}

void* Rendering::OpenGLTexture3D::Lock(int level, BufferLocking mode) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return openGLTextureData.Lock(level, mode);
}

void Rendering::OpenGLTexture3D::Unlock(int level)
{
    RENDERING_CLASS_IS_VALID_9;

    openGLTextureData.Unlock(level);
}
