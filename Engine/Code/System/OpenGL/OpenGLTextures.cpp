///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 23:44)

#include "System/SystemExport.h"

#include "OpenGLTextures.h" 
#include "Flags/OpenGLFlags.h"
#include "Detail/GL10Extensions.h"
#include "Detail/GL11Extensions.h"
#include "Detail/GL12Extensions.h"
#include "Detail/GL30Extensions.h"
#include "Detail/GL42Extensions.h"
#include "System/Helper/EnumCast.h"

void System::SetGLBindTexture(TextureTarget target, OpenGLUInt texture) noexcept
{
    GLBindTexture(EnumCastUnderlying(target), texture);
}

void System::SetGLPixelStore(PixelStore pName, OpenGLInt param) noexcept
{
    GLPixelStorei(EnumCastUnderlying(pName), param);
}

void System::SetGLTexturesParameter(TextureTarget target, TextureParameter pName, OpenGLInt param) noexcept
{
    GLTexParameteri(EnumCastUnderlying(target), EnumCastUnderlying(pName), param);
}

System::OpenGLInt System::GetGLTexturesLevelParameter(TextureTarget target, OpenGLInt level, TextureLevelParameter pName) noexcept
{
    OpenGLInt params{};
    GLGetTexLevelParameteriv(EnumCastUnderlying(target), level, EnumCastUnderlying(pName), &params);

    return params;
}

System::OpenGLInt System::GetGLTexturesLevelParameter(TextureCubeMap target, OpenGLInt level, TextureLevelParameter pName) noexcept
{
    OpenGLInt params{};
    GLGetTexLevelParameteriv(EnumCastUnderlying(target), level, EnumCastUnderlying(pName), &params);

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

System::OpenGLUInt System::GetGLGenTextures() noexcept
{
    OpenGLUInt textures{};
    GetGLGenTextures(1, &textures);

    return textures;
}

void System::GetGLGenTextures(OpenGLSize n, OpenGLUInt* textures) noexcept
{
    GLGenTextures(n, textures);
}

void System::SetGLDeleteTextures(OpenGLSize n, const OpenGLUInt* textures) noexcept
{
    GLDeleteTextures(n, textures);
}

void System::SetGLDeleteTextures(OpenGLUInt textures) noexcept
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

void System::SetGLTexturesSubImage3D(TextureCubeMap target, OpenGLInt level, OpenGLInt xOffset, OpenGLInt yOffset, OpenGLInt zOffset, OpenGLSize width, OpenGLSize height, OpenGLSize depth, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
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

void System::SetGLFrameBufferTexture2D(FrameBufferType target, ColorAttachment attachment, TextureTarget texTarget, OpenGLUInt texture, OpenGLInt level) noexcept
{
    GLFramebufferTexture2D(EnumCastUnderlying(target), EnumCastUnderlying(attachment), EnumCastUnderlying(texTarget), texture, level);
}