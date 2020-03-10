// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:17)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_FWD_H
#define SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_FWD_H

#include "CharacterStringFlagsFwd.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputDataFwd.h"

namespace System
{
	WindowDWord	FormatErrorMessage(FormatMessageOption flag, FormatMessageWidth widthFlag, WindowConstVoidPtr source, WindowError messageID,
								   const LanguageIDData& languageID, TChar* buffer, WindowDWord size, va_list* arguments) noexcept;
	bool FormatErrorMessage(WindowHLocal& errorMessage, WindowError lastError) noexcept;
	WindowDWord FormatErrorMessage(WindowError lastError, TChar* buffer, WindowDWord size) noexcept;
	bool FormatErrorMessage(WindowHLocal& errorMessage, DynamicLinkModule module, WindowError lastError) noexcept;
	WindowDWord FormatErrorMessage(DynamicLinkModule module, WindowError lastError, TChar* buffer, WindowDWord size) noexcept;
	WindowDWord FormatStringMessage(const TChar* message, TChar* buffer, WindowDWord size, WindowPtrDWord* arguments) noexcept;
	WindowDWord FormatStringMessage(const TChar* message, TChar* buffer, WindowDWord size, va_list* arguments) noexcept;
	WindowDWord FormatStringMessage(const TChar* message, WindowHLocal& resultMessage, WindowPtrDWord* arguments) noexcept;
	WindowDWord FormatStringMessage(const TChar* message, WindowHLocal& resultMessage, va_list* arguments) noexcept; 
}

#endif // SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_FWD_H