///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 18:40)

#ifndef RENDERING_RENDERERS_TEXTURE_MANAGEMENT_DETAIL_H
#define RENDERING_RENDERERS_TEXTURE_MANAGEMENT_DETAIL_H

#include "PlatformTexture1D.h"
#include "PlatformTexture2D.h"
#include "PlatformTexture3D.h"
#include "PlatformTextureCube.h"
#include "TextureManagement.h"
#include "TextureManagementLockEncapsulationDetail.h"
#include "System/Helper/PragmaWarning.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/OpenGLRenderer/TextureDataTraits.h"
#include "Rendering/Resources/Textures/Texture1D.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Resources/Textures/Texture3D.h"
#include "Rendering/Resources/Textures/TextureCube.h"

template <typename PlatformTextureType>
Rendering::TextureManagement<PlatformTextureType>::TextureManagement(const RendererSharedPtr& renderer)
    : renderer{ renderer }, textures{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename PlatformTextureType>
bool Rendering::TextureManagement<PlatformTextureType>::IsValid() const noexcept
{
    if (renderer.lock())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename PlatformTextureType>
void Rendering::TextureManagement<PlatformTextureType>::Bind(const ConstTextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    if (textures.find(texture) == textures.end())
    {
        auto platformTexture = std::make_shared<PlatformTextureType>(renderer.lock().get(), texture.get());
        textures.emplace(texture, platformTexture);
    }
}

template <typename PlatformTextureType>
void Rendering::TextureManagement<PlatformTextureType>::Unbind(const ConstTextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    textures.erase(texture);
}

template <typename PlatformTextureType>
void Rendering::TextureManagement<PlatformTextureType>::Enable(const ConstTextureSharedPtr& texture, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = textures.find(texture);
    PlatformTextureSharedPtr platformTexture{};
    if (iter != textures.end())
    {
        platformTexture = iter->second;
    }
    else
    {
        // 延迟构造。
        platformTexture = std::make_shared<PlatformTextureType>(renderer.lock().get(), texture.get());
        textures.emplace(texture, platformTexture);
    }

    platformTexture->Enable(renderer.lock().get(), textureUnit);
}

template <typename PlatformTextureType>
void Rendering::TextureManagement<PlatformTextureType>::Disable(const ConstTextureSharedPtr& texture, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = textures.find(texture);

    if (iter != textures.end())
    {
        auto platformTexture = iter->second;

        platformTexture->Disable(renderer.lock().get(), textureUnit);
    }
}

template <typename PlatformTextureType>
void* Rendering::TextureManagement<PlatformTextureType>::Lock(const ConstTextureSharedPtr& texture, int level, BufferLocking mode)
{
    static_assert(TextureDataTraits<PlatformTextureType::TextureType>::textureType != TextureFlags::TextureCube, "sm_TextureType != TextureCube ");

    RENDERING_CLASS_IS_VALID_1;

    const auto iter = textures.find(texture);
    PlatformTextureSharedPtr platformTexture{};
    if (iter != textures.end())
    {
        platformTexture = iter->second;
    }
    else
    {
        // 延迟构造。
        platformTexture = std::make_shared<PlatformTextureType>(renderer.lock().get(), texture.get());
        textures.emplace(texture, platformTexture);
    }

    return platformTexture->Lock(level, mode);
}

template <typename PlatformTextureType>
void Rendering::TextureManagement<PlatformTextureType>::Unlock(const ConstTextureSharedPtr& texture, int level)
{
    static_assert(TextureDataTraits<PlatformTextureType::TextureType>::textureType != TextureFlags::TextureCube);

    RENDERING_CLASS_IS_VALID_1;

    const auto iter = textures.find(texture);

    if (iter != textures.end())
    {
        auto platformTexture = iter->second;

        platformTexture->Unlock(level);
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

template <typename PlatformTextureType>
void Rendering::TextureManagement<PlatformTextureType>::Update(const ConstTextureSharedPtr& texture, int level)
{
    static_assert(TextureDataTraits<PlatformTextureType::TextureType>::textureType != TextureFlags::TextureCube);

    RENDERING_CLASS_IS_VALID_1;

    const auto numBytes = texture->GetNumLevelBytes(level);

    TextureManagementLockEncapsulation<ClassType> encapsulation{ *this };
}

#include STSTEM_WARNING_POP

template <typename PlatformTextureType>
typename Rendering::TextureManagement<PlatformTextureType>::PlatformTextureSharedPtr Rendering::TextureManagement<PlatformTextureType>::GetResource(const ConstTextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = textures.find(texture);
    if (iter != textures.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的纹理资源！"s));
    }
}

template <typename PlatformTextureType>
void* Rendering::TextureManagement<PlatformTextureType>::LockCube(const ConstTextureSharedPtr& texture, int face, int level, BufferLocking mode)
{
    static_assert(TextureDataTraits<PlatformTextureType::TextureType>::textureType == TextureFlags::TextureCube);

    RENDERING_CLASS_IS_VALID_1;

    const auto iter = textures.find(texture);
    PlatformTextureSharedPtr platformTexture{};
    if (iter != textures.end())
    {
        platformTexture = iter->second;
    }
    else
    {
        // 延迟构造。
        platformTexture = std::make_shared<PlatformTextureType>(renderer.lock().get(), texture.get());
        textures.emplace(texture, platformTexture);
    }

    return platformTexture->Lock(face, level, mode);
}

template <typename PlatformTextureType>
void Rendering::TextureManagement<PlatformTextureType>::UnlockCube(const ConstTextureSharedPtr& texture, int face, int level)
{
    static_assert(TextureDataTraits<PlatformTextureType::TextureType>::textureType == TextureFlags::TextureCube);

    RENDERING_CLASS_IS_VALID_1;

    const auto iter = textures.find(texture);

    if (iter != textures.end())
    {
        auto platformTexture = iter->second;

        platformTexture->Unlock(face, level);
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

template <typename PlatformTextureType>
void Rendering::TextureManagement<PlatformTextureType>::UpdateCube(const ConstTextureSharedPtr& texture, MAYBE_UNUSED int face, int level)
{
    static_assert(TextureDataTraits<PlatformTextureType::TextureType>::textureType == TextureFlags::TextureCube);

    RENDERING_CLASS_IS_VALID_1;

    const auto numBytes = texture->GetNumLevelBytes(level);

    TextureManagementLockEncapsulation<ClassType> encapsulation{ *this };
}

#include STSTEM_WARNING_POP

template <typename PlatformTextureType>
bool Rendering::TextureManagement<PlatformTextureType>::IsInTextureMap(const ConstTextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return textures.find(texture) != textures.end();
}

template <typename PlatformTextureType>
void Rendering::TextureManagement<PlatformTextureType>::InsertTextureMap(const ConstTextureSharedPtr& texture, const PlatformTextureSharedPtr& platformTexture)
{
    RENDERING_CLASS_IS_VALID_1;

    textures.emplace(texture, platformTexture);
}

template <typename PlatformTextureType>
void Rendering::TextureManagement<PlatformTextureType>::RemoveTextureMap(const ConstTextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    textures.erase(texture);
}

#endif  // RENDERING_RENDERERS_TEXTURE_MANAGEMENT_DETAIL_H