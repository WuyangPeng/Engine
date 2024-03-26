/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/24 20:49)

#ifndef SYSTEM_OPENGL_OPENGL_USING_H
#define SYSTEM_OPENGL_OPENGL_USING_H

#include "System/Helper/GLExtensionsMacro.h"
#include "System/Helper/UserMacro.h"

#include <array>
#include <string>
#include <vector>

namespace System
{
    using OpenGLEnum = GLenum;
    using OpenGLBoolean = GLboolean;
    using OpenGLBitfield = GLbitfield;
    using OpenGLByte = GLbyte;
    using OpenGLShort = GLshort;
    using OpenGLInt = GLint;
    using OpenGLSize = GLsizei;
    using OpenGLUnsignedByte = GLubyte;
    using OpenGLUnsignedShort = GLushort;
    using OpenGLUnsignedInt = GLuint;
    using OpenGLFloat = GLfloat;
    using OpenGLClampFloat = GLclampf;
    using OpenGLDouble = GLdouble;
    using OpenGLClampDouble = GLclampd;
    using OpenGLVoid = GLvoid;
    using OpenGLIntPtr = GLintptr;
    using OpenGLSizePtr = GLsizeiptr;
    using OpenGLChar = GLchar;
    using OpenGLInt64 = GLint64;
    using OpenGLUnsignedInt64 = GLuint64;
    using OpenGLHalf = GLhalf;

    constexpr auto invalidGLIndex = GL_INVALID_INDEX;

    using ComputeWorkGroupSizeType = std::array<OpenGLInt, 3>;
    using ViewportQueryType = std::array<OpenGLInt, 4>;
    using DepthRangeQueryType = std::array<OpenGLDouble, 2>;

    using OpenGLEnumContainer = std::vector<OpenGLEnum>;
    using OpenGLUnsignedIntIntContainer = std::vector<OpenGLUnsignedInt>;
    using TokenSplitType = std::vector<std::string>;
    using LogInfoType = std::vector<OpenGLChar>;
}

#endif  // SYSTEM_OPENGL_OPENGL_USING_H
