//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:17)

#ifndef SYSTEM_OPENGL_OPEN_GLUTILITY_H
#define SYSTEM_OPENGL_OPEN_GLUTILITY_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"

#include <string>

namespace System
{
    [[nodiscard]] OpenGLSystemVersion SYSTEM_DEFAULT_DECLARE GetOpenGLVersion() noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsOpenGLSupportsExtension(const char* acExtension);

    [[nodiscard]] SYSTEM_DEFAULT_DECLARE void* GetFunctionPointer(const char* glFunction) noexcept;

    [[nodiscard]] std::string SYSTEM_DEFAULT_DECLARE GetOpenGLErrorDescription(OpenGLErrorCode code);

    [[nodiscard]] SYSTEM_DEFAULT_DECLARE bool IsWglSupportsExtension(const char* wglExtension);
}

#endif  // SYSTEM_OPENGL_OPEN_GLUTILITY_H
