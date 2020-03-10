// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:32)

#ifndef SYSTEM_CONSOLE_CONSOLE_CODE_PAGE_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_CODE_PAGE_FWD_H

#include "ConsoleFlagsFwd.h"

namespace System
{
	CodePage GetConsoleCodePage() noexcept;
	bool SetConsoleCodePage(CodePage codePage) noexcept;
	CodePage GetConsoleOutputCodePage() noexcept;
	bool SetConsoleOutputCodePage(CodePage codePage) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_CODE_PAGE_FWD_H