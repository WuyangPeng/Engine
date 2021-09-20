///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/22 11:29)

#include "System/SystemExport.h"

#include "MessageBoxSelection.h"
#include "Flags/MessageBoxFlags.h"
#include "Data/LanguageIDData.h"
#include "Data/MessageBoxFlagsData.h"
#include "System/Helper/EnumCast.h"

namespace System
{
    static constexpr MessageBoxFlagsData defaultMessageBoxFlagsData{ MessageBoxType::YesNoCancel,
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

    NullFunction<const char*, const char*>(text, caption);

    return DialogBoxCommand::PlatformUnknown;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DialogBoxCommand System::MessageBoxSelectionWithWChar(const wchar_t* text, const wchar_t* caption) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto selection = ::MessageBoxW(nullptr, text, caption, defaultMessageBoxFlagsData.GetFlag());

    return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const wchar_t*, const wchar_t*>(text, caption);

    return DialogBoxCommand::PlatformUnknown;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DialogBoxCommand System::MessageBoxSelectionWithTChar(const TChar* text, const TChar* caption) noexcept
{
    return MessageBoxSelection(nullptr, text, caption, defaultMessageBoxFlagsData);
}

System::DialogBoxCommand System::MessageBoxSelection(WindowsHWnd hwnd,
                                                     const TChar* text,
                                                     const TChar* caption,
                                                     const MessageBoxFlagsData& flagsData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto selection = ::MessageBox(hwnd, text, caption, flagsData.GetFlag());

    return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHWnd, const TChar*, const TChar*, MessageBoxFlagsData>(hwnd, text, caption, flagsData);

    return DialogBoxCommand::PlatformUnknown;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DialogBoxCommand System::MessageBoxSelection(WindowsHWnd hwnd,
                                                     const TChar* text,
                                                     const TChar* caption,
                                                     const MessageBoxFlagsData& flagsData,
                                                     const LanguageIDData& languageIDData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto selection = ::MessageBoxEx(hwnd, text, caption, flagsData.GetFlag(), languageIDData.GetLanguageID());

    return UnderlyingCastEnum<DialogBoxCommand>(selection);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHWnd, const TChar*, const TChar*, MessageBoxFlagsData, LanguageIDData>(hwnd, text, caption, flagsData, languageIDData);

    return DialogBoxCommand::PlatformUnknown;

#endif  // SYSTEM_PLATFORM_WIN32
}
