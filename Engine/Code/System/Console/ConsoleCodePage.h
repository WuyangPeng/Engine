// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/09 21:13)

#ifndef SYSTEM_CONSOLE_CONSOLE_CODE_PAGE_H
#define SYSTEM_CONSOLE_CONSOLE_CODE_PAGE_H

#include "System/SystemDll.h" 

#include "Fwd/ConsoleFlagsFwd.h"
#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

namespace System
{
	// 获取和设置控制台代码页。

	CodePage SYSTEM_DEFAULT_DECLARE GetConsoleCodePage() noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetConsoleCodePage(CodePage codePage) noexcept;
	CodePage SYSTEM_DEFAULT_DECLARE GetConsoleOutputCodePage() noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetConsoleOutputCodePage(CodePage codePage) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_CODE_PAGE_H