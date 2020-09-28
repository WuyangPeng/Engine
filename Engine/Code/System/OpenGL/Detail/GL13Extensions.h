//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:31)

#ifndef SYSTEM_OPENGL_GL_13_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_13_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GL13ExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/OpenGL/Using/GL13ExtensionsUsing.h"

namespace System
{
    // OpenGL 1.3

    extern PgglActiveTexture gglActiveTexture;
    extern PgglClientActiveTexture gglClientActiveTexture;
    extern PgglMultiTexCoord1d gglMultiTexCoord1d;
    extern PgglMultiTexCoord1dv gglMultiTexCoord1dv;
    extern PgglMultiTexCoord1f gglMultiTexCoord1f;
    extern PgglMultiTexCoord1fv gglMultiTexCoord1fv;
    extern PgglMultiTexCoord1i gglMultiTexCoord1i;
    extern PgglMultiTexCoord1iv gglMultiTexCoord1iv;
    extern PgglMultiTexCoord1s gglMultiTexCoord1s;
    extern PgglMultiTexCoord1sv gglMultiTexCoord1sv;
    extern PgglMultiTexCoord2d gglMultiTexCoord2d;
    extern PgglMultiTexCoord2dv gglMultiTexCoord2dv;
    extern PgglMultiTexCoord2f gglMultiTexCoord2f;
    extern PgglMultiTexCoord2fv gglMultiTexCoord2fv;
    extern PgglMultiTexCoord2i gglMultiTexCoord2i;
    extern PgglMultiTexCoord2iv gglMultiTexCoord2iv;
    extern PgglMultiTexCoord2s gglMultiTexCoord2s;
    extern PgglMultiTexCoord2sv gglMultiTexCoord2sv;
    extern PgglMultiTexCoord3d gglMultiTexCoord3d;
    extern PgglMultiTexCoord3dv gglMultiTexCoord3dv;
    extern PgglMultiTexCoord3f gglMultiTexCoord3f;
    extern PgglMultiTexCoord3fv gglMultiTexCoord3fv;
    extern PgglMultiTexCoord3i gglMultiTexCoord3i;
    extern PgglMultiTexCoord3iv gglMultiTexCoord3iv;
    extern PgglMultiTexCoord3s gglMultiTexCoord3s;
    extern PgglMultiTexCoord3sv gglMultiTexCoord3sv;
    extern PgglMultiTexCoord4d gglMultiTexCoord4d;
    extern PgglMultiTexCoord4dv gglMultiTexCoord4dv;
    extern PgglMultiTexCoord4f gglMultiTexCoord4f;
    extern PgglMultiTexCoord4fv gglMultiTexCoord4fv;
    extern PgglMultiTexCoord4i gglMultiTexCoord4i;
    extern PgglMultiTexCoord4iv gglMultiTexCoord4iv;
    extern PgglMultiTexCoord4s gglMultiTexCoord4s;
    extern PgglMultiTexCoord4sv gglMultiTexCoord4sv;
    extern PgglLoadTransposeMatrixf gglLoadTransposeMatrixf;
    extern PgglLoadTransposeMatrixd gglLoadTransposeMatrixd;
    extern PgglMultTransposeMatrixf gglMultTransposeMatrixf;
    extern PgglMultTransposeMatrixd gglMultTransposeMatrixd;
    extern PgglSampleCoverage gglSampleCoverage;
    extern PgglCompressedTexImage3D gglCompressedTexImage3D;
    extern PgglCompressedTexImage2D gglCompressedTexImage2D;
    extern PgglCompressedTexImage1D gglCompressedTexImage1D;
    extern PgglCompressedTexSubImage3D gglCompressedTexSubImage3D;
    extern PgglCompressedTexSubImage2D gglCompressedTexSubImage2D;
    extern PgglCompressedTexSubImage1D gglCompressedTexSubImage1D;
    extern PgglGetCompressedTexImage gglGetCompressedTexImage;

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL13() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlActiveTexture(GLenum texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClientActiveTexture(GLenum texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1d(GLenum target, GLdouble s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1dv(GLenum target, const GLdouble* s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1f(GLenum target, GLfloat s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1fv(GLenum target, const GLfloat* s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1i(GLenum target, GLint s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1iv(GLenum target, const GLint* s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1s(GLenum target, GLshort s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1sv(GLenum target, const GLshort* s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2dv(GLenum target, const GLdouble* dt) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2fv(GLenum target, const GLfloat* st) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2i(GLenum target, GLint s, GLint t) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2iv(GLenum target, const GLint* st) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2s(GLenum target, GLshort s, GLshort st) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2sv(GLenum target, const GLshort* st) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3dv(GLenum target, const GLdouble* str) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3fv(GLenum target, const GLfloat* str) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3iv(GLenum target, const GLint* str) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3s(GLenum target, GLshort s, GLshort st, GLshort r) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3sv(GLenum target, const GLshort* str) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4dv(GLenum target, const GLdouble* strq) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4fv(GLenum target, const GLfloat* strq) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4iv(GLenum target, const GLint* strq) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4s(GLenum target, GLshort s, GLshort st, GLshort r, GLshort q) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4sv(GLenum target, const GLshort* strq) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlLoadTransposeMatrixd(const GLdouble* matrix) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlLoadTransposeMatrixf(const GLfloat* matrix) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultTransposeMatrixd(const GLdouble* matrix) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultTransposeMatrixf(const GLfloat* matrix) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSampleCoverage(GLclampf value, GLboolean invert) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTexImage1D(GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTexImage2D(GLenum target, GLint level, GLenum internalFormat, GLsizei width,
                                                      GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTexImage3D(GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLsizei height,
                                                      GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTexSubImage1D(GLenum target, GLint level, GLint xOffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTexSubImage2D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLsizei width,
                                                         GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTexSubImage3D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width,
                                                         GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetCompressedTexImage(GLenum target, GLint level, GLvoid* data) noexcept;

    void InitOpenGL13();
}

#endif  // SYSTEM_OPENGL_GL_13_EXTENSIONS_H
