/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:11)

#ifndef SYSTEM_OPENGL_OPEN_GL_UTILITY_H
#define SYSTEM_OPENGL_OPEN_GL_UTILITY_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"

#include <string>

namespace System
{
    NODISCARD OpenGLSystemVersion SYSTEM_DEFAULT_DECLARE GetOpenGLVersion() noexcept;

    NODISCARD std::string SYSTEM_DEFAULT_DECLARE GetOpenGLErrorDescription(OpenGLErrorCode code);

    MAYBE_NULLPTR SYSTEM_DEFAULT_DECLARE void* GetFunctionPointer(const char* glFunction) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsOpenGLSupportsExtension(const std::string& extension);
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsWglSupportsExtension(const char* wglExtension);
}

#endif  // SYSTEM_OPENGL_OPEN_GL_UTILITY_H
