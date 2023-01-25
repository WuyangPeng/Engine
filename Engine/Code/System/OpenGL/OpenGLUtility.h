///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 22:43)

#ifndef SYSTEM_OPENGL_OPEN_GLUTILITY_H
#define SYSTEM_OPENGL_OPEN_GLUTILITY_H

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

#endif  // SYSTEM_OPENGL_OPEN_GLUTILITY_H
