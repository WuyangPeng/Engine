//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:39)

#ifndef SYSTEM_OPENGL_GL_ARB_ES_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_ARB_ES_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GLARBESExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"

namespace System
{
    // GL_ARB_ES2_compatibility

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbEs2Compatibility() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlClearDepthf(GLclampf d) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDepthRangef(GLclampf n, GLclampf f) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlReleaseShaderCompiler() noexcept;
    SYSTEM_HIDDEN_DECLARE void GlShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryformat, const void* binary, GLsizei length) noexcept;

    // GL_ARB_ES3_1_compatibility

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbEs31Compatibility() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlMemoryBarrierByRegion(GLbitfield barriers) noexcept;

    // GL_ARB_ES3_compatibility

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbEs3Compatibility() noexcept;

    void InitGlArbEs2Compatibility();
    void InitGlArbEs31Compatibility();
    void InitGlArbEs3Compatibility();

    void InitGlArbEs();
}

#endif  // SYSTEM_OPENGL_GL_ARB_ES_EXTENSIONS_H
