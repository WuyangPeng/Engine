// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/09 21:13)

#ifndef SYSTEM_CONSOLE_CONSOLE_ALIAS_H
#define SYSTEM_CONSOLE_CONSOLE_ALIAS_H

#include "System/SystemDll.h"  

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 增加和获取控制台别名。

	bool SYSTEM_DEFAULT_DECLARE AddSystemConsoleAlias(TChar* source, TChar* target, TChar* exeName) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleAlias(TChar* source, TChar* targetBuffer, WindowDWord targetBufferLength, TChar* exeName) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleAliasesLength(TChar* exeName) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleAliasExesLength() noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleAliases(TChar* aliasBuffer, WindowDWord aliasBufferLength, TChar* exeName) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleAliasExes(TChar* exeNameBuffer, WindowDWord exeNameBufferLength) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_ALIAS_H