//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:39)

#ifndef SYSTEM_OPENGL_GL_45_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_45_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GL45ExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL45ExtensionsUsing.h"

namespace System
{
    // OpenGL 4.5

    extern PgglGetGraphicsResetStatus gglGetGraphicsResetStatus;
    extern PgglGetnCompressedTexImage gglGetnCompressedTexImage;
    extern PgglGetnTexImage gglGetnTexImage;
    extern PgglGetnUniformdv gglGetnUniformdv;

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL45() noexcept;

    SYSTEM_HIDDEN_DECLARE GLenum GlGetGraphicsResetStatus() noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, GLvoid* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnTexImage(GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnUniformdv(GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels) noexcept;

    void InitOpenGL45();
}

#endif  // SYSTEM_OPENGL_GL_45_EXTENSIONS_H
