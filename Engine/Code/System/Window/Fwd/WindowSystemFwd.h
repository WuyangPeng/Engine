// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:37)

#ifndef SYSTEM_WINDOW_WINDOW_SYSTEM_FWD_H 
#define SYSTEM_WINDOW_WINDOW_SYSTEM_FWD_H 

#include "WindowFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	void GetWindowSystemInfo(WindowSystemInfo& systemInfo) noexcept;

	bool GetNumaProcessorNodeNumber(WindowUChar processor, WindowUCharPtr nodeNumber) noexcept;

	void DebugBreak() noexcept;
	void Exit() noexcept;
	int SystemCommand(const char* command) noexcept;

	WindowDWord GetSystemCurrentDirectory(WindowDWord bufferLength, TChar* buffer) noexcept;
	bool SetSystemCurrentDirectory(const TChar* pathName) noexcept;
	bool GetSystemUserName(TChar* buffer, WindowDWord* bufferCount) noexcept;
	WindowBool BoolConversion(bool value) noexcept;
	void BoolConversion(WindowBool value, bool* result) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_SYSTEM_FWD_H