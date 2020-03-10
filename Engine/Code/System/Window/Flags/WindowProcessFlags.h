// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:35)

#ifndef SYSTEM_WINDOW_WINDOW_PROCESS_FLAGS_H
#define SYSTEM_WINDOW_WINDOW_PROCESS_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	enum class PeekMessageOptions
	{
		NoRemove = PM_NOREMOVE,
		Remove = PM_REMOVE,
		Noyield = PM_NOYIELD,
	};

#else // !SYSTEM_PLATFORM_WIN32

	enum class PeekMessageOptions
	{
		NoRemove = 0x0000,
		Remove = 0x0001,
		Noyield = 0x0002,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_WINDOW_WINDOW_PROCESS_FLAGS_H
