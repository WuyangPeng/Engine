/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/29 09:26)

#ifndef SYSTEM_GL_EXTENSIONS_H
#define SYSTEM_GL_EXTENSIONS_H

#include "System/SystemDll.h"

namespace System
{
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR const char* GetVendorString() noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR const char* GetRendererString() noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR const char* GetVersionString() noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR const char* GetShadingLanguageVersion() noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD bool InitGL() noexcept;
}

#endif  // SYSTEM_GL_EXTENSIONS_H
