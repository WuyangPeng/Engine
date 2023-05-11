///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.0 (2023/01/12 22:44)

#include "System/SystemExport.h"

#include "OpenGLTextures.h"
#include "Flags/GLExtensionsFlags.h"
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

void System::SetGLPixelStore(PixelStore pname, OpenGLInt param) noexcept
{
    GLPixelStorei(EnumCastUnderlying(pname), param);
}

void System::SetGLTexturesParameter(TextureTarget target, TextureParameter pname, OpenGLInt param) noexcept
{
    GLTexParameteri(EnumCastUnderlying(target), EnumCastUnderlying(pname), param);
}

System::OpenGLInt System::GetGLTexturesLevelParameter(TextureTarget target, OpenGLInt level, TextureLevelParameter pname) noexcept
{
    OpenGLInt params{};
    GLGetTexLevelParameteriv(EnumCastUnderlying(target), level, EnumCastUnderlying(pname), &params);

    return params;
}

System::OpenGLInt System::GetGLTexturesLevelParameter(TextureCubeMap target, OpenGLInt level, TextureLevelParameter pname) noexcept
{
    OpenGLInt params{};
    GLGetTexLevelParameteriv(EnumCastUnderlying(target), level, EnumCastUnderlying(pname), &params);

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

void System::SetGLTexturesSubImage1D(TextureTarget target, OpenGLInt level, OpenGLInt xoffset, OpenGLSize width, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage1D(EnumCastUnderlying(target), level, xoffset, width, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexturesStorage1D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalformat, OpenGLSize width) noexcept
{
    GLTexStorage1D(EnumCastUnderlying(target), levels, EnumCastUnderlying(internalformat), width);
}

void System::SetGLTexturesSubImage2D(TextureTarget target, OpenGLInt level, OpenGLInt xoffset, OpenGLInt yoffset, OpenGLSize width, OpenGLSize height, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage2D(EnumCastUnderlying(target), level, xoffset, yoffset, width, height, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexturesSubImage2D(TextureCubeMap target, OpenGLInt level, OpenGLInt xoffset, OpenGLInt yoffset, OpenGLSize width, OpenGLSize height, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage2D(EnumCastUnderlying(target), level, xoffset, yoffset, width, height, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexturesStorage2D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalformat, OpenGLSize width, OpenGLSize height) noexcept
{
    GLTexStorage2D(EnumCastUnderlying(target), levels, EnumCastUnderlying(internalformat), width, height);
}

void System::SetGLTexturesSubImage3D(TextureTarget target, OpenGLInt level, OpenGLInt xoffset, OpenGLInt yoffset, OpenGLInt zoffset, OpenGLSize width, OpenGLSize height, OpenGLSize depth, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage3D(EnumCastUnderlying(target), level, xoffset, yoffset, zoffset, width, height, depth, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexturesSubImage3D(TextureCubeMap target, OpenGLInt level, OpenGLInt xoffset, OpenGLInt yoffset, OpenGLInt zoffset, OpenGLSize width, OpenGLSize height, OpenGLSize depth, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage3D(EnumCastUnderlying(target), level, xoffset, yoffset, zoffset, width, height, depth, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexturesStorage3D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalformat, OpenGLSize width, OpenGLSize height, OpenGLSize depth) noexcept
{
    GLTexStorage3D(EnumCastUnderlying(target), levels, EnumCastUnderlying(internalformat), width, height, depth);
}

void System::SetGLGenerateMipmap(TextureTarget target) noexcept
{
    GLGenerateMipmap(EnumCastUnderlying(target));
}

void System::SetGLFramebufferTexture2D(FrameBufferType target, ColorAttachent attachment, TextureTarget textarget, OpenGLUInt texture, OpenGLInt level) noexcept
{
    GLFramebufferTexture2D(EnumCastUnderlying(target), EnumCastUnderlying(attachment), EnumCastUnderlying(textarget), texture, level);
}