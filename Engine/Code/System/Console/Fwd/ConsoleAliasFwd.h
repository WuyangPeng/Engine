// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:31)

#ifndef SYSTEM_CONSOLE_CONSOLE_ALIAS_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_ALIAS_FWD_H

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	bool AddSystemConsoleAlias(TChar* source, TChar* target, TChar* exeName) noexcept;
	WindowDWord GetSystemConsoleAlias(TChar* source, TChar* targetBuffer, WindowDWord targetBufferLength, TChar* exeName) noexcept;
	WindowDWord GetSystemConsoleAliasesLength(TChar* exeName) noexcept;
	WindowDWord GetSystemConsoleAliasExesLength() noexcept;
	WindowDWord GetSystemConsoleAliases(TChar* aliasBuffer, WindowDWord aliasBufferLength, TChar* exeName) noexcept;
	WindowDWord GetSystemConsoleAliasExes(TChar* exeNameBuffer, WindowDWord exeNameBufferLength) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_ALIAS_FWD_H