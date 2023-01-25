///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 22:41)

#ifndef SYSTEM_OPENGL_OPENGL_USING_H
#define SYSTEM_OPENGL_OPENGL_USING_H

#include "System/Helper/GLExtensionsMacro.h"
#include "System/Helper/UserMacro.h"

#include <array>

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
    using OpenGLHalf = GLhalf;

    constexpr auto invalidGLIndex = GL_INVALID_INDEX;

    using ComputeWorkGroupSizeType = std::array<OpenGLInt, 3>;
    using ViewportQueryType = std::array<OpenGLInt, 4>;
    using DepthRangeQueryType = std::array<OpenGLDouble, 2>;
}

#endif  // SYSTEM_OPENGL_OPENGL_USING_H
