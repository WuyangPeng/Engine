///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.5 (2021/06/12 18:23)

#ifndef SYSTEM_OPENGL_GL_UTILITY_H
#define SYSTEM_OPENGL_GL_UTILITY_H

#include "System/SystemDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // 错误检查。
    SYSTEM_HIDDEN_DECLARE NODISCARD const char* GetOpenGLErrorString(OpenGLErrorCode code) noexcept;

    NODISCARD OpenGLSystemVersion SYSTEM_HIDDEN_DECLARE GetOpenGLVersion(int major, int minor) noexcept;

    SYSTEM_HIDDEN_DECLARE void PrintExtensionsInfo(const char* extensions);

    // 每个平台必须实现这个函数。
    MAYBE_NULLPTR void* SYSTEM_HIDDEN_DECLARE GetOpenGLFunctionPointer(const char* glFunction) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_UTILITY_H
