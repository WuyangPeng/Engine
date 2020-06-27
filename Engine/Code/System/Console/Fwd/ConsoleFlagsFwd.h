// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/09 19:20)

#ifndef SYSTEM_CONSOLE_CONSOLE_FLAGS_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
	// ConsoleColours
	enum class TextColour;
	enum class BackgroundColour;
	enum class ConsoleCommon;

	// ConsoleHandle
	enum class StandardHandle : uint32_t;

	// ConsoleMode
	enum class ConsoleInputMode;
	enum class ConsoleOutputMode;

	// ConsoleScreenBuffer
	enum class DesiredAccessGeneric : uint32_t;
	enum class ConsoleScreenBufferShareMode;
	enum class ConsoleScreenBuffer;
}

#endif // SYSTEM_CONSOLE_CONSOLE_FLAGS_FWD_H