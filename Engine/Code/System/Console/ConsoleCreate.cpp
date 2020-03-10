// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:37)

#include "System/SystemExport.h"

#include "ConsoleCreate.h"
#include "ConsoleTools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowCreate.h"

bool System
	::AllocConsole() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::AllocConsole() != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FreeConsole() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::FreeConsole() != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FReOpenConsole(FILE*& file, const char* path, const char* mode, FILE* stream) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	const auto result = freopen_s(&file, path, mode, stream);

	if (result == 0)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	file = freopen(path, mode, stream);

	if (file != nullptr)
		return true;
	else
		return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FCloseConsole(FILE* file) noexcept
{
	const auto result = fclose(file);

	if (result == 0)
		return true;
	else
		return false;
}

bool System
	::RemoveConsoleCloseButton() noexcept
{
	auto hwnd = GetSystemConsoleWindow();
	if (hwnd != nullptr)
		return RemoveMenuCloseButton(hwnd);
	else
		return false;
}
