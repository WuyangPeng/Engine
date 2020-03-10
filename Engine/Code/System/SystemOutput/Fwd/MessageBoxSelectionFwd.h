// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:03)

#ifndef SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_SELECTION_FWD_H
#define SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_SELECTION_FWD_H

#include "SystemOutputDataFwd.h"
#include "SystemOutputFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	DialogBoxCommand MessageBoxSelectionWithChar(const char* text, const char* caption) noexcept;
	DialogBoxCommand MessageBoxSelectionWithWChar(const wchar_t* text, const wchar_t* caption) noexcept;
	DialogBoxCommand MessageBoxSelectionWithTChar(const TChar* text, const TChar* caption) noexcept;
	DialogBoxCommand MessageBoxSelection(WindowHWnd hWnd, const TChar* text, const TChar* caption, const MessageBoxFlagsData& flagsData) noexcept;
	DialogBoxCommand MessageBoxSelection(WindowHWnd hWnd, const TChar* text, const TChar* caption,
										 const MessageBoxFlagsData& flagsData, const LanguageIDData& languageIDData) noexcept;
}

#endif // SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_SELECTION_FWD_H