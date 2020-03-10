// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:31)

#ifndef SYSTEM_CONSOLE_CONSOLE_HANDLE_FLAGS_H
#define SYSTEM_CONSOLE_CONSOLE_HANDLE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	enum class StandardHandle : uint32_t
	{
		Input = STD_INPUT_HANDLE,
		Output = STD_OUTPUT_HANDLE,
		Error = STD_ERROR_HANDLE,
	};

#else // !SYSTEM_PLATFORM_WIN32

	enum class StandardHandle : uint32_t
	{
		Input = static_cast<uint32_t>(-10),
		Output = static_cast<uint32_t>(-11),
		Error = static_cast<uint32_t>(-12),
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_CONSOLE_CONSOLE_HANDLE_FLAGS_H
