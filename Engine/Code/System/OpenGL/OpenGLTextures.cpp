/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 00:12)

#include "System/SystemExport.h"

#include "OpenGLTextures.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL10Extensions.h"
#include "Detail/GL11Extensions.h"
#include "Detail/GL12Extensions.h"
#include "Detail/GL13Extensions.h"
#include "Detail/GL30Extensions.h"
#include "Detail/GL42Extensions.h"
#include "System/Helper/EnumCast.h"

void System::SetGLBindTexture(TextureTarget target, OpenGLUnsignedInt texture) noexcept
{
    GLBindTexture(EnumCastUnderlying(target), texture);
}

void System::SetGLPixelStore(PixelStore pName, OpenGLInt param) noexcept
{
    GLPixelStoreI(EnumCastUnderlying(pName), param);
}

void System::SetGLTexturesParameter(TextureTarget target, TextureParameter pName, OpenGLInt param) noexcept
{
    GLTexParameterI(EnumCastUnderlying(target), EnumCastUnderlying(pName), param);
}

System::OpenGLInt System::GetGLTexturesLevelParameter(TextureTarget target, OpenGLInt level, TextureLevelParameter pName) noexcept
{
    OpenGLInt params{};
    GLGetTexLevelParameterIv(EnumCastUnderlying(target), level, EnumCastUnderlying(pName), &params);

    return params;
}

System::OpenGLInt System::GetGLTexturesLevelParameter(TextureCubeMap target, OpenGLInt level, TextureLevelParameter pName) noexcept
{
    OpenGLInt params{};
    GLGetTexLevelParameterIv(EnumCastUnderlying(target), level, EnumCastUnderlying(pName), &params);

    return params;
}

void System::GetGLTexturesImage(TextureTarget target, OpenGLInt level, TextureExternalFormat format, OpenGLData type, void* pixels) noexcept
{
    GLGetTexImage(EnumCastUnderlying(target), level, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::GetGLTexturesImage(TextureCubeMap target, OpenGLInt level, TextureExternalFormat format, OpenGLData type, void* pixels) noexcept
{
    GLGetTexImage(EnumCastUnderlying(target), level, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

System::OpenGLUnsignedInt System::GetGLGenTextures() noexcept
{
    OpenGLUnsignedInt textures{};
    GetGLGenTextures(1, &textures);

    return textures;
}

void System::GetGLGenTextures(OpenGLSize n, OpenGLUnsignedInt* textures) noexcept
{
    GLGenTextures(n, textures);
}

void System::SetGLDeleteTextures(OpenGLSize n, const OpenGLUnsignedInt* textures) noexcept
{
    GLDeleteTextures(n, textures);
}

void System::SetGLDeleteTextures(OpenGLUnsignedInt textures) noexcept
{
    SetGLDeleteTextures(1, &textures);
}

void System::SetGLTexturesSubImage1D(TextureTarget target, OpenGLInt level, OpenGLInt xOffset, OpenGLSize width, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage1D(EnumCastUnderlying(target), level, xOffset, width, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexturesStorage1D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalFormat, OpenGLSize width) noexcept
{
    GLTexStorage1D(EnumCastUnderlying(target), levels, EnumCastUnderlying(internalFormat), width);
}

void System::SetGLTexturesSubImage2D(TextureTarget target, OpenGLInt level, OpenGLInt xOffset, OpenGLInt yOffset, OpenGLSize width, OpenGLSize height, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage2D(EnumCastUnderlying(target), level, xOffset, yOffset, width, height, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexturesSubImage2D(TextureCubeMap target, OpenGLInt level, OpenGLInt xOffset, OpenGLInt yOffset, OpenGLSize width, OpenGLSize height, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage2D(EnumCastUnderlying(target), level, xOffset, yOffset, width, height, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexturesStorage2D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalFormat, OpenGLSize width, OpenGLSize height) noexcept
{
    GLTexStorage2D(EnumCastUnderlying(target), levels, EnumCastUnderlying(internalFormat), width, height);
}

void System::SetGLTexturesSubImage3D(TextureTarget target, OpenGLInt level, OpenGLInt xOffset, OpenGLInt yOffset, OpenGLInt zOffset, OpenGLSize width, OpenGLSize height, OpenGLSize depth, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage3D(EnumCastUnderlying(target), level, xOffset, yOffset, zOffset, width, height, depth, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexturesStorage3D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalFormat, OpenGLSize width, OpenGLSize height, OpenGLSize depth) noexcept
{
    GLTexStorage3D(EnumCastUnderlying(target), levels, EnumCastUnderlying(internalFormat), width, height, depth);
}

void System::SetGLGenerateMipmap(TextureTarget target) noexcept
{
    GLGenerateMipmap(EnumCastUnderlying(target));
}

void System::SetGLFrameBufferTexture2D(FrameBufferType target, ColorAttachment attachment, TextureTarget texTarget, OpenGLUnsignedInt texture, OpenGLInt level) noexcept
{
    GLFrameBufferTexture2D(EnumCastUnderlying(target), EnumCastUnderlying(attachment), EnumCastUnderlying(texTarget), texture, level);
}

void System::SetGLActiveTexture(OpenGLEnum texture) noexcept
{
    GLActiveTexture(texture);
}

void System::SetGLBindImageTexture(OpenGLUnsignedInt unit, OpenGLUnsignedInt texture, OpenGLInt level, bool layered, OpenGLInt layer, BufferLocking access, OpenGLEnum format) noexcept
{
    GLBindImageTexture(unit, texture, level, layered, layer ? GL_TRUE : GL_FALSE, EnumCastUnderlying(access), format);
}
