//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 16:36)

#include "System/SystemExport.h"

#include "GL14Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Using/GL14ExtensionsUsing.h"

// OpenGL 1.4

namespace System
{
    auto g_ExistsOpenGL14 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL14() noexcept
{
    return g_ExistsOpenGL14;
}

System::PgglBlendFuncSeparate System::gglBlendFuncSeparate{ nullptr };
System::PgglFogCoordf System::gglFogCoordf{ nullptr };
System::PgglFogCoordfv System::gglFogCoordfv{ nullptr };
System::PgglFogCoordd System::gglFogCoordd{ nullptr };
System::PgglFogCoorddv System::gglFogCoorddv{ nullptr };
System::PgglFogCoordPointer System::gglFogCoordPointer{ nullptr };
System::PgglMultiDrawArrays System::gglMultiDrawArrays{ nullptr };
System::PgglMultiDrawElements System::gglMultiDrawElements{ nullptr };
System::PgglPointParameterf System::gglPointParameterf{ nullptr };
System::PgglPointParameterfv System::gglPointParameterfv{ nullptr };
System::PgglPointParameteri System::gglPointParameteri{ nullptr };
System::PgglPointParameteriv System::gglPointParameteriv{ nullptr };
System::PgglSecondaryColor3b System::gglSecondaryColor3b{ nullptr };
System::PgglSecondaryColor3bv System::gglSecondaryColor3bv{ nullptr };
System::PgglSecondaryColor3d System::gglSecondaryColor3d{ nullptr };
System::PgglSecondaryColor3dv System::gglSecondaryColor3dv{ nullptr };
System::PgglSecondaryColor3f System::gglSecondaryColor3f{ nullptr };
System::PgglSecondaryColor3fv System::gglSecondaryColor3fv{ nullptr };
System::PgglSecondaryColor3i System::gglSecondaryColor3i{ nullptr };
System::PgglSecondaryColor3iv System::gglSecondaryColor3iv{ nullptr };
System::PgglSecondaryColor3s System::gglSecondaryColor3s{ nullptr };
System::PgglSecondaryColor3sv System::gglSecondaryColor3sv{ nullptr };
System::PgglSecondaryColor3ub System::gglSecondaryColor3ub{ nullptr };
System::PgglSecondaryColor3ubv System::gglSecondaryColor3ubv{ nullptr };
System::PgglSecondaryColor3ui System::gglSecondaryColor3ui{ nullptr };
System::PgglSecondaryColor3uiv System::gglSecondaryColor3uiv{ nullptr };
System::PgglSecondaryColor3us System::gglSecondaryColor3us{ nullptr };
System::PgglSecondaryColor3usv System::gglSecondaryColor3usv{ nullptr };
System::PgglSecondaryColorPointer System::gglSecondaryColorPointer{ nullptr };
System::PgglWindowPos2d System::gglWindowPos2d{ nullptr };
System::PgglWindowPos2dv System::gglWindowPos2dv{ nullptr };
System::PgglWindowPos2f System::gglWindowPos2f{ nullptr };
System::PgglWindowPos2fv System::gglWindowPos2fv{ nullptr };
System::PgglWindowPos2i System::gglWindowPos2i{ nullptr };
System::PgglWindowPos2iv System::gglWindowPos2iv{ nullptr };
System::PgglWindowPos2s System::gglWindowPos2s{ nullptr };
System::PgglWindowPos2sv System::gglWindowPos2sv{ nullptr };
System::PgglWindowPos3d System::gglWindowPos3d{ nullptr };
System::PgglWindowPos3dv System::gglWindowPos3dv{ nullptr };
System::PgglWindowPos3f System::gglWindowPos3f{ nullptr };
System::PgglWindowPos3fv System::gglWindowPos3fv{ nullptr };
System::PgglWindowPos3i System::gglWindowPos3i{ nullptr };
System::PgglWindowPos3iv System::gglWindowPos3iv{ nullptr };
System::PgglWindowPos3s System::gglWindowPos3s{ nullptr };
System::PgglWindowPos3sv System::gglWindowPos3sv{ nullptr };

void System::GlBlendFuncSeparate(GLenum srcFactorRGB, GLenum dstFactorRGB, GLenum srcFactorA, GLenum dstFactorA) noexcept
{
    SYSTEM_BODY_4(gglBlendFuncSeparate, srcFactorRGB, dstFactorRGB, srcFactorA, dstFactorA);
}

void System::GlFogCoordd(GLdouble coord) noexcept
{
    SYSTEM_BODY_1(gglFogCoordd, coord);
}

void System::GlFogCoorddv(const GLdouble* coord) noexcept
{
    SYSTEM_BODY_1(gglFogCoorddv, coord);
}

void System::GlFogCoordf(GLfloat coord) noexcept
{
    SYSTEM_BODY_1(gglFogCoordf, coord);
}

void System::GlFogCoordfv(const GLfloat* coord) noexcept
{
    SYSTEM_BODY_1(gglFogCoordfv, coord);
}

void System::GlFogCoordPointer(GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
    SYSTEM_BODY_3(gglFogCoordPointer, type, stride, pointer);
}

void System::GlMultiDrawArrays(GLenum mode, GLint* first, GLsizei* count, GLsizei primitiveCount) noexcept
{
    SYSTEM_BODY_4(gglMultiDrawArrays, mode, first, count, primitiveCount);
}

void System::GlMultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei primitiveCount) noexcept
{
    SYSTEM_BODY_5(gglMultiDrawElements, mode, count, type, indices, primitiveCount);
}

void System::GlPointParameterf(GLenum name, GLfloat param) noexcept
{
    SYSTEM_BODY_2(gglPointParameterf, name, param);
}

void System::GlPointParameterfv(GLenum name, const GLfloat* param) noexcept
{
    SYSTEM_BODY_2(gglPointParameterfv, name, param);
}

void System::GlPointParameteri(GLenum name, int param) noexcept
{
    SYSTEM_BODY_2(gglPointParameteri, name, param);
}

void System::GlPointParameteriv(GLenum name, const GLint* param) noexcept
{
    SYSTEM_BODY_2(gglPointParameteriv, name, param);
}

void System::GlSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) noexcept
{
    SYSTEM_BODY_3(gglSecondaryColor3b, red, green, blue);
}

void System::GlSecondaryColor3bv(const GLbyte* rgb) noexcept
{
    SYSTEM_BODY_1(gglSecondaryColor3bv, rgb);
}

void System::GlSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) noexcept
{
    SYSTEM_BODY_3(gglSecondaryColor3d, red, green, blue);
}

void System::GlSecondaryColor3dv(const GLdouble* rgb) noexcept
{
    SYSTEM_BODY_1(gglSecondaryColor3dv, rgb);
}

void System::GlSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) noexcept
{
    SYSTEM_BODY_3(gglSecondaryColor3f, red, green, blue);
}

void System::GlSecondaryColor3fv(const GLfloat* rgb) noexcept
{
    SYSTEM_BODY_1(gglSecondaryColor3fv, rgb);
}

void System::GlSecondaryColor3i(GLint red, GLint green, GLint blue) noexcept
{
    SYSTEM_BODY_3(gglSecondaryColor3i, red, green, blue);
}

void System::GlSecondaryColor3iv(const GLint* rgb) noexcept
{
    SYSTEM_BODY_1(gglSecondaryColor3iv, rgb);
}

void System::GlSecondaryColor3s(GLshort red, GLshort green, GLshort blue) noexcept
{
    SYSTEM_BODY_3(gglSecondaryColor3s, red, green, blue);
}

void System::GlSecondaryColor3sv(const GLshort* rgb) noexcept
{
    SYSTEM_BODY_1(gglSecondaryColor3sv, rgb);
}

void System::GlSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) noexcept
{
    SYSTEM_BODY_3(gglSecondaryColor3ub, red, green, blue);
}

void System::GlSecondaryColor3ubv(const GLubyte* rgb) noexcept
{
    SYSTEM_BODY_1(gglSecondaryColor3ubv, rgb);
}

void System::GlSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) noexcept
{
    SYSTEM_BODY_3(gglSecondaryColor3ui, red, green, blue);
}

void System::GlSecondaryColor3uiv(const GLuint* rgb) noexcept
{
    SYSTEM_BODY_1(gglSecondaryColor3uiv, rgb);
}

void System::GlSecondaryColor3us(GLushort red, GLushort green, GLushort blue) noexcept
{
    SYSTEM_BODY_3(gglSecondaryColor3us, red, green, blue);
}

void System::GlSecondaryColor3usv(const GLushort* rgb) noexcept
{
    SYSTEM_BODY_1(gglSecondaryColor3usv, rgb);
}

void System::GlSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
    SYSTEM_BODY_4(gglSecondaryColorPointer, size, type, stride, pointer);
}

void System::GlWindowPos2d(GLdouble x, GLdouble y) noexcept
{
    SYSTEM_BODY_2(gglWindowPos2d, x, y);
}

void System::GlWindowPos2dv(const GLdouble* xy) noexcept
{
    SYSTEM_BODY_1(gglWindowPos2dv, xy);
}

void System::GlWindowPos2f(GLfloat x, GLfloat y) noexcept
{
    SYSTEM_BODY_2(gglWindowPos2f, x, y);
}

void System::GlWindowPos2fv(const GLfloat* xy) noexcept
{
    SYSTEM_BODY_1(gglWindowPos2fv, xy);
}

void System::GlWindowPos2i(GLint x, GLint y) noexcept
{
    SYSTEM_BODY_2(gglWindowPos2i, x, y);
}

void System::GlWindowPos2iv(const GLint* xy) noexcept
{
    SYSTEM_BODY_1(gglWindowPos2iv, xy);
}

void System::GlWindowPos2s(GLshort x, GLshort y) noexcept
{
    SYSTEM_BODY_2(gglWindowPos2s, x, y);
}

void System::GlWindowPos2sv(const GLshort* xy) noexcept
{
    SYSTEM_BODY_1(gglWindowPos2sv, xy);
}

void System::GlWindowPos3d(GLdouble x, GLdouble y, GLdouble z) noexcept
{
    SYSTEM_BODY_3(gglWindowPos3d, x, y, z);
}

void System::GlWindowPos3dv(const GLdouble* xyz) noexcept
{
    SYSTEM_BODY_1(gglWindowPos3dv, xyz);
}

void System::GlWindowPos3f(GLfloat x, GLfloat y, GLfloat z) noexcept
{
    SYSTEM_BODY_3(gglWindowPos3f, x, y, z);
}

void System::GlWindowPos3fv(const GLfloat* xyz) noexcept
{
    SYSTEM_BODY_1(gglWindowPos3fv, xyz);
}

void System::GlWindowPos3i(GLint x, GLint y, GLint z) noexcept
{
    SYSTEM_BODY_3(gglWindowPos3i, x, y, z);
}

void System::GlWindowPos3iv(const GLint* xyz) noexcept
{
    SYSTEM_BODY_1(gglWindowPos3iv, xyz);
}

void System::GlWindowPos3s(GLshort x, GLshort y, GLshort z) noexcept
{
    SYSTEM_BODY_3(gglWindowPos3s, x, y, z);
}

void System::GlWindowPos3sv(const GLshort* xyz) noexcept
{
    SYSTEM_BODY_1(gglWindowPos3sv, xyz);
}

void System::InitOpenGL14()
{
    if (System::OpenGLSystemVersion::Version14 <= GetOpenGLVersion())
    {
        g_ExistsOpenGL14 = ExistsOpenGLExtensions::Exists;

        // GL_{EXT,INGR}_blend_func_separate

        SYSTEM_GET_FUNCTION(gglBlendFuncSeparate);

        // GL_EXT_fog_coord

        SYSTEM_GET_FUNCTION(gglFogCoordf);
        SYSTEM_GET_FUNCTION(gglFogCoordfv);
        SYSTEM_GET_FUNCTION(gglFogCoordd);
        SYSTEM_GET_FUNCTION(gglFogCoorddv);
        SYSTEM_GET_FUNCTION(gglFogCoordPointer);

        // GL_EXT_multi_draw_arrays

        SYSTEM_GET_FUNCTION(gglMultiDrawArrays);
        SYSTEM_GET_FUNCTION(gglMultiDrawElements);

        // GL_{ARB,EXT,SGIS}_point_parameters

        SYSTEM_GET_FUNCTION(gglPointParameterf);
        SYSTEM_GET_FUNCTION(gglPointParameterfv);

        // GL_NV_point_sprite

        SYSTEM_GET_FUNCTION(gglPointParameteri);
        SYSTEM_GET_FUNCTION(gglPointParameteriv);

        // GL_EXT_secondary_color

        SYSTEM_GET_FUNCTION(gglSecondaryColor3b);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3bv);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3d);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3dv);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3f);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3fv);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3i);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3iv);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3s);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3sv);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3ub);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3ubv);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3ui);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3uiv);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3us);
        SYSTEM_GET_FUNCTION(gglSecondaryColor3usv);
        SYSTEM_GET_FUNCTION(gglSecondaryColorPointer);

        // GL_{ARB,MESA}_window_pos

        SYSTEM_GET_FUNCTION(gglWindowPos2d);
        SYSTEM_GET_FUNCTION(gglWindowPos2dv);
        SYSTEM_GET_FUNCTION(gglWindowPos2f);
        SYSTEM_GET_FUNCTION(gglWindowPos2fv);
        SYSTEM_GET_FUNCTION(gglWindowPos2i);
        SYSTEM_GET_FUNCTION(gglWindowPos2iv);
        SYSTEM_GET_FUNCTION(gglWindowPos2s);
        SYSTEM_GET_FUNCTION(gglWindowPos2sv);
        SYSTEM_GET_FUNCTION(gglWindowPos3d);
        SYSTEM_GET_FUNCTION(gglWindowPos3dv);
        SYSTEM_GET_FUNCTION(gglWindowPos3f);
        SYSTEM_GET_FUNCTION(gglWindowPos3fv);
        SYSTEM_GET_FUNCTION(gglWindowPos3i);
        SYSTEM_GET_FUNCTION(gglWindowPos3iv);
        SYSTEM_GET_FUNCTION(gglWindowPos3s);
        SYSTEM_GET_FUNCTION(gglWindowPos3sv);
    }
    else
    {
        g_ExistsOpenGL14 = ExistsOpenGLExtensions::NotExist;
    }
}
