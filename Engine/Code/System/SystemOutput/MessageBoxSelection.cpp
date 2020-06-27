// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/08 23:46)

#include "System/SystemExport.h"

#include "MessageBoxSelection.h"
#include "Data/LanguageIDData.h"
#include "Data/MessageBoxFlagsData.h"
#include "Flags/MessageBoxFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"

namespace System
{
	static constexpr MessageBoxFlagsData g_DefaultMessageBoxFlagsData{ MessageBoxType::YesNoCancel,MessageBoxIcon::Error,MessageBoxDefault::Button1,
																	   MessageBoxMode::ApplModal,MessageBoxMisc::TopMost };
}

System::DialogBoxCommand System
	::MessageBoxSelectionWithChar(const char* text, const char* caption) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32 

	const auto selection = ::MessageBoxA(nullptr, text, caption, g_DefaultMessageBoxFlagsData.GetFlag()); ;

	return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else // !SYSTEM_PLATFORM_WIN32

	SYSTEM_UNUSED_ARG(text);
	SYSTEM_UNUSED_ARG(caption);

	return DialogBoxCommand::PlatformUnknown;

#endif // SYSTEM_PLATFORM_WIN32
}

System::DialogBoxCommand System
	::MessageBoxSelectionWithWChar(const wchar_t* text, const wchar_t* caption) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	const auto selection = ::MessageBoxW(nullptr, text, caption, g_DefaultMessageBoxFlagsData.GetFlag());

	return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else // !SYSTEM_PLATFORM_WIN32

	SYSTEM_UNUSED_ARG(text);
	SYSTEM_UNUSED_ARG(caption);

	return DialogBoxCommand::PlatformUnknown;

#endif // SYSTEM_PLATFORM_WIN32
}

System::DialogBoxCommand System
	::MessageBoxSelectionWithTChar(const TChar* text, const TChar* caption) noexcept
{
	return MessageBoxSelection(nullptr, text, caption, g_DefaultMessageBoxFlagsData);
}

System::DialogBoxCommand System
	::MessageBoxSelection(WindowHWnd hWnd, const TChar* text, const TChar* caption, const MessageBoxFlagsData& flagsData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	const auto selection = ::MessageBox(hWnd, text, caption, flagsData.GetFlag());

	return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else // !SYSTEM_PLATFORM_WIN32

	SYSTEM_UNUSED_ARG(hWnd);
	SYSTEM_UNUSED_ARG(text);
	SYSTEM_UNUSED_ARG(caption);
	SYSTEM_UNUSED_ARG(flagsData);

	return DialogBoxCommand::PlatformUnknown;

#endif // SYSTEM_PLATFORM_WIN32
}

System::DialogBoxCommand System
	::MessageBoxSelection(WindowHWnd hWnd, const TChar* text, const TChar* caption,
						  const MessageBoxFlagsData& flagsData, const LanguageIDData& languageIDData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	const auto selection = ::MessageBoxEx(hWnd, text, caption, flagsData.GetFlag(), languageIDData.GetLanguageID());

	return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else // !SYSTEM_PLATFORM_WIN32

	SYSTEM_UNUSED_ARG(hWnd);
	SYSTEM_UNUSED_ARG(text);
	SYSTEM_UNUSED_ARG(caption);
	SYSTEM_UNUSED_ARG(flagsData);
	SYSTEM_UNUSED_ARG(languageIDData);

	return DialogBoxCommand::PlatformUnknown;

#endif // SYSTEM_PLATFORM_WIN32
}
