///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 13:50)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_DETAIL_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_DETAIL_H

#include "OpenGLBindTexture.h"
#include "OpenGLMapping.h"
#include "OpenGLTextureData.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Textures/Texture1D.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Resources/Textures/Texture3D.h"
#include "Rendering/Resources/Textures/TextureCube.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

template <typename Texture>
Rendering::OpenGLTextureData<Texture>::OpenGLTextureData(const Texture* texture)
    : texture{ 0 },
      textureInternalFormat{ System::UnderlyingCastEnum<TextureInternalFormat>(OpenGLConstant::GetOpenGLTextureInternalFormat(System::EnumCastUnderlying(texture->GetFormat()))) },
      textureFormat{ System::UnderlyingCastEnum<TextureFormat>(OpenGLConstant::GetOpenGLTextureFormat(System::EnumCastUnderlying(texture->GetFormat()))) },
      dataType{ System::UnderlyingCastEnum<DataType>(OpenGLConstant::GetOpenGLTextureType(System::EnumCastUnderlying(texture->GetFormat()))) },
      previousTexture{ 0 },
      numLevels{ boost::numeric_cast<UInt>(texture->GetNumLevels()) },
      numLevelBytes{},
      dimension{},
      buffer{},
      lockedMemory{},
      writeLock{},
      isCompressed{ false }
{
    CreatePixelBufferObjects(texture);
    InitRemainData();
    const auto previousBind = CreateTextureStructure();
    CreateMipmapLevelStructures(texture, previousBind);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Texture>
void Rendering::OpenGLTextureData<Texture>::CreatePixelBufferObjects(const Texture* aTtexture)
{
    // 创建像素缓冲器的对象来存储纹理数据。
    for (auto level = 0u; level < numLevels; ++level)
    {
        numLevelBytes.at(level) = aTtexture->GetNumLevelBytes(level);

        for (auto i = 0; i < textureDimension; ++i)
        {
            dimension.at(i).at(level) = aTtexture->GetDimension(i, level);
        }

        for (auto face = 0; face < textureFace; ++face)
        {
            lockedMemory.at(face).at(level) = nullptr;
            writeLock.at(face).at(level) = false;
        }
    }
}

// private
template <typename Texture>
void Rendering::OpenGLTextureData<Texture>::InitRemainData() noexcept
{
    for (auto level = numLevels; level < textureMaximumMipmapLevels; ++level)
    {
        numLevelBytes.at(level) = 0;

        for (auto i = 0; i < textureDimension; ++i)
        {
            dimension.at(i).at(level) = 0;
        }

        for (auto face = 0; face < textureFace; ++face)
        {
            buffer.at(face).at(level) = 0;
            lockedMemory.at(face).at(level) = nullptr;
            writeLock.at(face).at(level) = false;
        }
    }
}

// private
template <typename Texture>
System::OpenGLUInt Rendering::OpenGLTextureData<Texture>::CreateTextureStructure()
{
    // 创建纹理结构。

    const auto previousBind = BindTexture(textureSamplerType, texture);

    return previousBind;
}

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::Texture1D>::CreateMipmapLevelStructures(const Texture1D* aTexture, UInt previousBind) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::Texture2D>::CreateMipmapLevelStructures(const Texture2D* aTexture, UInt previousBind) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::Texture3D>::CreateMipmapLevelStructures(const Texture3D* aTexture, UInt previousBind) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::TextureCube>::CreateMipmapLevelStructures(const TextureCube* aTexture, UInt previousBind) noexcept;

#ifdef OPEN_CLASS_INVARIANT

template <typename Texture>
bool Rendering::OpenGLTextureData<Texture>::IsValid() const noexcept
{
    if (0 < texture && 0 < numLevels)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIAN

template <typename Texture>
void Rendering::OpenGLTextureData<Texture>::Enable(MAYBE_UNUSED int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    previousTexture = BindTexture(textureSamplerType, texture);
}

template <typename Texture>
void Rendering::OpenGLTextureData<Texture>::Disable(MAYBE_UNUSED int textureUnit) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

template <typename Texture>
void* Rendering::OpenGLTextureData<Texture>::Lock(int level, BufferLocking mode) noexcept
{
    static_assert(TextureDataTraits<Texture>::textureType != TextureFlags::TextureCube);

    RENDERING_CLASS_IS_VALID_1;

    if (lockedMemory.at(0).at(level) == nullptr)
    {
        writeLock.at(0).at(level) = (mode != BufferLocking::ReadOnly);
    }

    return lockedMemory.at(0).at(level);
}

template <typename Texture>
void Rendering::OpenGLTextureData<Texture>::Unlock(int level)
{
    static_assert(TextureDataTraits<Texture>::textureType != TextureFlags::TextureCube);

    RENDERING_CLASS_IS_VALID_1;

    if (lockedMemory.at(0).at(level) != nullptr)
    {
        if (writeLock.at(0).at(level))
        {
            const auto previousBind = BindTexture(textureSamplerType, texture);

            TextureImage(level);

            writeLock.at(0).at(level) = false;
        }

        lockedMemory.at(0).at(level) = nullptr;
    }
}

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::Texture1D>::TextureImage(int level) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::Texture2D>::TextureImage(int level) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::Texture3D>::TextureImage(int level) noexcept;

template <typename Texture>
void* Rendering::OpenGLTextureData<Texture>::Lock(int face, int level, BufferLocking mode) noexcept
{
    static_assert(TextureDataTraits<Texture>::textureType == TextureFlags::TextureCube);

    RENDERING_CLASS_IS_VALID_1;

    if (lockedMemory.at(face).at(level) == nullptr)
    {
        writeLock.at(face).at(level) = (mode != BufferLocking::ReadOnly);
    }

    return lockedMemory.at(face).at(level);
}

template <typename Texture>
void Rendering::OpenGLTextureData<Texture>::Unlock(int face, int level)
{
    static_assert(TextureDataTraits<Texture>::textureType == TextureFlags::TextureCube);

    RENDERING_CLASS_IS_VALID_1;

    if (lockedMemory.at(face).at(level) != nullptr)
    {
        if (writeLock.at(face).at(level))
        {
            const auto previousBind = BindTexture(TextureDataTraits<Texture>::samplerType, texture);

            writeLock.at(face).at(level) = false;
        }

        lockedMemory.at(face).at(level) = 0;
    }
}

template <typename Texture>
System::OpenGLUInt Rendering::OpenGLTextureData<Texture>::GetTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return texture;
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_DETAIL_H