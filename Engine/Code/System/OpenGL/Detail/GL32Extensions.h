//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:38)

#ifndef SYSTEM_OPENGL_GL_32_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_32_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GL32ExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/OpenGL/Using/GL32ExtensionsUsing.h"

namespace System
{
    // OpenGL 3.2

    extern PgglGetInteger64i_v gglGetInteger64i_v;
    extern PgglGetBufferParameteri64v gglGetBufferParameteri64v;
    extern PgglProgramParameteri gglProgramParameteri;
    extern PgglFramebufferTexture gglFramebufferTexture;

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL32() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetInteger64i_v(GLenum target, GLuint index, GLint64* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetBufferParameteri64v(GLenum target, GLenum name, GLint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramParameteri(GLuint program, GLenum name, GLint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) noexcept;

    void InitOpenGL32();
}

#endif  // SYSTEM_OPENGL_GL_32_EXTENSIONS_H
