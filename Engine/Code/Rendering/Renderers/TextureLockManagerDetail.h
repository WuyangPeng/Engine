///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:33)

#ifndef RENDERING_RENDERERS_TEXTURE_LOCK_MANAGE_DETAIL_H
#define RENDERING_RENDERERS_TEXTURE_LOCK_MANAGE_DETAIL_H

#include "PlatformTexture1D.h"
#include "PlatformTexture2D.h"
#include "PlatformTexture3D.h"
#include "PlatformTextureCube.h"
#include "TextureLockManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/TextureDataTraits.h"

template <typename PlatformTextureType>
Rendering::TextureLockManager<PlatformTextureType>::TextureLockManager(PlatformTextureType& manager)
    : manager{ manager }, level{ -1 }, face{ -1 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureLockManager<Rendering::PlatformTexture1D>::~TextureLockManager() noexcept;

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureLockManager<Rendering::PlatformTexture2D>::~TextureLockManager() noexcept;

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureLockManager<Rendering::PlatformTexture3D>::~TextureLockManager() noexcept;

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureLockManager<Rendering::PlatformTextureCube>::~TextureLockManager() noexcept;

#ifdef OPEN_CLASS_INVARIANT

template <typename PlatformTextureType>
bool Rendering::TextureLockManager<PlatformTextureType>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename PlatformTextureType>
void* Rendering::TextureLockManager<PlatformTextureType>::Lock(int alevel, BufferLocking mode)
{
    static_assert(TextureDataTraits<PlatformTextureType::TextureType>::sm_TextureType != TextureFlags::TextureCube, "sm_TextureType != TextureCube");

    RENDERING_CLASS_IS_VALID_9;

    level = alevel;

    return manager.Lock(level, mode);
}

template <typename PlatformTextureType>
void* Rendering::TextureLockManager<PlatformTextureType>::Lock(int aFace, int alevel, BufferLocking mode)
{
    static_assert(TextureDataTraits<PlatformTextureType::TextureType>::sm_TextureType == TextureFlags::TextureCube, "sm_TextureType == TextureCube");

    RENDERING_CLASS_IS_VALID_9;

    level = alevel;
    face = aFace;

    return manager.Lock(face, level, mode);
}

#endif  // RENDERING_RENDERERS_TEXTURE_LOCK_MANAGE_DETAIL_H