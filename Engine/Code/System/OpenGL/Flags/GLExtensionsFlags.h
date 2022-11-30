///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:19)

#ifndef SYSTEM_OPENGL_GL_EXTENSIONS_FLAGS_H
#define SYSTEM_OPENGL_GL_EXTENSIONS_FLAGS_H

#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/Helper/EnumMacro.h"
#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    enum class ExistsOpenGLExtensions
    {
        NotExist = -1,
        Unknown = 0,
        Exists = 1,
    };

    enum class OpenGLErrorCode
    {
        NoError = GL_NO_ERROR,
        InvalidEnum = GL_INVALID_ENUM,
        InvalidValue = GL_INVALID_VALUE,
        InvalidOperation = GL_INVALID_OPERATION,
        StackOverflow = GL_STACK_OVERFLOW,
        StackUnderflow = GL_STACK_UNDERFLOW,
        OutOfMemory = GL_OUT_OF_MEMORY,
        InvalidFramebufferOperation = GL_INVALID_FRAMEBUFFER_OPERATION,
        ContextLost = GL_CONTEXT_LOST,
    };

    enum class OpenGLSystemVersion
    {
        VersionNone = gSystemOpenGLVersionNone,
        Version10 = gSystemOpenGLVersion10,
        Version11 = gSystemOpenGLVersion11,
        Version12 = gSystemOpenGLVersion12,
        Version13 = gSystemOpenGLVersion13,
        Version14 = gSystemOpenGLVersion14,
        Version15 = gSystemOpenGLVersion15,
        Version20 = gSystemOpenGLVersion20,
        Version21 = gSystemOpenGLVersion21,
        Version30 = gSystemOpenGLVersion30,
        Version31 = gSystemOpenGLVersion31,
        Version32 = gSystemOpenGLVersion32,
        Version33 = gSystemOpenGLVersion33,
        Version40 = gSystemOpenGLVersion40,
        Version41 = gSystemOpenGLVersion41,
        Version42 = gSystemOpenGLVersion42,
        Version43 = gSystemOpenGLVersion43,
        Version44 = gSystemOpenGLVersion44,
        Version45 = gSystemOpenGLVersion45,
        Version46 = gSystemOpenGLVersion46,
        VersionUnkownMax = gSystemOpenGLVersionMax,
    };
}

#endif  // SYSTEM_OPENGL_GL_EXTENSIONS_FLAGS_H
