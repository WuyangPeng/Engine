// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 10:59)

#ifndef SYSTEM_THREADING_HANDLE_TOOLS_FLAGS_H
#define SYSTEM_THREADING_HANDLE_TOOLS_FLAGS_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	enum class HandleInformation
	{
		Default = 0x00000000,
		Inherit = HANDLE_FLAG_INHERIT,
		ProtectFromClose = HANDLE_FLAG_PROTECT_FROM_CLOSE,
		All = Inherit | ProtectFromClose,
	};

	enum class DuplicateOptions
	{
		Default = 0x00000000,
		CloseSource = DUPLICATE_CLOSE_SOURCE,
		SameAccess = DUPLICATE_SAME_ACCESS,
	};

#else // !SYSTEM_PLATFORM_WIN32	

	enum class HandleInformation
	{
		Default = 0x00000000,
		Inherit = 0x00000001,
		ProtectFromClose = 0x00000002,
		All = Inherit | ProtectFromClose,
	};

	enum class DuplicateOptions
	{
		Default = 0x00000000,
		CloseSource = 0x00000001,
		SameAccess = 0x00000002,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_THREADING_HANDLE_TOOLS_FLAGS_H