//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:39)

#ifndef SYSTEM_CONSOLE_CONSOLE_CREATE_H
#define SYSTEM_CONSOLE_CONSOLE_CREATE_H

#include "System/SystemDll.h"

#include <cstdio>

namespace System
{
    // 控制台窗口的创建的销毁。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE AllocConsole() noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FreeConsole() noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FReOpenConsole(FILE*& file, const char* path, const char* mode, FILE* stream) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FCloseConsole(FILE* file) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE RemoveConsoleCloseButton() noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_CREATE_H