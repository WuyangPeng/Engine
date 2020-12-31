//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:16)

#ifndef SYSTEM_OPENGL_OPENGL_USING_H
#define SYSTEM_OPENGL_OPENGL_USING_H

#include "GL11ExtensionsUsing.h"
#include "GL15ExtensionsUsing.h"
#include "GL20ExtensionsUsing.h"
#include "GL32ExtensionsUsing.h"

namespace System
{
    using OpenGLEnum = GLenum;
    using OpenGLBoolean = GLboolean;
    using OpenGLBitfield = GLbitfield;
    using OpenGLByte = GLbyte;
    using OpenGLShort = GLshort;
    using OpenGLInt = GLint;
    using OpenGLSize = GLsizei;
    using OpenGLUByte = GLbyte;
    using OpenGLUShort = GLshort;
    using OpenGLUInt = GLuint;
    using OpenGLULong = GLulong;
    using OpenGLFloat = GLfloat;
    using OpenGLClampf = GLclampf;
    using OpenGLDouble = GLdouble;
    using OpenGLClampd = GLclampd;
    using OpenGLVoid = GLvoid;
    using OpenGLIntPtr = GLintptr;
    using OpenGLSizePtr = GLsizeiptr;
    using OpenGLChar = GLchar;
    using OpenGLInt64 = GLint64;
    using OpenGLUInt64 = GLuint64;
}

#endif  // SYSTEM_OPENGL_OPENGL_USING_H
