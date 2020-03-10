// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:32)

#ifndef SYSTEM_CONSOLE_CONSOLE_CREATE_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_CREATE_FWD_H  

#include <cstdio>

namespace System
{
	bool AllocConsole() noexcept;
	bool FreeConsole() noexcept;

	bool FReOpenConsole(FILE*& file, const char* path, const char* mode, FILE* stream) noexcept;
	bool FCloseConsole(FILE* file) noexcept;

	bool RemoveConsoleCloseButton() noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_CREATE_FWD_H