///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 11:20)

#ifndef SYSTEM_OPENGL_GL_10_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_10_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 1.0
    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL10() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitOpenGL10() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLCullFace(GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFrontFace(GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLHint(GLenum target, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLLineWidth(GLfloat width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPointSize(GLfloat size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPolygonMode(GLenum face, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLScissor(GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexParameterf(GLenum target, GLenum pname, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexParameterfv(GLenum target, GLenum pname, const GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexParameteri(GLenum target, GLenum pname, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexParameteriv(GLenum target, GLenum pname, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) noexcept;
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
    SYSTEM_HIDDEN_DECLARE void GLBlendFunc(GLenum sfactor, GLenum dfactor) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLLogicOp(GLenum opcode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLStencilFunc(GLenum func, GLint ref, GLuint mask) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLStencilOp(GLenum fail, GLenum zfail, GLenum zpass) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDepthFunc(GLenum func) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPixelStoref(GLenum pname, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPixelStorei(GLenum pname, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLReadBuffer(GLenum src) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetBooleanv(GLenum pname, GLboolean* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetDoublev(GLenum pname, GLdouble* data) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLenum GLGetError() noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetFloatv(GLenum pname, GLfloat* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetIntegerv(GLenum pname, GLint* data) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD const GLubyte* GLGetString(GLenum name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexParameteriv(GLenum target, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params) noexcept;
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
