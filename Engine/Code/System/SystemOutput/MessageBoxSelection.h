/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 16:24)

#ifndef SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_SELECTION_H
#define SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_SELECTION_H

#include "System/SystemDll.h"

#include "Fwd/SystemOutputDataFwd.h"
#include "Fwd/SystemOutputFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// ������Ϣѡ���
namespace System
{
    NODISCARD DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelectionWithChar(const char* text, const char* caption) noexcept;
    NODISCARD DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelectionWithWChar(const wchar_t* text, const wchar_t* caption) noexcept;
    NODISCARD DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelectionWithTChar(const TChar* text, const TChar* caption) noexcept;

    NODISCARD DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelection(WindowsHWnd hWnd,
                                                                          const TChar* text,
                                                                          const TChar* caption,
                                                                          const MessageBoxFlagsData& flagsData) noexcept;
    NODISCARD DialogBoxCommand SYSTEM_DEFAULT_DECLARE MessageBoxSelection(WindowsHWnd hWnd,
                                                                          const TChar* text,
                                                                          const TChar* caption,
                                                                          const MessageBoxFlagsData& flagsData,
                                                                          const LanguageIdData& languageIdData) noexcept;
}

#endif  // SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_SELECTION_H