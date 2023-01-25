///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/20 15:04)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_TESTING_BASE_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_TESTING_BASE_H

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>

namespace System
{
    class OpenGLTexturesTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLTexturesTestingBase;
        using ParentType = UnitTest;

    public:
        explicit OpenGLTexturesTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto bufferSize = 12;
        using TexturesType = std::array<OpenGLUInt, bufferSize>;
        using TexturesImageType = std::vector<char>;
        using TextureTargetContainer = std::vector<TextureTarget>;
        using TextureTargetContainerConstIter = TextureTargetContainer::const_iterator;
        using TextureInternalFormatContainer = std::vector<TextureInternalFormat>;
        using TextureInternalFormatContainerConstIter = TextureInternalFormatContainer::const_iterator;
        using TextureCubeMapContainer = std::vector<TextureCubeMap>;
        using TextureCubeMapContainerConstIter = TextureCubeMapContainer::const_iterator;
        using TextureFormatMapping = std::map<TextureInternalFormat, TextureExternalFormat>;
        using TextureFormatSizeMapping = std::map<TextureInternalFormat, int>;

    protected:
        void SetGLDeleteTextureTest(OpenGLUInt texture) noexcept;
        void SetGLDeleteTexturesTest(const TexturesType& textures) noexcept;
        NODISCARD TextureTargetContainerConstIter begin() const noexcept;
        NODISCARD TextureTargetContainerConstIter end() const noexcept;
        NODISCARD int GetTextureTargetSize() const;
        NODISCARD TextureInternalFormatContainerConstIter GetTextureInternalFormatsBegin() const noexcept;
        NODISCARD TextureInternalFormatContainerConstIter GetTextureInternalFormatsEnd() const noexcept;
        NODISCARD TextureCubeMapContainerConstIter GetTextureCubeMapBegin() const noexcept;
        NODISCARD TextureCubeMapContainerConstIter GetTextureCubeMapEnd() const noexcept;
        NODISCARD TextureExternalFormat GetTextureExternalFormat(TextureInternalFormat textureInternalFormat) const;
        NODISCARD int GetTextureFormatSize(TextureInternalFormat textureInternalFormat) const;

    private:
        TextureTargetContainer textureTargets;
        TextureInternalFormatContainer textureInternalFormats;
        TextureFormatMapping textureFormat;
        TextureFormatSizeMapping textureFormatSize;
        TextureCubeMapContainer textureCubeMaps;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_TESTING_BASE_H