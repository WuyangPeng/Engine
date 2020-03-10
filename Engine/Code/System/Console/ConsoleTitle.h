// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 13:36)

#ifndef SYSTEM_CONSOLE_CONSOLE_TITLE_H
#define SYSTEM_CONSOLE_CONSOLE_TITLE_H

#include "System/SystemDll.h"   

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 控制台的标题的设置和获取。

	WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleTitle(TChar* consoleTitle, WindowDWord size) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleOriginalTitle(TChar* consoleTitle, WindowDWord size) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleTitle(const TChar* consoleTitle) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_TITLE_H