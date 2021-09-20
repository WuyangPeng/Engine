///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.2 (2021/04/07 19:51)

#ifndef SYSTEM_CONSOLE_CONSOLE_CODE_PAGE_H
#define SYSTEM_CONSOLE_CONSOLE_CODE_PAGE_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

namespace System
{
    // 获取和设置控制台代码页。

    NODISCARD CodePage SYSTEM_DEFAULT_DECLARE GetConsoleCodePage() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetConsoleCodePage(CodePage codePage) noexcept;
    NODISCARD CodePage SYSTEM_DEFAULT_DECLARE GetConsoleOutputCodePage() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetConsoleOutputCodePage(CodePage codePage) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_CODE_PAGE_H