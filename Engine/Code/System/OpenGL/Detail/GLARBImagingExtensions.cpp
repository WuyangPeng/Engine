//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 18:56)

#include "System/SystemExport.h"

#include "GLARBImagingExtensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// 成像子集 (GL_ARB_imaging)

namespace System
{
    auto g_ExistsGlArbImaging = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsGlArbImaging() noexcept
{
    return g_ExistsGlArbImaging;
}

System::PgglBlendColor System::gglBlendColor{ nullptr };
System::PgglBlendEquation System::gglBlendEquation{ nullptr };
System::PgglColorTable System::gglColorTable{ nullptr };
System::PgglColorTableParameterfv System::gglColorTableParameterfv{ nullptr };
System::PgglColorTableParameteriv System::gglColorTableParameteriv{ nullptr };
System::PgglCopyColorTable System::gglCopyColorTable{ nullptr };
System::PgglGetColorTable System::gglGetColorTable{ nullptr };
System::PgglGetColorTableParameterfv System::gglGetColorTableParameterfv{ nullptr };
System::PgglGetColorTableParameteriv System::gglGetColorTableParameteriv{ nullptr };
System::PgglColorSubTable System::gglColorSubTable{ nullptr };
System::PgglCopyColorSubTable System::gglCopyColorSubTable{ nullptr };
System::PgglConvolutionFilter1D System::gglConvolutionFilter1D{ nullptr };
System::PgglConvolutionFilter2D System::gglConvolutionFilter2D{ nullptr };
System::PgglConvolutionParameterf System::gglConvolutionParameterf{ nullptr };
System::PgglConvolutionParameterfv System::gglConvolutionParameterfv{ nullptr };
System::PgglConvolutionParameteri System::gglConvolutionParameteri{ nullptr };
System::PgglConvolutionParameteriv System::gglConvolutionParameteriv{ nullptr };
System::PgglCopyConvolutionFilter1D System::gglCopyConvolutionFilter1D{ nullptr };
System::PgglCopyConvolutionFilter2D System::gglCopyConvolutionFilter2D{ nullptr };
System::PgglGetConvolutionFilter System::gglGetConvolutionFilter{ nullptr };
System::PgglGetConvolutionParameterfv System::gglGetConvolutionParameterfv{ nullptr };
System::PgglGetConvolutionParameteriv System::gglGetConvolutionParameteriv{ nullptr };
System::PgglGetSeparableFilter System::gglGetSeparableFilter{ nullptr };
System::PgglSeparableFilter2D System::gglSeparableFilter2D{ nullptr };
System::PgglGetHistogram System::gglGetHistogram{ nullptr };
System::PgglGetHistogramParameterfv System::gglGetHistogramParameterfv{ nullptr };
System::PgglGetHistogramParameteriv System::gglGetHistogramParameteriv{ nullptr };
System::PgglGetMinmax System::gglGetMinmax{ nullptr };
System::PgglGetMinmaxParameterfv System::gglGetMinmaxParameterfv{ nullptr };
System::PgglGetMinmaxParameteriv System::gglGetMinmaxParameteriv{ nullptr };
System::PgglHistogram System::gglHistogram{ nullptr };
System::PgglMinmax System::gglMinmax{ nullptr };
System::PgglResetHistogram System::gglResetHistogram{ nullptr };
System::PgglResetMinmax System::gglResetMinmax{ nullptr };

void System::GlBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) noexcept
{
    SYSTEM_BODY_4(gglBlendColor, red, green, blue, alpha);
}

void System::GlBlendEquation(GLenum mode) noexcept
{
    SYSTEM_BODY_1(gglBlendEquation, mode);
}

void System::GlColorTable(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid* table) noexcept
{
    SYSTEM_BODY_6(gglColorTable, target, internalFormat, width, format, type, table);
}

void System::GlColorTableParameterfv(GLenum target, GLenum name, const GLfloat* param) noexcept
{
    SYSTEM_BODY_3(gglColorTableParameterfv, target, name, param);
}

void System::GlColorTableParameteriv(GLenum target, GLenum name, const GLint* param) noexcept
{
    SYSTEM_BODY_3(gglColorTableParameteriv, target, name, param);
}

void System::GlCopyColorTable(GLenum target, GLenum internalFormat, GLint x, GLint y, GLsizei width) noexcept
{
    SYSTEM_BODY_5(gglCopyColorTable, target, internalFormat, x, y, width);
}

void System::GlGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid* table) noexcept
{
    SYSTEM_BODY_4(gglGetColorTable, target, format, type, table);
}

void System::GlGetColorTableParameterfv(GLenum target, GLenum name, GLfloat* param) noexcept
{
    SYSTEM_BODY_3(gglGetColorTableParameterfv, target, name, param);
}

void System::GlGetColorTableParameteriv(GLenum target, GLenum name, GLint* param) noexcept
{
    SYSTEM_BODY_3(gglGetColorTableParameteriv, target, name, param);
}

void System::GlColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid* data) noexcept
{
    SYSTEM_BODY_6(gglColorSubTable, target, start, count, format, type, data);
}

void System::GlCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) noexcept
{
    SYSTEM_BODY_5(gglCopyColorSubTable, target, start, x, y, width);
}

void System::GlConvolutionFilter1D(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid* image) noexcept
{
    SYSTEM_BODY_6(gglConvolutionFilter1D, target, internalFormat, width, format, type, image);
}

void System::GlConvolutionFilter2D(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* image) noexcept
{
    SYSTEM_BODY_7(gglConvolutionFilter2D, target, internalFormat, width, height, format, type, image);
}

void System::GlConvolutionParameterf(GLenum target, GLenum name, GLfloat param) noexcept
{
    SYSTEM_BODY_3(gglConvolutionParameterf, target, name, param);
}

void System::GlConvolutionParameterfv(GLenum target, GLenum name, const GLfloat* param) noexcept
{
    SYSTEM_BODY_3(gglConvolutionParameterfv, target, name, param);
}

void System::GlConvolutionParameteri(GLenum target, GLenum name, GLint param) noexcept
{
    SYSTEM_BODY_3(gglConvolutionParameteri, target, name, param);
}

void System::GlConvolutionParameteriv(GLenum target, GLenum name, const GLint* param) noexcept
{
    SYSTEM_BODY_3(gglConvolutionParameteriv, target, name, param);
}

void System::GlCopyConvolutionFilter1D(GLenum target, GLenum internalFormat, GLint x, GLint y, GLsizei width) noexcept
{
    SYSTEM_BODY_5(gglCopyConvolutionFilter1D, target, internalFormat, x, y, width);
}

void System::GlCopyConvolutionFilter2D(GLenum target, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_6(gglCopyConvolutionFilter2D, target, internalFormat, x, y, width, height);
}

void System::GlGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid* image) noexcept
{
    SYSTEM_BODY_4(gglGetConvolutionFilter, target, format, type, image);
}

void System::GlGetConvolutionParameterfv(GLenum target, GLenum name, GLfloat* param) noexcept
{
    SYSTEM_BODY_3(gglGetConvolutionParameterfv, target, name, param);
}

void System::GlGetConvolutionParameteriv(GLenum target, GLenum name, GLint* param) noexcept
{
    SYSTEM_BODY_3(gglGetConvolutionParameteriv, target, name, param);
}

void System::GlGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid* row, GLvoid* column, GLvoid* span) noexcept
{
    SYSTEM_BODY_6(gglGetSeparableFilter, target, format, type, row, column, span);
}

void System::GlSeparableFilter2D(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* row, const GLvoid* column) noexcept
{
    SYSTEM_BODY_8(gglSeparableFilter2D, target, internalFormat, width, height, format, type, row, column);
}

void System::GlGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values) noexcept
{
    SYSTEM_BODY_5(gglGetHistogram, target, reset, format, type, values);
}

void System::GlGetHistogramParameterfv(GLenum target, GLenum name, GLfloat* param) noexcept
{
    SYSTEM_BODY_3(gglGetHistogramParameterfv, target, name, param);
}

void System::GlGetHistogramParameteriv(GLenum target, GLenum name, GLint* param) noexcept
{
    SYSTEM_BODY_3(gglGetHistogramParameteriv, target, name, param);
}

void System::GlGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values) noexcept
{
    SYSTEM_BODY_5(gglGetMinmax, target, reset, format, type, values);
}

void System::GlGetMinmaxParameterfv(GLenum target, GLenum name, GLfloat* param) noexcept
{
    SYSTEM_BODY_3(gglGetMinmaxParameterfv, target, name, param);
}

void System::GlGetMinmaxParameteriv(GLenum target, GLenum name, GLint* param) noexcept
{
    SYSTEM_BODY_3(gglGetMinmaxParameteriv, target, name, param);
}

void System::GlHistogram(GLenum target, GLsizei width, GLenum internalFormat, GLboolean sink) noexcept
{
    SYSTEM_BODY_4(gglHistogram, target, width, internalFormat, sink);
}

void System::GlMinmax(GLenum target, GLenum internalFormat, GLboolean sink) noexcept
{
    SYSTEM_BODY_3(gglMinmax, target, internalFormat, sink);
}

void System::GlResetHistogram(GLenum target) noexcept
{
    SYSTEM_BODY_1(gglResetHistogram, target);
}

void System::GlResetMinmax(GLenum target) noexcept
{
    SYSTEM_BODY_1(gglResetMinmax, target);
}

void System::InitGlArbImaging()
{
    if (IsOpenGLSupportsExtension("GL_ARB_imaging"))
    {
        g_ExistsGlArbImaging = ExistsOpenGLExtensions::Exists;

        // GL_SGI_color_table
        SYSTEM_GET_FUNCTION(gglColorTableParameterfv);
        SYSTEM_GET_FUNCTION(gglColorTableParameteriv);
        SYSTEM_GET_FUNCTION(gglCopyColorTable);

        // GL_SGI_color_table and GL_EXT_paletted_texture
        SYSTEM_GET_FUNCTION(gglColorTable);
        SYSTEM_GET_FUNCTION(gglGetColorTable);
        SYSTEM_GET_FUNCTION(gglGetColorTableParameterfv);
        SYSTEM_GET_FUNCTION(gglGetColorTableParameteriv);

        // GL_EXT_color_subtable
        SYSTEM_GET_FUNCTION(gglColorSubTable);
        SYSTEM_GET_FUNCTION(gglCopyColorSubTable);

        // GL_EXT_convolution
        SYSTEM_GET_FUNCTION(gglConvolutionFilter1D);
        SYSTEM_GET_FUNCTION(gglConvolutionFilter2D);
        SYSTEM_GET_FUNCTION(gglConvolutionParameterf);
        SYSTEM_GET_FUNCTION(gglConvolutionParameterfv);
        SYSTEM_GET_FUNCTION(gglConvolutionParameteri);
        SYSTEM_GET_FUNCTION(gglConvolutionParameteriv);
        SYSTEM_GET_FUNCTION(gglCopyConvolutionFilter1D);
        SYSTEM_GET_FUNCTION(gglCopyConvolutionFilter2D);
        SYSTEM_GET_FUNCTION(gglGetConvolutionFilter);
        SYSTEM_GET_FUNCTION(gglGetConvolutionParameterfv);
        SYSTEM_GET_FUNCTION(gglGetConvolutionParameteriv);
        SYSTEM_GET_FUNCTION(gglGetSeparableFilter);
        SYSTEM_GET_FUNCTION(gglSeparableFilter2D);

        // GL_EXT_histogram
        SYSTEM_GET_FUNCTION(gglGetHistogram);
        SYSTEM_GET_FUNCTION(gglGetHistogramParameterfv);
        SYSTEM_GET_FUNCTION(gglGetHistogramParameteriv);
        SYSTEM_GET_FUNCTION(gglGetMinmax);
        SYSTEM_GET_FUNCTION(gglGetMinmaxParameterfv);
        SYSTEM_GET_FUNCTION(gglGetMinmaxParameteriv);
        SYSTEM_GET_FUNCTION(gglHistogram);
        SYSTEM_GET_FUNCTION(gglMinmax);
        SYSTEM_GET_FUNCTION(gglResetHistogram);
        SYSTEM_GET_FUNCTION(gglResetMinmax);

        // GL_EXT_blend_color
        SYSTEM_GET_FUNCTION(gglBlendColor);

        // GL_EXT_blend_minmax
        SYSTEM_GET_FUNCTION(gglBlendEquation);
    }
    else
    {
        g_ExistsGlArbImaging = ExistsOpenGLExtensions::NotExist;
    }
}
