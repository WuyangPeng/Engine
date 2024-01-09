/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 17:10)

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
    using OpenGLClampF = GLclampf;
    using OpenGLDouble = GLdouble;
    using OpenGLClampD = GLclampd;
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
