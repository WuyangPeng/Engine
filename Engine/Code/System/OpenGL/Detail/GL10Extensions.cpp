/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/03/02 20:49)

#include "System/SystemExport.h"

#include "GL10Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/Helper/EnumCast.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

/// OpenGL 1.0
namespace System
{
    auto existsOpenGL10 = ExistsOpenGLExtensions::Unknown;

#ifdef SYSTEM_PLATFORM_WIN32

    extern "C"
    {
        OPENGL_EXTERN void OPENGL_STDCALL glCullFace(GLenum mode);
        OPENGL_EXTERN void OPENGL_STDCALL glFrontFace(GLenum mode);
        OPENGL_EXTERN void OPENGL_STDCALL glHint(GLenum target, GLenum mode);
        OPENGL_EXTERN void OPENGL_STDCALL glLineWidth(GLfloat width);
        OPENGL_EXTERN void OPENGL_STDCALL glPointSize(GLfloat size);
        OPENGL_EXTERN void OPENGL_STDCALL glPolygonMode(GLenum face, GLenum mode);
        OPENGL_EXTERN void OPENGL_STDCALL glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
        OPENGL_EXTERN void OPENGL_STDCALL glTexParameterf(GLenum target, GLenum pName, GLfloat param);
        OPENGL_EXTERN void OPENGL_STDCALL glTexParameterfv(GLenum target, GLenum pName, const GLfloat* params);
        OPENGL_EXTERN void OPENGL_STDCALL glTexParameteri(GLenum target, GLenum pName, GLint param);
        OPENGL_EXTERN void OPENGL_STDCALL glTexParameteriv(GLenum target, GLenum pName, const GLint* params);
        OPENGL_EXTERN void OPENGL_STDCALL glTexImage1D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
        OPENGL_EXTERN void OPENGL_STDCALL glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
        OPENGL_EXTERN void OPENGL_STDCALL glDrawBuffer(GLenum buf);
        OPENGL_EXTERN void OPENGL_STDCALL glClear(GLbitfield mask);
        OPENGL_EXTERN void OPENGL_STDCALL glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
        OPENGL_EXTERN void OPENGL_STDCALL glClearStencil(GLint s);
        OPENGL_EXTERN void OPENGL_STDCALL glClearDepth(GLdouble depth);
        OPENGL_EXTERN void OPENGL_STDCALL glStencilMask(GLuint mask);
        OPENGL_EXTERN void OPENGL_STDCALL glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
        OPENGL_EXTERN void OPENGL_STDCALL glDepthMask(GLboolean flag);
        OPENGL_EXTERN void OPENGL_STDCALL glDisable(GLenum cap);
        OPENGL_EXTERN void OPENGL_STDCALL glEnable(GLenum cap);
        OPENGL_EXTERN void OPENGL_STDCALL glFinish(void);
        OPENGL_EXTERN void OPENGL_STDCALL glFlush(void);
        OPENGL_EXTERN void OPENGL_STDCALL glBlendFunc(GLenum sFactor, GLenum dFactor);
        OPENGL_EXTERN void OPENGL_STDCALL glLogicOp(GLenum opcode);
        OPENGL_EXTERN void OPENGL_STDCALL glStencilFunc(GLenum func, GLint ref, GLuint mask);
        OPENGL_EXTERN void OPENGL_STDCALL glStencilOp(GLenum fail, GLenum zFail, GLenum zPass);
        OPENGL_EXTERN void OPENGL_STDCALL glDepthFunc(GLenum func);
        OPENGL_EXTERN void OPENGL_STDCALL glPixelStoref(GLenum pName, GLfloat param);
        OPENGL_EXTERN void OPENGL_STDCALL glPixelStorei(GLenum pName, GLint param);
        OPENGL_EXTERN void OPENGL_STDCALL glReadBuffer(GLenum src);
        OPENGL_EXTERN void OPENGL_STDCALL glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels);
        OPENGL_EXTERN void OPENGL_STDCALL glGetBooleanv(GLenum pName, GLboolean* data);
        OPENGL_EXTERN void OPENGL_STDCALL glGetDoublev(GLenum pName, GLdouble* data);
        OPENGL_EXTERN GLenum OPENGL_STDCALL glGetError(void);
        OPENGL_EXTERN void OPENGL_STDCALL glGetFloatv(GLenum pName, GLfloat* data);
        OPENGL_EXTERN void OPENGL_STDCALL glGetIntegerv(GLenum pName, GLint* data);
        OPENGL_EXTERN const GLubyte* OPENGL_STDCALL glGetString(GLenum name);
        OPENGL_EXTERN void OPENGL_STDCALL glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
        OPENGL_EXTERN void OPENGL_STDCALL glGetTexParameterfv(GLenum target, GLenum pName, GLfloat* params);
        OPENGL_EXTERN void OPENGL_STDCALL glGetTexParameteriv(GLenum target, GLenum pName, GLint* params);
        OPENGL_EXTERN void OPENGL_STDCALL glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pName, GLfloat* params);
        OPENGL_EXTERN void OPENGL_STDCALL glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pName, GLint* params);
        OPENGL_EXTERN GLboolean OPENGL_STDCALL glIsEnabled(GLenum cap);
        OPENGL_EXTERN void OPENGL_STDCALL glDepthRange(GLdouble n, GLdouble f);
        OPENGL_EXTERN void OPENGL_STDCALL glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
    }

#else  // !SYSTEM_PLATFORM_WIN32

    PFNGLCULLFACEPROC glCullFace{ nullptr };
    PFNGLFRONTFACEPROC glFrontFace{ nullptr };
    PFNGLHINTPROC glHint{ nullptr };
    PFNGLLINEWIDTHPROC glLineWidth{ nullptr };
    PFNGLPOINTSIZEPROC glPointSize{ nullptr };
    PFNGLPOLYGONMODEPROC glPolygonMode{ nullptr };
    PFNGLSCISSORPROC glScissor{ nullptr };
    PFNGLTEXPARAMETERFPROC glTexParameterf{ nullptr };
    PFNGLTEXPARAMETERFVPROC glTexParameterfv{ nullptr };
    PFNGLTEXPARAMETERIPROC glTexParameteri{ nullptr };
    PFNGLTEXPARAMETERIVPROC glTexParameteriv{ nullptr };
    PFNGLTEXIMAGE1DPROC glTexImage1D{ nullptr };
    PFNGLTEXIMAGE2DPROC glTexImage2D{ nullptr };
    PFNGLDRAWBUFFERPROC glDrawBuffer{ nullptr };
    PFNGLCLEARPROC glClear{ nullptr };
    PFNGLCLEARCOLORPROC glClearColor{ nullptr };
    PFNGLCLEARSTENCILPROC glClearStencil{ nullptr };
    PFNGLCLEARDEPTHPROC glClearDepth{ nullptr };
    PFNGLSTENCILMASKPROC glStencilMask{ nullptr };
    PFNGLCOLORMASKPROC glColorMask{ nullptr };
    PFNGLDEPTHMASKPROC glDepthMask{ nullptr };
    PFNGLDISABLEPROC glDisable{ nullptr };
    PFNGLENABLEPROC glEnable{ nullptr };
    PFNGLFINISHPROC glFinish{ nullptr };
    PFNGLFLUSHPROC glFlush{ nullptr };
    PFNGLBLENDFUNCPROC glBlendFunc{ nullptr };
    PFNGLLOGICOPPROC glLogicOp{ nullptr };
    PFNGLSTENCILFUNCPROC glStencilFunc{ nullptr };
    PFNGLSTENCILOPPROC glStencilOp{ nullptr };
    PFNGLDEPTHFUNCPROC glDepthFunc{ nullptr };
    PFNGLPIXELSTOREFPROC glPixelStoref{ nullptr };
    PFNGLPIXELSTOREIPROC glPixelStorei{ nullptr };
    PFNGLREADBUFFERPROC glReadBuffer{ nullptr };
    PFNGLREADPIXELSPROC glReadPixels{ nullptr };
    PFNGLGETBOOLEANVPROC glGetBooleanv{ nullptr };
    PFNGLGETDOUBLEVPROC glGetDoublev{ nullptr };
    PFNGLGETERRORPROC glGetError{ nullptr };
    PFNGLGETFLOATVPROC glGetFloatv{ nullptr };
    PFNGLGETINTEGERVPROC glGetIntegerv{ nullptr };
    PFNGLGETSTRINGPROC glGetString{ nullptr };
    PFNGLGETTEXIMAGEPROC glGetTexImage{ nullptr };
    PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv{ nullptr };
    PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv{ nullptr };
    PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv{ nullptr };
    PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv{ nullptr };
    PFNGLISENABLEDPROC glIsEnabled{ nullptr };
    PFNGLDEPTHRANGEPROC glDepthRange{ nullptr };
    PFNGLVIEWPORTPROC glViewport{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL10() noexcept
{
    return existsOpenGL10;
}

void System::InitOpenGL10() noexcept
{
    if (OpenGLSystemVersion::Version10 <= GetOpenGLVersion())
    {
        existsOpenGL10 = ExistsOpenGLExtensions::Exists;

#ifndef SYSTEM_PLATFORM_WIN32

        SYSTEM_GET_FUNCTION(glCullFace);
        SYSTEM_GET_FUNCTION(glFrontFace);
        SYSTEM_GET_FUNCTION(glHint);
        SYSTEM_GET_FUNCTION(glLineWidth);
        SYSTEM_GET_FUNCTION(glPointSize);
        SYSTEM_GET_FUNCTION(glPolygonMode);
        SYSTEM_GET_FUNCTION(glScissor);
        SYSTEM_GET_FUNCTION(glTexParameterf);
        SYSTEM_GET_FUNCTION(glTexParameterfv);
        SYSTEM_GET_FUNCTION(glTexParameteri);
        SYSTEM_GET_FUNCTION(glTexParameteriv);
        SYSTEM_GET_FUNCTION(glTexImage1D);
        SYSTEM_GET_FUNCTION(glTexImage2D);
        SYSTEM_GET_FUNCTION(glDrawBuffer);
        SYSTEM_GET_FUNCTION(glClear);
        SYSTEM_GET_FUNCTION(glClearColor);
        SYSTEM_GET_FUNCTION(glClearStencil);
        SYSTEM_GET_FUNCTION(glClearDepth);
        SYSTEM_GET_FUNCTION(glStencilMask);
        SYSTEM_GET_FUNCTION(glColorMask);
        SYSTEM_GET_FUNCTION(glDepthMask);
        SYSTEM_GET_FUNCTION(glDisable);
        SYSTEM_GET_FUNCTION(glEnable);
        SYSTEM_GET_FUNCTION(glFinish);
        SYSTEM_GET_FUNCTION(glFlush);
        SYSTEM_GET_FUNCTION(glBlendFunc);
        SYSTEM_GET_FUNCTION(glLogicOp);
        SYSTEM_GET_FUNCTION(glStencilFunc);
        SYSTEM_GET_FUNCTION(glStencilOp);
        SYSTEM_GET_FUNCTION(glDepthFunc);
        SYSTEM_GET_FUNCTION(glPixelStoref);
        SYSTEM_GET_FUNCTION(glPixelStorei);
        SYSTEM_GET_FUNCTION(glReadBuffer);
        SYSTEM_GET_FUNCTION(glReadPixels);
        SYSTEM_GET_FUNCTION(glGetBooleanv);
        SYSTEM_GET_FUNCTION(glGetDoublev);
        SYSTEM_GET_FUNCTION(glGetError);
        SYSTEM_GET_FUNCTION(glGetFloatv);
        SYSTEM_GET_FUNCTION(glGetIntegerv);
        SYSTEM_GET_FUNCTION(glGetString);
        SYSTEM_GET_FUNCTION(glGetTexImage);
        SYSTEM_GET_FUNCTION(glGetTexParameterfv);
        SYSTEM_GET_FUNCTION(glGetTexParameteriv);
        SYSTEM_GET_FUNCTION(glGetTexLevelParameterfv);
        SYSTEM_GET_FUNCTION(glGetTexLevelParameteriv);
        SYSTEM_GET_FUNCTION(glIsEnabled);
        SYSTEM_GET_FUNCTION(glDepthRange);
        SYSTEM_GET_FUNCTION(glViewport);

#endif  // SYSTEM_PLATFORM_WIN32
    }
    else
    {
        existsOpenGL10 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLCullFace(GLenum mode) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glCullFace, mode);
}

void System::GLFrontFace(GLenum mode) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glFrontFace, mode);
}

void System::GLHint(GLenum target, GLenum mode) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glHint, target, mode);
}

void System::GLLineWidth(GLfloat width) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glLineWidth, width);
}

void System::GLPointSize(GLfloat size) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glPointSize, size);
}

void System::GLPolygonMode(GLenum face, GLenum mode) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glPolygonMode, face, mode);
}

void System::GLScissor(GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_4(glScissor, x, y, width, height);
}

void System::GLTexParameterF(GLenum target, GLenum pName, GLfloat param) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_3(glTexParameterf, target, pName, param);
}

void System::GLTexParameterFv(GLenum target, GLenum pName, const GLfloat* params) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_3(glTexParameterfv, target, pName, params);
}

void System::GLTexParameterI(GLenum target, GLenum pName, GLint param) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_3(glTexParameteri, target, pName, param);
}

void System::GLTexParameterIv(GLenum target, GLenum pName, const GLint* params) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_3(glTexParameteriv, target, pName, params);
}

void System::GLTexImage1D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_8(glTexImage1D, target, level, internalFormat, width, border, format, type, pixels);
}

void System::GLTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_9(glTexImage2D, target, level, internalFormat, width, height, border, format, type, pixels);
}

void System::GLDrawBuffer(GLenum buf) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glDrawBuffer, buf);
}

void System::GLClear(GLbitfield mask) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glClear, mask);
}

void System::GLClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_4(glClearColor, red, green, blue, alpha);
}

void System::GLClearStencil(GLint s) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glClearStencil, s);
}

void System::GLClearDepth(GLdouble depth) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glClearDepth, depth);
}

void System::GLStencilMask(GLuint mask) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glStencilMask, mask);
}

void System::GLColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_4(glColorMask, red, green, blue, alpha);
}

void System::GLDepthMask(GLboolean flag) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glDepthMask, flag);
}

void System::GLDisable(GLenum cap) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glDisable, cap);
}

void System::GLEnable(GLenum cap) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glEnable, cap);
}

void System::GLFinish() noexcept
{
    SYSTEM_PREVIOUSLY_BODY_0(glFinish);
}

void System::GLFlush() noexcept
{
    SYSTEM_PREVIOUSLY_BODY_0(glFlush);
}

void System::GLBlendFunc(GLenum sFactor, GLenum dFactor) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glBlendFunc, sFactor, dFactor);
}

void System::GLLogicOp(GLenum opcode) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glLogicOp, opcode);
}

void System::GLStencilFunc(GLenum func, GLint ref, GLuint mask) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_3(glStencilFunc, func, ref, mask);
}

void System::GLStencilOp(GLenum fail, GLenum zFail, GLenum zPass) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_3(glStencilOp, fail, zFail, zPass);
}

void System::GLDepthFunc(GLenum func) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glDepthFunc, func);
}

void System::GLPixelStoreF(GLenum pName, GLfloat param) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glPixelStoref, pName, param);
}

void System::GLPixelStoreI(GLenum pName, GLint param) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glPixelStorei, pName, param);
}

void System::GLReadBuffer(GLenum src) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1(glReadBuffer, src);
}

void System::GLReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_7(glReadPixels, x, y, width, height, format, type, pixels);
}

void System::GLGetBooleanV(GLenum pName, GLboolean* data) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glGetBooleanv, pName, data);
}

void System::GLGetDoubleV(GLenum pName, GLdouble* data) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glGetDoublev, pName, data);
}

GLenum System::GLGetError() noexcept
{
    SYSTEM_PREVIOUSLY_BODY_0_RESULT(glGetError, EnumCastUnderlying(OpenGLErrorCode::NoError));
}

void System::GLGetFloatV(GLenum pName, GLfloat* data) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glGetFloatv, pName, data);
}

void System::GLGetIntegerV(GLenum pName, GLint* data) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glGetIntegerv, pName, data);
}

const GLubyte* System::GLGetString(GLenum name) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1_RESULT(glGetString, name, nullptr);
}

void System::GLGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_5(glGetTexImage, target, level, format, type, pixels);
}

void System::GLGetTexParameterFv(GLenum target, GLenum pName, GLfloat* params) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_3(glGetTexParameterfv, target, pName, params);
}

void System::GLGetTexParameterIv(GLenum target, GLenum pName, GLint* params) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_3(glGetTexParameteriv, target, pName, params);
}

void System::GLGetTexLevelParameterFv(GLenum target, GLint level, GLenum pName, GLfloat* params) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_4(glGetTexLevelParameterfv, target, level, pName, params);
}

void System::GLGetTexLevelParameterIv(GLenum target, GLint level, GLenum pName, GLint* params) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_4(glGetTexLevelParameteriv, target, level, pName, params);
}

GLboolean System::GLIsEnabled(GLenum cap) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1_RESULT(glIsEnabled, cap, GL_FALSE);
}

void System::GLDepthRange(GLdouble n, GLdouble f) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glDepthRange, n, f);
}

void System::GLViewport(GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_4(glViewport, x, y, width, height);
}