/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 15:40)

#ifndef SYSTEM_WINDOWS_WINDOWS_REGISTRY_USING_H
#define SYSTEM_WINDOWS_WINDOWS_REGISTRY_USING_H

#include "WindowsUsing.h"
#include "System/Helper/Platform.h"
#include "System/Helper/UnicodeUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using SystemHKey = HKEY;
    using SystemRegSam = REGSAM;

    static const SystemHKey gClassesRoot{ HKEY_CLASSES_ROOT };
    static const SystemHKey gCurrentUser{ HKEY_CURRENT_USER };
    static const SystemHKey gLocalMachine{ HKEY_LOCAL_MACHINE };
    static const SystemHKey gUsers{ HKEY_USERS };
    static const SystemHKey gPerformanceData{ HKEY_PERFORMANCE_DATA };
    static const SystemHKey gPerformanceText{ HKEY_PERFORMANCE_TEXT };
    static const SystemHKey gPerformanceNaturalLanguageSpeechText{ HKEY_PERFORMANCE_NLSTEXT };
    static const SystemHKey gCurrentConfig{ HKEY_CURRENT_CONFIG };
    static const SystemHKey gDynData{ HKEY_DYN_DATA };
    static const SystemHKey gCurrentUserLocalSettings{ HKEY_CURRENT_USER_LOCAL_SETTINGS };

    static const TChar* gArrow{ IDC_ARROW };
    static const TChar* gIbeam{ IDC_IBEAM };
    static const TChar* gWait{ IDC_WAIT };
    static const TChar* gCross{ IDC_CROSS };
    static const TChar* gUpArrow{ IDC_UPARROW };
    static const TChar* gSize{ IDC_SIZE };
    static const TChar* gIcon{ IDC_ICON };
    static const TChar* gSizeNwse{ IDC_SIZENWSE };
    static const TChar* gSizeNesw{ IDC_SIZENESW };
    static const TChar* gSizeWe{ IDC_SIZEWE };
    static const TChar* gSizeNs{ IDC_SIZENS };
    static const TChar* gSizeAll{ IDC_SIZEALL };
    static const TChar* gNo{ IDC_NO };
    static const TChar* gIdcHand{ IDC_HAND };
    static const TChar* gAppStarting{ IDC_APPSTARTING };
    static const TChar* gHelp{ IDC_HELP };
    static const TChar* gPin{ IDC_PIN };
    static const TChar* gPerson{ IDC_PERSON };

    static const TChar* gApplication{ IDI_APPLICATION };
    static const TChar* gIdiHand{ IDI_HAND };
    static const TChar* gQuestion{ IDI_QUESTION };
    static const TChar* gExclamation{ IDI_EXCLAMATION };
    static const TChar* gAsterisk{ IDI_ASTERISK };
    static const TChar* gWinLogo{ IDI_WINLOGO };
    static const TChar* gShield{ IDI_SHIELD };
    static const TChar* gWarning{ IDI_WARNING };
    static const TChar* gError{ IDI_ERROR };
    static const TChar* gInformation{ IDI_INFORMATION };

#else  // !SYSTEM_PLATFORM_WIN32

    struct SystemHKey
    {
        uint32_t unused;

        explicit SystemHKey(uint32_t key)
            : unused{ key }
        {
        }
    };

    using SystemRegSam = uint32_t;

    static const SystemHKey gClassesRoot{ 0x80000000 };
    static const SystemHKey gCurrentUser{ 0x80000001 };
    static const SystemHKey gLocalMachine{ 0x80000002 };
    static const SystemHKey gUsers{ 0x80000003 };
    static const SystemHKey gPerformanceData{ 0x80000004 };
    static const SystemHKey gPerformanceText{ 0x80000050 };
    static const SystemHKey gPerformanceNaturalLanguageSpeechText{ 0x80000060 };
    static const SystemHKey gCurrentConfig{ 0x80000005 };
    static const SystemHKey gDynData{ 0x80000006 };
    static const SystemHKey gCurrentUserLocalSettings{ 0x80000007 };

    static const TChar* gArrow{ SYSTEM_TEXT("IDC_ARROW") };
    static const TChar* gIbeam{ SYSTEM_TEXT("IDC_IBEAM") };
    static const TChar* gWait{ SYSTEM_TEXT("IDC_WAIT") };
    static const TChar* gCross{ SYSTEM_TEXT("IDC_CROSS") };
    static const TChar* gUpArrow{ SYSTEM_TEXT("IDC_UPARROW") };
    static const TChar* gSize{ SYSTEM_TEXT("IDC_SIZE") };
    static const TChar* gIcon{ SYSTEM_TEXT("IDC_ICON") };
    static const TChar* gSizeNwse{ SYSTEM_TEXT("IDC_SIZENWSE") };
    static const TChar* gSizeNesw{ SYSTEM_TEXT("IDC_SIZENESW") };
    static const TChar* gSizeWe{ SYSTEM_TEXT("IDC_SIZEWE") };
    static const TChar* gSizeNs{ SYSTEM_TEXT("IDC_SIZENS") };
    static const TChar* gSizeAll{ SYSTEM_TEXT("IDC_SIZEALL") };
    static const TChar* gNo{ SYSTEM_TEXT("IDC_NO") };
    static const TChar* gIdcHand{ SYSTEM_TEXT("IDC_HAND") };
    static const TChar* gAppStarting{ SYSTEM_TEXT("IDC_APPSTARTING") };
    static const TChar* gHelp{ SYSTEM_TEXT("IDC_HELP") };
    static const TChar* gPin{ SYSTEM_TEXT("IDC_PIN") };
    static const TChar* gPerson{ SYSTEM_TEXT("IDC_PERSON") };

    static const TChar* gApplication{ SYSTEM_TEXT("IDI_APPLICATION") };
    static const TChar* gIdiHand{ SYSTEM_TEXT("IDI_HAND") };
    static const TChar* gQuestion{ SYSTEM_TEXT("IDI_QUESTION") };
    static const TChar* gExclamation{ SYSTEM_TEXT("IDI_EXCLAMATION") };
    static const TChar* gAsterisk{ SYSTEM_TEXT("IDI_ASTERISK") };
    static const TChar* gWinLogo{ SYSTEM_TEXT("IDI_WINLOGO") };
    static const TChar* gShield{ SYSTEM_TEXT("IDI_SHIELD") };
    static const TChar* gWarning{ SYSTEM_TEXT("IDI_WARNING") };
    static const TChar* gError{ SYSTEM_TEXT("IDI_ERROR") };
    static const TChar* gInformation{ SYSTEM_TEXT("IDI_INFORMATION") };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOWS_WINDOWS_REGISTRY_USING_H
