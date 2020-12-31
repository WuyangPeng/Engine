//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 9:19)

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

    [[nodiscard]] DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelectionWithChar(const char* text, const char* caption) noexcept;
    [[nodiscard]] DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelectionWithWChar(const wchar_t* text, const wchar_t* caption) noexcept;
    [[nodiscard]] DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelectionWithTChar(const TChar* text, const TChar* caption) noexcept;
    [[nodiscard]] DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelection(WindowHWnd hwnd, const TChar* text, const TChar* caption,
                                                                              const MessageBoxFlagsData& flagsData) noexcept;
    [[nodiscard]] DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelection(WindowHWnd hwnd, const TChar* text, const TChar* caption,
                                                                              const MessageBoxFlagsData& flagsData, const LanguageIDData& languageIDData) noexcept;
}

#endif  // SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_SELECTION_H