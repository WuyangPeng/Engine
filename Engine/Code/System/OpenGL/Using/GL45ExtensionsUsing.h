//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/25 13:14)

#ifndef SYSTEM_OPENGL_GL_45_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_45_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

namespace System
{
    using PgglGetGraphicsResetStatus = GLenum(OPENGL_STDCALL*)();
    using PgglGetnCompressedTexImage = void(OPENGL_STDCALL*)(GLenum target, GLint lod, GLsizei bufSize, GLvoid* pixels);
    using PgglGetnTexImage = void(OPENGL_STDCALL*)(GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
    using PgglGetnUniformdv = void(OPENGL_STDCALL*)(GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
}

#endif  // SYSTEM_OPENGL_GL_45_EXTENSIONS_USING_H
