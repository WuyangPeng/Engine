//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:10)

#ifndef SYSTEM_OPENGL_GL_EXTENSIONS_FLAGS_H
#define SYSTEM_OPENGL_GL_EXTENSIONS_FLAGS_H

#include "System/Helper/EnumMacro.h"

#include "System/Helper/Detail/OpenGL/GL11ExtensionsMacro.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

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
    };

    enum class OpenGLSystemVersion
    {
        VersionNone = g_SystemOpenGLVersionNone,
        Version11 = g_SystemOpenGLVersion11,
        Version12 = g_SystemOpenGLVersion12,
        Version13 = g_SystemOpenGLVersion13,
        Version14 = g_SystemOpenGLVersion14,
        Version15 = g_SystemOpenGLVersion15,
        Version20 = g_SystemOpenGLVersion20,
        Version21 = g_SystemOpenGLVersion21,
        Version30 = g_SystemOpenGLVersion30,
        Version31 = g_SystemOpenGLVersion31,
        Version32 = g_SystemOpenGLVersion32,
        Version33 = g_SystemOpenGLVersion33,
        Version40 = g_SystemOpenGLVersion40,
        Version41 = g_SystemOpenGLVersion41,
        Version42 = g_SystemOpenGLVersion42,
        Version43 = g_SystemOpenGLVersion43,
        Version44 = g_SystemOpenGLVersion44,
        Version45 = g_SystemOpenGLVersion45,
        Version46 = g_SystemOpenGLVersion46,
        VersionUnkownMax = g_SystemOpenGLVersionMax,
    };
}

#endif  // SYSTEM_OPENGL_GL_EXTENSIONS_FLAGS_H
