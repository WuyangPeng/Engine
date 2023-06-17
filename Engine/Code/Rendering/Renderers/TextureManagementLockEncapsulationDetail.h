///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:33)

#ifndef RENDERING_RENDERERS_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_DETAIL_H
#define RENDERING_RENDERERS_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_DETAIL_H

#include "PlatformTexture1D.h"
#include "PlatformTexture2D.h"
#include "PlatformTexture3D.h"
#include "PlatformTextureCube.h"
#include "TextureManagement.h"
#include "TextureManagementLockEncapsulation.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/TextureDataTraits.h"
#include "Rendering/Resources/Flags/TextureFlags.h"

template <typename TextureManagementType>
Rendering::TextureManagementLockEncapsulation<TextureManagementType>::TextureManagementLockEncapsulation(TextureManagementType& manager) noexcept
    : manager{ manager }, texture{ nullptr }, level{ -1 }, face{ -1 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture1D>>::~TextureManagementLockEncapsulation() noexcept;

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture2D>>::~TextureManagementLockEncapsulation() noexcept;

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture3D>>::~TextureManagementLockEncapsulation() noexcept;

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTextureCube>>::~TextureManagementLockEncapsulation() noexcept;

#ifdef OPEN_CLASS_INVARIANT

template <typename TextureManagementType>
bool Rendering::TextureManagementLockEncapsulation<TextureManagementType>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename TextureManagementType>
void* Rendering::TextureManagementLockEncapsulation<TextureManagementType>::Lock(ConstTextureSharedPtr aTexture, int aLevel, BufferLocking mode)
{
    static_assert(TextureDataTraits<TextureManagementType::TextureType>::textureType != TextureFlags::TextureCube);

    RENDERING_CLASS_IS_VALID_9;

    auto videoMemory = manager.Lock(aTexture, aLevel, mode);
    texture = aTexture;
    level = aLevel;

    return videoMemory;
}

template <typename TextureManagementType>
void* Rendering::TextureManagementLockEncapsulation<TextureManagementType>::LockCube(ConstTextureSharedPtr aTexture, int aFace, int aLevel, BufferLocking mode)
{
    static_assert(TextureDataTraits<TextureManagementType::TextureType>::textureType == TextureFlags::TextureCube);

    RENDERING_CLASS_IS_VALID_9;

    auto videoMemory = manager.LockCube(aTexture, aFace, aLevel, mode);
    texture = aTexture;
    level = aLevel;
    face = aFace;

    return videoMemory;
}

#endif  // RENDERING_RENDERERS_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_DETAIL_H