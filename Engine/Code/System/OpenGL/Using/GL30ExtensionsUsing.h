//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:14)

#ifndef SYSTEM_OPENGL_GL_30_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_30_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "GL15ExtensionsUsing.h"
#include "GL20ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

namespace System
{
    using PgglColorMaski = void(OPENGL_STDCALL*)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean);
    using PgglGetBooleani_v = void(OPENGL_STDCALL*)(GLenum, GLuint, GLboolean*);
    using PgglGetIntegeri_v = void(OPENGL_STDCALL*)(GLenum, GLuint, GLint*);
    using PgglEnablei = void(OPENGL_STDCALL*)(GLenum, GLuint);
    using PgglDisablei = void(OPENGL_STDCALL*)(GLenum, GLuint);
    using PgglIsEnabledi = GLboolean(OPENGL_STDCALL*)(GLenum, GLuint);
    using PgglBeginTransformFeedback = void(OPENGL_STDCALL*)(GLenum);
    using PgglEndTransformFeedback = void(OPENGL_STDCALL*)(void);
    using PgglBindBufferRange = void(OPENGL_STDCALL*)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr);
    using PgglBindBufferBase = void(OPENGL_STDCALL*)(GLenum, GLuint, GLuint);
    using PgglTransformFeedbackVaryings = void(OPENGL_STDCALL*)(GLuint, GLsizei, const GLchar**, GLenum);
    using PgglGetTransformFeedbackVarying = void(OPENGL_STDCALL*)(GLuint, GLuint, GLsizei, GLsizei*, GLsizei*, GLenum*, GLchar*);
    using PgglClampColor = void(OPENGL_STDCALL*)(GLenum, GLenum);
    using PgglBeginConditionalRender = void(OPENGL_STDCALL*)(GLuint, GLenum);
    using PgglEndConditionalRender = void(OPENGL_STDCALL*)(void);
    using PgglVertexAttribIPointer = void(OPENGL_STDCALL*)(GLuint, GLint, GLenum, GLsizei, const GLvoid*);
    using PgglGetVertexAttribIiv = void(OPENGL_STDCALL*)(GLuint, GLenum, GLint*);
    using PgglGetVertexAttribIuiv = void(OPENGL_STDCALL*)(GLuint, GLenum, GLuint*);
    using PgglVertexAttribI1i = void(OPENGL_STDCALL*)(GLuint, GLint);
    using PgglVertexAttribI2i = void(OPENGL_STDCALL*)(GLuint, GLint, GLint);
    using PgglVertexAttribI3i = void(OPENGL_STDCALL*)(GLuint, GLint, GLint, GLint);
    using PgglVertexAttribI4i = void(OPENGL_STDCALL*)(GLuint, GLint, GLint, GLint, GLint);
    using PgglVertexAttribI1ui = void(OPENGL_STDCALL*)(GLuint, GLuint);
    using PgglVertexAttribI2ui = void(OPENGL_STDCALL*)(GLuint, GLuint, GLuint);
    using PgglVertexAttribI3ui = void(OPENGL_STDCALL*)(GLuint, GLuint, GLuint, GLuint);
    using PgglVertexAttribI4ui = void(OPENGL_STDCALL*)(GLuint, GLuint, GLuint, GLuint, GLuint);
    using PgglVertexAttribI1iv = void(OPENGL_STDCALL*)(GLuint, const GLint*);
    using PgglVertexAttribI2iv = void(OPENGL_STDCALL*)(GLuint, const GLint*);
    using PgglVertexAttribI3iv = void(OPENGL_STDCALL*)(GLuint, const GLint*);
    using PgglVertexAttribI4iv = void(OPENGL_STDCALL*)(GLuint, const GLint*);
    using PgglVertexAttribI1uiv = void(OPENGL_STDCALL*)(GLuint, const GLuint*);
    using PgglVertexAttribI2uiv = void(OPENGL_STDCALL*)(GLuint, const GLuint*);
    using PgglVertexAttribI3uiv = void(OPENGL_STDCALL*)(GLuint, const GLuint*);
    using PgglVertexAttribI4uiv = void(OPENGL_STDCALL*)(GLuint, const GLuint*);
    using PgglVertexAttribI4bv = void(OPENGL_STDCALL*)(GLuint, const GLbyte*);
    using PgglVertexAttribI4sv = void(OPENGL_STDCALL*)(GLuint, const GLshort*);
    using PgglVertexAttribI4ubv = void(OPENGL_STDCALL*)(GLuint, const GLubyte*);
    using PgglVertexAttribI4usv = void(OPENGL_STDCALL*)(GLuint, const GLushort*);
    using PgglGetUniformuiv = void(OPENGL_STDCALL*)(GLuint, GLint, GLuint*);
    using PgglBindFragDataLocation = void(OPENGL_STDCALL*)(GLuint, GLuint, const GLchar*);
    using PgglGetFragDataLocation = GLint(OPENGL_STDCALL*)(GLuint, const GLchar*);
    using PgglUniform1ui = void(OPENGL_STDCALL*)(GLint, GLuint);
    using PgglUniform2ui = void(OPENGL_STDCALL*)(GLint, GLuint, GLuint);
    using PgglUniform3ui = void(OPENGL_STDCALL*)(GLint, GLuint, GLuint, GLuint);
    using PgglUniform4ui = void(OPENGL_STDCALL*)(GLint, GLuint, GLuint, GLuint, GLuint);
    using PgglUniform1uiv = void(OPENGL_STDCALL*)(GLint, GLsizei, const GLuint*);
    using PgglUniform2uiv = void(OPENGL_STDCALL*)(GLint, GLsizei, const GLuint*);
    using PgglUniform3uiv = void(OPENGL_STDCALL*)(GLint, GLsizei, const GLuint*);
    using PgglUniform4uiv = void(OPENGL_STDCALL*)(GLint, GLsizei, const GLuint*);
    using PgglTexParameterIiv = void(OPENGL_STDCALL*)(GLenum, GLenum, const GLint*);
    using PgglTexParameterIuiv = void(OPENGL_STDCALL*)(GLenum, GLenum, const GLuint*);
    using PgglGetTexParameterIiv = void(OPENGL_STDCALL*)(GLenum, GLenum, GLint*);
    using PgglGetTexParameterIuiv = void(OPENGL_STDCALL*)(GLenum, GLenum, GLuint*);
    using PgglClearBufferiv = void(OPENGL_STDCALL*)(GLenum, GLint, const GLint*);
    using PgglClearBufferuiv = void(OPENGL_STDCALL*)(GLenum, GLint, const GLuint*);
    using PgglClearBufferfv = void(OPENGL_STDCALL*)(GLenum, GLint, const GLfloat*);
    using PgglClearBufferfi = void(OPENGL_STDCALL*)(GLenum, GLint, GLfloat, GLint);
    using PgglGetStringi = const GLubyte*(OPENGL_STDCALL*)(GLenum, GLuint);
}

#endif  // SYSTEM_OPENGL_GL_30_EXTENSIONS_USING_H
