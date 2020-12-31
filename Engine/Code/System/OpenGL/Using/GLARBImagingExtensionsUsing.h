//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:15)

#ifndef SYSTEM_OPENGL_GL_ARB_IMAGING_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_ARB_IMAGING_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

namespace System
{
    // 成像子集 (GL_ARB_imaging)

    using PgglBlendColor = void(OPENGL_STDCALL*)(GLclampf, GLclampf, GLclampf, GLclampf);
    using PgglBlendEquation = void(OPENGL_STDCALL*)(GLenum);
    using PgglColorTable = void(OPENGL_STDCALL*)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
    using PgglColorTableParameterfv = void(OPENGL_STDCALL*)(GLenum, GLenum, const GLfloat*);
    using PgglColorTableParameteriv = void(OPENGL_STDCALL*)(GLenum, GLenum, const GLint*);
    using PgglCopyColorTable = void(OPENGL_STDCALL*)(GLenum, GLenum, GLint, GLint, GLsizei);
    using PgglGetColorTable = void(OPENGL_STDCALL*)(GLenum, GLenum, GLenum, GLvoid*);
    using PgglGetColorTableParameterfv = void(OPENGL_STDCALL*)(GLenum, GLenum, GLfloat*);
    using PgglGetColorTableParameteriv = void(OPENGL_STDCALL*)(GLenum, GLenum, GLint*);
    using PgglColorSubTable = void(OPENGL_STDCALL*)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
    using PgglCopyColorSubTable = void(OPENGL_STDCALL*)(GLenum, GLsizei, GLint, GLint, GLsizei);
    using PgglConvolutionFilter1D = void(OPENGL_STDCALL*)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
    using PgglConvolutionFilter2D = void(OPENGL_STDCALL*)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
    using PgglConvolutionParameterf = void(OPENGL_STDCALL*)(GLenum, GLenum, GLfloat);
    using PgglConvolutionParameterfv = void(OPENGL_STDCALL*)(GLenum, GLenum, const GLfloat*);
    using PgglConvolutionParameteri = void(OPENGL_STDCALL*)(GLenum, GLenum, GLint);
    using PgglConvolutionParameteriv = void(OPENGL_STDCALL*)(GLenum, GLenum, const GLint*);
    using PgglCopyConvolutionFilter1D = void(OPENGL_STDCALL*)(GLenum, GLenum, GLint, GLint, GLsizei);
    using PgglCopyConvolutionFilter2D = void(OPENGL_STDCALL*)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei);
    using PgglGetConvolutionFilter = void(OPENGL_STDCALL*)(GLenum, GLenum, GLenum, GLvoid*);
    using PgglGetConvolutionParameterfv = void(OPENGL_STDCALL*)(GLenum, GLenum, GLfloat*);
    using PgglGetConvolutionParameteriv = void(OPENGL_STDCALL*)(GLenum, GLenum, GLint*);
    using PgglGetSeparableFilter = void(OPENGL_STDCALL*)(GLenum, GLenum, GLenum, GLvoid*, GLvoid*, GLvoid*);
    using PgglSeparableFilter2D = void(OPENGL_STDCALL*)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*, const GLvoid*);
    using PgglGetHistogram = void(OPENGL_STDCALL*)(GLenum, GLboolean, GLenum, GLenum, GLvoid*);
    using PgglGetHistogramParameterfv = void(OPENGL_STDCALL*)(GLenum, GLenum, GLfloat*);
    using PgglGetHistogramParameteriv = void(OPENGL_STDCALL*)(GLenum, GLenum, GLint*);
    using PgglGetMinmax = void(OPENGL_STDCALL*)(GLenum, GLboolean, GLenum, GLenum, GLvoid*);
    using PgglGetMinmaxParameterfv = void(OPENGL_STDCALL*)(GLenum, GLenum, GLfloat*);
    using PgglGetMinmaxParameteriv = void(OPENGL_STDCALL*)(GLenum, GLenum, GLint*);
    using PgglHistogram = void(OPENGL_STDCALL*)(GLenum, GLsizei, GLenum, GLboolean);
    using PgglMinmax = void(OPENGL_STDCALL*)(GLenum, GLenum, GLboolean);
    using PgglResetHistogram = void(OPENGL_STDCALL*)(GLenum);
    using PgglResetMinmax = void(OPENGL_STDCALL*)(GLenum);
}

#endif  // SYSTEM_OPENGL_GL_ARB_IMAGING_EXTENSIONS_USING_H
