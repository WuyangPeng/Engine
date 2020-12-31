//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:38)

#ifndef SYSTEM_OPENGL_GL_40_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_40_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GL40ExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/OpenGL/Using/GL40ExtensionsUsing.h"

namespace System
{
    // OpenGL 4.0

    extern PgglBlendEquationSeparatei gglBlendEquationSeparatei;
    extern PgglBlendEquationi gglBlendEquationi;
    extern PgglBlendFuncSeparatei gglBlendFuncSeparatei;
    extern PgglBlendFunci gglBlendFunci;
    extern PgglMinSampleShading gglMinSampleShading;

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL40() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBlendEquationi(GLuint buf, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBlendFunci(GLuint buf, GLenum src, GLenum dst) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMinSampleShading(GLclampf value) noexcept;

    void InitOpenGL40();
}

#endif  // SYSTEM_OPENGL_GL_40_EXTENSIONS_H
