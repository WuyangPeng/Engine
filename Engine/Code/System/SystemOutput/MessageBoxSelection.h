// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 16:04)

#ifndef SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_SELECTION_H
#define SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_SELECTION_H

#include "System/SystemDll.h"

#include "Fwd/SystemOutputDataFwd.h"
#include "Fwd/SystemOutputFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 弹出消息选择框。

	DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelectionWithChar(const char* text, const char* caption) noexcept;
	DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelectionWithWChar(const wchar_t* text, const wchar_t* caption) noexcept;
	DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelectionWithTChar(const TChar* text, const TChar* caption) noexcept;
	DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelection(WindowHWnd hWnd, const TChar* text, const TChar* caption,
																const MessageBoxFlagsData& flagsData) noexcept;
	DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelection(WindowHWnd hWnd, const TChar* text, const TChar* caption,
																const MessageBoxFlagsData& flagsData, const LanguageIDData& languageIDData) noexcept;
}

#endif // SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_SELECTION_H