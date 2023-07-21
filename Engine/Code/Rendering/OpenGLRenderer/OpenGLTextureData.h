///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:17)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_H

#include "Rendering/RenderingDll.h"

#include "TextureDataTraits.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Resources/Flags/TextureFlags.h"

#include <array>

namespace Rendering
{
    template <typename Texture>
    class OpenGLTextureData
    {
    public:
        using ClassType = OpenGLTextureData<Texture>;
        using TextureType = Texture;
        using UInt = System::OpenGLUInt;
        using TextureTargetType = System::TextureTarget;
        using TextureInternalFormat = System::TextureInternalFormat;
        using TextureFormat = System::TextureFormat;
        using DataType = System::OpenGLData;

    public:
        explicit OpenGLTextureData(const Texture* texture);
        ~OpenGLTextureData() noexcept = default;
        OpenGLTextureData(const OpenGLTextureData& rhs) = delete;
        OpenGLTextureData& operator=(const OpenGLTextureData& rhs) = delete;
        OpenGLTextureData(OpenGLTextureData&& rhs) noexcept = delete;
        OpenGLTextureData& operator=(OpenGLTextureData&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Enable(int textureUnit) noexcept;
        void Disable(int textureUnit) noexcept;
        NODISCARD void* Lock(int level, BufferLocking mode) noexcept;
        void Unlock(int level);
        NODISCARD void* Lock(int face, int level, BufferLocking mode) noexcept;
        void Unlock(int face, int level);

        NODISCARD UInt GetTexture() const noexcept;

    private:
        void CreatePixelBufferObjects(const Texture* aTexture);
        void InitRemainData() noexcept;
        NODISCARD UInt CreateTextureStructure() noexcept;
        void CreateMipmapLevelStructures(const Texture* aTexture, UInt previousBind) noexcept;
        void TextureImage(int level) noexcept;

    private:
        static constexpr auto textureDimension = TextureDataTraits<Texture>::dimension;
        static constexpr auto textureFace = TextureDataTraits<Texture>::face;
        static constexpr auto textureTextureTargetType = TextureDataTraits<Texture>::textureTargetType;

    private:
        UInt texture;
        TextureInternalFormat textureInternalFormat;
        TextureFormat textureFormat;
        DataType dataType;
        UInt previousTexture;
        UInt numLevels;
        std::array<UInt, textureMaximumMipmapLevels> numLevelBytes;
        std::array<std::array<UInt, textureMaximumMipmapLevels>, textureDimension> dimension;
        std::array<std::array<UInt, textureMaximumMipmapLevels>, textureFace> buffer;
        std::array<std::array<void*, textureMaximumMipmapLevels>, textureFace> lockedMemory;
        std::array<std::array<bool, textureMaximumMipmapLevels>, textureFace> writeLock;
        bool isCompressed;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_H
