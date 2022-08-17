///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/22 22:26)

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

        void Enable(int textureUnit);
        void Disable(int textureUnit) noexcept;
        NODISCARD void* Lock(int level, BufferLocking mode) noexcept;
        void Unlock(int level);
        NODISCARD void* Lock(int face, int level, BufferLocking mode) noexcept;
        void Unlock(int face, int level);

        NODISCARD UInt GetTexture() const noexcept;

    private:
        void CreatePixelBufferObjects(const Texture* aTexture);
        void InitRemainData() noexcept;
        NODISCARD UInt CreateTextureStructure();
        void CreateMipmapLevelStructures(const Texture* aTexture, UInt previousBind) noexcept;
        void TextureImage(int level) noexcept;

    private:
        static constexpr auto textureDimension = TextureDataTraits<Texture>::dimension;
        static constexpr auto textureFace = TextureDataTraits<Texture>::face;
        static constexpr auto textureSamplerType = TextureDataTraits<Texture>::samplerType;
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
