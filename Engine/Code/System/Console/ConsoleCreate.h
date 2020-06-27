// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/09 21:14)

#ifndef SYSTEM_CONSOLE_CONSOLE_CREATE_H
#define SYSTEM_CONSOLE_CONSOLE_CREATE_H

#include "System/SystemDll.h"

#include <cstdio>

namespace System
{
	// ����̨���ڵĴ��������١�

	bool SYSTEM_DEFAULT_DECLARE AllocConsole() noexcept;
	bool SYSTEM_DEFAULT_DECLARE FreeConsole() noexcept;

	bool SYSTEM_DEFAULT_DECLARE FReOpenConsole(FILE*& file, const char* path, const char* mode, FILE* stream) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FCloseConsole(FILE* file) noexcept;

	bool SYSTEM_DEFAULT_DECLARE RemoveConsoleCloseButton() noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_CREATE_H