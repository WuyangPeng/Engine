//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:41)

#ifndef SYSTEM_OPENGL_GL_UTILITY_H
#define SYSTEM_OPENGL_GL_UTILITY_H

#include "System/SystemDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"

namespace System
{
    // 错误检查。
    const char* SYSTEM_HIDDEN_DECLARE GetOpenGLErrorString(OpenGLErrorCode code) noexcept;

    OpenGLSystemVersion SYSTEM_HIDDEN_DECLARE GetOpenGLVersion(char major, char minor) noexcept;
    int SYSTEM_HIDDEN_DECLARE ToIndex(char index) noexcept;
}

extern "C"
{
    // 每个平台必须实现这个函数。
    void* SYSTEM_HIDDEN_DECLARE GetOpenGLFunctionPointer(const char* glFunction) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_UTILITY_H
