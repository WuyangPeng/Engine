///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:16)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_MANAGE_DETAIL_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_MANAGE_DETAIL_H

#include "OpenGLTextureData.h"
#include "OpenGLTextureDataManager.h"
#include "TextureDataTraits.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <typename ManageType>
Rendering::OpenGLTextureDataManager<ManageType>::OpenGLTextureDataManager(ManageType& manager) noexcept
    : manager{ manager }, managerLevel{ -1 }, managerFace{ -1 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
RENDERING_DEFAULT_DECLARE Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::Texture1D>>::~OpenGLTextureDataManager() noexcept;

template <>
RENDERING_DEFAULT_DECLARE Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::Texture2D>>::~OpenGLTextureDataManager() noexcept;

template <>
RENDERING_DEFAULT_DECLARE Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::Texture3D>>::~OpenGLTextureDataManager() noexcept;

template <>
RENDERING_DEFAULT_DECLARE Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::TextureCube>>::~OpenGLTextureDataManager() noexcept;

#ifdef OPEN_CLASS_INVARIANT
template <typename ManageType>
bool Rendering::OpenGLTextureDataManager<ManageType>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIAN

template <typename ManageType>
void* Rendering::OpenGLTextureDataManager<ManageType>::Lock(int level, BufferLocking mode) noexcept
{
    static_assert(TextureDataTraits<ManageType::TextureType>::textureType != TextureFlags::TextureCube);

    RENDERING_CLASS_IS_VALID_9;

    managerLevel = level;

    return manager.Lock(managerLevel, mode);
}

template <typename ManageType>
void* Rendering::OpenGLTextureDataManager<ManageType>::Lock(int face, int level, BufferLocking mode) noexcept
{
    static_assert(TextureDataTraits<ManageType::TextureType>::textureType == TextureFlags::TextureCube);

    RENDERING_CLASS_IS_VALID_9;

    managerLevel = level;
    managerFace = face;

    return manager.Lock(managerFace, managerLevel, mode);
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_DETAIL_H