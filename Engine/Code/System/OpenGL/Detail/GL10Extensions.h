/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 14:53)

#ifndef SYSTEM_OPENGL_GL_10_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_10_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 1.0
    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL10() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitOpenGL10() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLCullFace(GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFrontFace(GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLHint(GLenum target, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLLineWidth(GLfloat width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPointSize(GLfloat size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPolygonMode(GLenum face, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLScissor(GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexParameterF(GLenum target, GLenum pName, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexParameterFv(GLenum target, GLenum pName, const GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexParameterI(GLenum target, GLenum pName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexParameterIv(GLenum target, GLenum pName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexImage1D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawBuffer(GLenum buf) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClear(GLbitfield mask) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearStencil(GLint s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearDepth(GLdouble depth) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLStencilMask(GLuint mask) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDepthMask(GLboolean flag) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDisable(GLenum cap) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLEnable(GLenum cap) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFinish() noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFlush() noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlendFunc(GLenum sFactor, GLenum dFactor) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLLogicOp(GLenum opcode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLStencilFunc(GLenum func, GLint ref, GLuint mask) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLStencilOp(GLenum fail, GLenum zFail, GLenum zPass) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDepthFunc(GLenum func) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPixelStoreF(GLenum pName, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPixelStoreI(GLenum pName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLReadBuffer(GLenum src) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetBooleanV(GLenum pName, GLboolean* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetDoubleV(GLenum pName, GLdouble* data) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLenum GLGetError() noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetFloatV(GLenum pName, GLfloat* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetIntegerV(GLenum pName, GLint* data) noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR const GLubyte* GLGetString(GLenum name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexParameterFv(GLenum target, GLenum pName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexParameterIv(GLenum target, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexLevelParameterFv(GLenum target, GLint level, GLenum pName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexLevelParameterIv(GLenum target, GLint level, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsEnabled(GLenum cap) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDepthRange(GLdouble n, GLdouble f) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLViewport(GLint x, GLint y, GLsizei width, GLsizei height) noexcept;

#ifdef SYSTEM_PLATFORM_WIN32

    extern "C"
    {
        OPENGL_EXTERN GLenum OPENGL_STDCALL glGetError(void);
    }

#else  // !SYSTEM_PLATFORM_WIN32

    extern PFNGLGETERRORPROC glGetError;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_OPENGL_GL_10_EXTENSIONS_H
