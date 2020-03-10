// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:03)

#ifndef SYSTEM_SYSTEM_OUTPUT_DIALOG_BOX_COMMAND_FLAGS_H
#define SYSTEM_SYSTEM_OUTPUT_DIALOG_BOX_COMMAND_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{	
#ifdef SYSTEM_PLATFORM_WIN32	

	enum class DialogBoxCommand : uint32_t
	{
		IDCreationFailed = 0,
		IDOk = IDOK,
		IDCancel = IDCANCEL,
		IDAbort = IDABORT,
		IDRetry = IDRETRY,
		IDIgnore = IDIGNORE,
		IDYes = IDYES,
		IDNo = IDNO,
		IDClose = IDCLOSE,
		IDHelp = IDHELP,
		IDTryAgain = IDTRYAGAIN,
		IDContinue = IDCONTINUE,
		IDTimeout = IDTIMEOUT,

		PlatformUnknown = 0xFFFFFFFF,
	};	
		 
#else // !SYSTEM_PLATFORM_WIN32	

	enum class DialogBoxCommand : uint32_t 
	{
		IDCreationFailed = 0,
		IDOk = 1,
		IDCancel = 2,
		IDAbort = 3,
		IDRetry = 4,
		IDIgnore = 5,
		IDYes = 6,
		IDNo = 7,
		IDClose = 8,
		IDHelp = 9,
		IDTryAgain = 10,
		IDContinue = 11,
		IDTimeout = 32000,

		PlatformUnknown = 0xFFFFFFFF,
	};	
			
#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_SYSTEM_OUTPUT_DIALOG_BOX_COMMAND_FLAGS_H