// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:34)

#ifndef SYSTEM_CONSOLE_CONSOLE_INFO_USING_H
#define SYSTEM_CONSOLE_CONSOLE_INFO_USING_H 

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using ConsoleHistoryInfo = CONSOLE_HISTORY_INFO;
	using ConsoleHistoryInfoPtr = PCONSOLE_HISTORY_INFO;
	using ConsoleSelectionInfo = CONSOLE_SELECTION_INFO;
	using ConsoleSelectionInfoPtr = PCONSOLE_SELECTION_INFO;

#else // !SYSTEM_PLATFORM_WIN32

	struct ConsoleHistoryInfo
	{
		uint32_t cbSize;
		uint32_t HistoryBufferSize;
		uint32_t NumberOfHistoryBuffers;
		uint32_t dwFlags;
	};
	using ConsoleHistoryInfoPtr = ConsoleHistoryInfo*;

	struct ConsoleSelectionInfo
	{
		uint32_t dwFlags;
		uint32_t dwSelectionAnchor;
		ConsoleSmallRect srSelection;
	};

	using ConsoleSelectionInfoPtr = ConsoleSelectionInfo*;

#endif // SYSTEM_PLATFORM_WIN32   
}

#endif // SYSTEM_CONSOLE_CONSOLE_INFO_USING_H