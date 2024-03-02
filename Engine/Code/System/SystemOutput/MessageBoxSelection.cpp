/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 10:16)

#include "System/SystemExport.h"

#include "MessageBoxSelection.h"
#include "Flags/DialogBoxCommandFlags.h"
#include "Flags/MessageBoxFlags.h"
#include "Data/LanguageIdData.h"
#include "Data/MessageBoxFlagsData.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"

namespace System
{
    constexpr MessageBoxFlagsData defaultMessageBoxFlagsData{ MessageBoxType::YesNoCancel,
                                                              MessageBoxIcon::Error,
                                                              MessageBoxDefault::Button1,
                                                              MessageBoxMode::ApplModal,
                                                              MessageBoxMisc::TopMost };
}

System::DialogBoxCommand System::MessageBoxSelectionWithChar(const char* text, const char* caption) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto selection = ::MessageBoxA(nullptr, text, caption, defaultMessageBoxFlagsData.GetFlag());

    return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(text, caption);

    return DialogBoxCommand::PlatformUnknown;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DialogBoxCommand System::MessageBoxSelectionWithWChar(const wchar_t* text, const wchar_t* caption) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto selection = ::MessageBoxW(nullptr, text, caption, defaultMessageBoxFlagsData.GetFlag());

    return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(text, caption);

    return DialogBoxCommand::PlatformUnknown;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DialogBoxCommand System::MessageBoxSelectionWithTChar(const TChar* text, const TChar* caption) noexcept
{
    return MessageBoxSelection(nullptr, text, caption, defaultMessageBoxFlagsData);
}

System::DialogBoxCommand System::MessageBoxSelection(WindowsHWnd hWnd,
                                                     const TChar* text,
                                                     const TChar* caption,
                                                     const MessageBoxFlagsData& flagsData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto selection = ::MessageBox(hWnd, text, caption, flagsData.GetFlag());

    return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd, text, caption, flagsData);

    return DialogBoxCommand::PlatformUnknown;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DialogBoxCommand System::MessageBoxSelection(WindowsHWnd hWnd,
                                                     const TChar* text,
                                                     const TChar* caption,
                                                     const MessageBoxFlagsData& flagsData,
                                                     const LanguageIdData& languageIdData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto selection = ::MessageBoxEx(hWnd, text, caption, flagsData.GetFlag(), languageIdData.GetLanguageId());

    return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd, text, caption, flagsData, languageIdData);

    return DialogBoxCommand::PlatformUnknown;

#endif  // SYSTEM_PLATFORM_WIN32
}
