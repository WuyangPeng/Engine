//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 9:20)

#include "System/SystemExport.h"

#include "MessageBoxSelection.h"
#include "Flags/MessageBoxFlags.h"
#include "Data/LanguageIDData.h"
#include "Data/MessageBoxFlagsData.h"
#include "System/Helper/EnumCast.h"

namespace System
{
    static constexpr MessageBoxFlagsData g_DefaultMessageBoxFlagsData{ MessageBoxType::YesNoCancel, MessageBoxIcon::Error, MessageBoxDefault::Button1,
                                                                       MessageBoxMode::ApplModal, MessageBoxMisc::TopMost };
}

System::DialogBoxCommand System::MessageBoxSelectionWithChar([[maybe_unused]] const char* text, [[maybe_unused]] const char* caption) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto selection = ::MessageBoxA(nullptr, text, caption, g_DefaultMessageBoxFlagsData.GetFlag());

    return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else  // !SYSTEM_PLATFORM_WIN32

    return DialogBoxCommand::PlatformUnknown;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DialogBoxCommand System::MessageBoxSelectionWithWChar([[maybe_unused]] const wchar_t* text, [[maybe_unused]] const wchar_t* caption) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto selection = ::MessageBoxW(nullptr, text, caption, g_DefaultMessageBoxFlagsData.GetFlag());

    return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else  // !SYSTEM_PLATFORM_WIN32

    return DialogBoxCommand::PlatformUnknown;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DialogBoxCommand System::MessageBoxSelectionWithTChar(const TChar* text, const TChar* caption) noexcept
{
    return MessageBoxSelection(nullptr, text, caption, g_DefaultMessageBoxFlagsData);
}

System::DialogBoxCommand System::MessageBoxSelection([[maybe_unused]] WindowHWnd hwnd, [[maybe_unused]] const TChar* text, [[maybe_unused]] const TChar* caption, [[maybe_unused]] const MessageBoxFlagsData& flagsData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto selection = ::MessageBox(hwnd, text, caption, flagsData.GetFlag());

    return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else  // !SYSTEM_PLATFORM_WIN32

    return DialogBoxCommand::PlatformUnknown;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DialogBoxCommand System::MessageBoxSelection([[maybe_unused]] WindowHWnd hwnd, [[maybe_unused]] const TChar* text, [[maybe_unused]] const TChar* caption,
                                                     [[maybe_unused]] const MessageBoxFlagsData& flagsData, [[maybe_unused]] const LanguageIDData& languageIDData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto selection = ::MessageBoxEx(hwnd, text, caption, flagsData.GetFlag(), languageIDData.GetLanguageID());

    return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else  // !SYSTEM_PLATFORM_WIN32

    return DialogBoxCommand::PlatformUnknown;

#endif  // SYSTEM_PLATFORM_WIN32
}
