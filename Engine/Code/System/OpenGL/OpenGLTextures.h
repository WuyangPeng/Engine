/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/03/01 17:37)

#ifndef SYSTEM_OPENGL_OPENGL_TEXTURES_H
#define SYSTEM_OPENGL_OPENGL_TEXTURES_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE GetGLGenTextures(OpenGLSize n, OpenGLUnsignedInt* textures) noexcept;
    NODISCARD OpenGLUnsignedInt SYSTEM_DEFAULT_DECLARE GetGLGenTextures() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteTextures(OpenGLSize n, const OpenGLUnsignedInt* textures) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteTextures(OpenGLUnsignedInt textures) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBindTexture(TextureTarget target, OpenGLUnsignedInt texture) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLPixelStore(PixelStore pName, OpenGLInt param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLTexturesParameter(TextureTarget target, TextureParameter pName, OpenGLInt param) noexcept;

    void SYSTEM_DEFAULT_DECLARE GetGLTexturesImage(TextureTarget target, OpenGLInt level, TextureExternalFormat format, OpenGLData type, void* pixels) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLTexturesImage(TextureCubeMap target, OpenGLInt level, TextureExternalFormat format, OpenGLData type, void* pixels) noexcept;
    NODISCARD OpenGLInt SYSTEM_DEFAULT_DECLARE GetGLTexturesLevelParameter(TextureTarget target, OpenGLInt level, TextureLevelParameter pName) noexcept;
    NODISCARD OpenGLInt SYSTEM_DEFAULT_DECLARE GetGLTexturesLevelParameter(TextureCubeMap target, OpenGLInt level, TextureLevelParameter pName) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLTexturesStorage1D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalFormat, OpenGLSize width) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLTexturesSubImage1D(TextureTarget target, OpenGLInt level, OpenGLInt xOffset, OpenGLSize width, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLTexturesStorage2D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalFormat, OpenGLSize width, OpenGLSize height) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLTexturesSubImage2D(TextureTarget target, OpenGLInt level, OpenGLInt xOffset, OpenGLInt yOffset, OpenGLSize width, OpenGLSize height, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLTexturesSubImage2D(TextureCubeMap target, OpenGLInt level, OpenGLInt xOffset, OpenGLInt yOffset, OpenGLSize width, OpenGLSize height, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLTexturesStorage3D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalFormat, OpenGLSize width, OpenGLSize height, OpenGLSize depth) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLTexturesSubImage3D(TextureTarget target, OpenGLInt level, OpenGLInt xOffset, OpenGLInt yOffset, OpenGLInt zOffset, OpenGLSize width, OpenGLSize height, OpenGLSize depth, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLGenerateMipmap(TextureTarget target) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLFrameBufferTexture2D(FrameBufferType target, ColorAttachment attachment, TextureTarget texTarget, OpenGLUnsignedInt texture, OpenGLInt level) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLActiveTexture(OpenGLEnum texture) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindImageTexture(OpenGLUnsignedInt unit, OpenGLUnsignedInt texture, OpenGLInt level, bool layered, OpenGLInt layer, BufferLocking access, OpenGLEnum format) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_TEXTURES_H