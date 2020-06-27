// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/09 21:14)

#ifndef SYSTEM_CONSOLE_CONSOLE_CREATE_H
#define SYSTEM_CONSOLE_CONSOLE_CREATE_H

#include "System/SystemDll.h"

#include <cstdio>

namespace System
{
	// 控制台窗口的创建的销毁。

	bool SYSTEM_DEFAULT_DECLARE AllocConsole() noexcept;
	bool SYSTEM_DEFAULT_DECLARE FreeConsole() noexcept;

	bool SYSTEM_DEFAULT_DECLARE FReOpenConsole(FILE*& file, const char* path, const char* mode, FILE* stream) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FCloseConsole(FILE* file) noexcept;

	bool SYSTEM_DEFAULT_DECLARE RemoveConsoleCloseButton() noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_CREATE_H