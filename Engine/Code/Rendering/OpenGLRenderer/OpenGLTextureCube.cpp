///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 22:25)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureCube.h"
#include "OpenGLTextureDataDetail.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::OpenGLTextureCube::OpenGLTextureCube(MAYBE_UNUSED Renderer* renderer, const TextureCube* texture)
    : openGLTextureData{ texture }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTextureCube)

void Rendering::OpenGLTextureCube::Enable(MAYBE_UNUSED Renderer* renderer, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_9;

    openGLTextureData.Enable(textureUnit);
}

void Rendering::OpenGLTextureCube::Disable(MAYBE_UNUSED Renderer* renderer, int textureUnit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    openGLTextureData.Disable(textureUnit);
}

void* Rendering::OpenGLTextureCube::Lock(int face, int level, BufferLocking mode) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return openGLTextureData.Lock(face, level, mode);
}

void Rendering::OpenGLTextureCube::Unlock(int face, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    openGLTextureData.Unlock(face, level);
}
