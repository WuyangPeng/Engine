//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 10:52)

#ifndef SYSTEM_WINDOW_WINDOW_REGISTRY_USING_H
#define SYSTEM_WINDOW_WINDOW_REGISTRY_USING_H

#include "WindowUsing.h"
#include "System/Helper/Platform.h"
#include "System/Helper/UnicodeUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using SystemHKey = HKEY;
    using StystemRegSam = REGSAM;

    static const SystemHKey g_ClassesRoot{ HKEY_CLASSES_ROOT };
    static const SystemHKey g_CurrentUser{ HKEY_CURRENT_USER };
    static const SystemHKey g_LocalMachine{ HKEY_LOCAL_MACHINE };
    static const SystemHKey g_Users{ HKEY_USERS };
    static const SystemHKey g_PerformanceData{ HKEY_PERFORMANCE_DATA };
    static const SystemHKey g_PerformanceText{ HKEY_PERFORMANCE_TEXT };
    static const SystemHKey g_PerformanceNlstext{ HKEY_PERFORMANCE_NLSTEXT };
    static const SystemHKey g_CurrentConfig{ HKEY_CURRENT_CONFIG };
    static const SystemHKey g_DynData{ HKEY_DYN_DATA };
    static const SystemHKey g_CurrentUserLocalSettings{ HKEY_CURRENT_USER_LOCAL_SETTINGS };

    static const TChar* g_Arrow{ IDC_ARROW };
    static const TChar* g_Ibeam{ IDC_IBEAM };
    static const TChar* g_Wait{ IDC_WAIT };
    static const TChar* g_Cross{ IDC_CROSS };
    static const TChar* g_UpArrow{ IDC_UPARROW };
    static const TChar* g_Size{ IDC_SIZE };
    static const TChar* g_Icon{ IDC_ICON };
    static const TChar* g_SizeNwse{ IDC_SIZENWSE };
    static const TChar* g_SizeNesw{ IDC_SIZENESW };
    static const TChar* g_SizeWe{ IDC_SIZEWE };
    static const TChar* g_SizeNs{ IDC_SIZENS };
    static const TChar* g_SizeAll{ IDC_SIZEALL };
    static const TChar* g_No{ IDC_NO };
    static const TChar* g_IDCHand{ IDC_HAND };
    static const TChar* g_AppStarting{ IDC_APPSTARTING };
    static const TChar* g_Help{ IDC_HELP };
    static const TChar* g_Pin{ IDC_PIN };
    static const TChar* g_Person{ IDC_PERSON };

    static const TChar* g_Application{ IDI_APPLICATION };
    static const TChar* g_IDIHand{ IDI_HAND };
    static const TChar* g_Question{ IDI_QUESTION };
    static const TChar* g_Exclamation{ IDI_EXCLAMATION };
    static const TChar* g_Asterisk{ IDI_ASTERISK };
    static const TChar* g_WinLogo{ IDI_WINLOGO };
    static const TChar* g_Shield{ IDI_SHIELD };
    static const TChar* g_Warning{ IDI_WARNING };
    static const TChar* g_Error{ IDI_ERROR };
    static const TChar* g_Information{ IDI_INFORMATION };

#else  // !SYSTEM_PLATFORM_WIN32

    struct SystemHKey
    {
        int unused;

        explicit SystemHKey(WindowPtrULong key)
            : unused{ static_cast<int>(key) }
        {
        }
    };

    using StystemRegSam = uint32_t;

    static const SystemHKey g_ClassesRoot{ 0x80000000 };
    static const SystemHKey g_CurrentUser{ 0x80000001 };
    static const SystemHKey g_LocalMachine{ 0x80000002 };
    static const SystemHKey g_Users{ 0x80000003 };
    static const SystemHKey g_PerformanceData{ 0x80000004 };
    static const SystemHKey g_PerformanceText{ 0x80000050 };
    static const SystemHKey g_PerformanceNlstext{ 0x80000060 };
    static const SystemHKey g_CurrentConfig{ 0x80000005 };
    static const SystemHKey g_DynData{ 0x80000006 };
    static const SystemHKey g_CurrentUserLocalSettings{ 0x80000007 };

    static const TChar* g_Arrow{ SYSTEM_TEXT("IDC_ARROW") };
    static const TChar* g_Ibeam{ SYSTEM_TEXT("IDC_IBEAM") };
    static const TChar* g_Wait{ SYSTEM_TEXT("IDC_WAIT") };
    static const TChar* g_Cross{ SYSTEM_TEXT("IDC_CROSS") };
    static const TChar* g_UpArrow{ SYSTEM_TEXT("IDC_UPARROW") };
    static const TChar* g_Size{ SYSTEM_TEXT("IDC_SIZE") };
    static const TChar* g_Icon{ SYSTEM_TEXT("IDC_ICON") };
    static const TChar* g_SizeNwse{ SYSTEM_TEXT("IDC_SIZENWSE") };
    static const TChar* g_SizeNesw{ SYSTEM_TEXT("IDC_SIZENESW") };
    static const TChar* g_SizeWe{ SYSTEM_TEXT("IDC_SIZEWE") };
    static const TChar* g_SizeNs{ SYSTEM_TEXT("IDC_SIZENS") };
    static const TChar* g_SizeAll{ SYSTEM_TEXT("IDC_SIZEALL") };
    static const TChar* g_No{ SYSTEM_TEXT("IDC_NO") };
    static const TChar* g_IDCHand{ SYSTEM_TEXT("IDC_HAND") };
    static const TChar* g_AppStarting{ SYSTEM_TEXT("IDC_APPSTARTING") };
    static const TChar* g_Help{ SYSTEM_TEXT("IDC_HELP") };
    static const TChar* g_Pin{ SYSTEM_TEXT("IDC_PIN") };
    static const TChar* g_Person{ SYSTEM_TEXT("IDC_PERSON") };

    static const TChar* g_Application{ SYSTEM_TEXT("IDI_APPLICATION") };
    static const TChar* g_IDIHand{ SYSTEM_TEXT("IDI_HAND") };
    static const TChar* g_Question{ SYSTEM_TEXT("IDI_QUESTION") };
    static const TChar* g_Exclamation{ SYSTEM_TEXT("IDI_EXCLAMATION") };
    static const TChar* g_Asterisk{ SYSTEM_TEXT("IDI_ASTERISK") };
    static const TChar* g_WinLogo{ SYSTEM_TEXT("IDI_WINLOGO") };
    static const TChar* g_Shield{ SYSTEM_TEXT("IDI_SHIELD") };
    static const TChar* g_Warning{ SYSTEM_TEXT("IDI_WARNING") };
    static const TChar* g_Error{ SYSTEM_TEXT("IDI_ERROR") };
    static const TChar* g_Information{ SYSTEM_TEXT("IDI_INFORMATION") };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOW_WINDOW_REGISTRY_USING_H
