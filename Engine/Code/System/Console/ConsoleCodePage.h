///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.5 (2022/12/02 16:26)

#ifndef SYSTEM_CONSOLE_CONSOLE_CODE_PAGE_H
#define SYSTEM_CONSOLE_CONSOLE_CODE_PAGE_H

#include "System/SystemDll.h"

#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

// 获取和设置控制台代码页。
namespace System
{
    NODISCARD CodePage SYSTEM_DEFAULT_DECLARE GetConsoleCodePage() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetConsoleCodePage(CodePage codePage) noexcept;
    NODISCARD CodePage SYSTEM_DEFAULT_DECLARE GetConsoleOutputCodePage() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetConsoleOutputCodePage(CodePage codePage) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_CODE_PAGE_H