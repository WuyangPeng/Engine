///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/30 14:58)

#ifndef SYSTEM_SECURITY_ADD_ACCESS_FLAGS_H
#define SYSTEM_SECURITY_ADD_ACCESS_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class SpecificAccess
    {
        DesktopReadObjects = DESKTOP_READOBJECTS,
        DesktopCreateWindow = DESKTOP_CREATEWINDOW,
        DesktopCreateMenu = DESKTOP_CREATEMENU,
        DesktopHookControl = DESKTOP_HOOKCONTROL,
        DesktopJournalRecord = DESKTOP_JOURNALRECORD,
        DesktopJournalPlayBack = DESKTOP_JOURNALPLAYBACK,
        DesktopEnumerate = DESKTOP_ENUMERATE,
        DesktopWriteObjects = DESKTOP_WRITEOBJECTS,
        DesktopSwitchDesktop = DESKTOP_SWITCHDESKTOP,
        DesktopAllAccess = DesktopReadObjects |
                           DesktopCreateWindow |
                           DesktopCreateMenu |
                           DesktopHookControl |
                           DesktopJournalRecord |
                           DesktopJournalPlayBack |
                           DesktopEnumerate |
                           DesktopWriteObjects |
                           DesktopSwitchDesktop,

        WinStaEnumDesktops = WINSTA_ENUMDESKTOPS,
        WinStaReadAttributes = WINSTA_READATTRIBUTES,
        WinStaAccessClipboard = WINSTA_ACCESSCLIPBOARD,
        WinStaCreateDesktop = WINSTA_CREATEDESKTOP,
        WinStaWriteAttributes = WINSTA_WRITEATTRIBUTES,
        WinStaAccessGlobalAtoms = WINSTA_ACCESSGLOBALATOMS,
        WinStaExitWindows = WINSTA_EXITWINDOWS,
        WinStaEnumerate = WINSTA_ENUMERATE,
        WinStaReadScreen = WINSTA_READSCREEN,
        WinStaAllAccess = WINSTA_ALL_ACCESS,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class SpecificAccess
    {
        DesktopReadObjects = 0x0001L,
        DesktopCreateWindow = 0x0002L,
        DesktopCreateMenu = 0x0004L,
        DesktopHookControl = 0x0008L,
        DesktopJournalRecord = 0x0010L,
        DesktopJournalPlayBack = 0x0020L,
        DesktopEnumerate = 0x0040L,
        DesktopWriteObjects = 0x0080L,
        DesktopSwitchDesktop = 0x0100L,
        DesktopAllAccess = DesktopReadObjects |
                           DesktopCreateWindow |
                           DesktopCreateMenu |
                           DesktopHookControl |
                           DesktopJournalRecord |
                           DesktopJournalPlayBack |
                           DesktopEnumerate |
                           DesktopWriteObjects |
                           DesktopSwitchDesktop,

        WinStaEnumDesktops = 0x0001L,
        WinStaReadAttributes = 0x0002L,
        WinStaAccessClipboard = 0x0004L,
        WinStaCreateDesktop = 0x0008L,
        WinStaWriteAttributes = 0x0010L,
        WinStaAccessGlobalAtoms = 0x0020L,
        WinStaExitWindows = 0x0040L,
        WinStaEnumerate = 0x0100L,
        WinStaReadScreen = 0x0200L,

        WinStaAllAccess = (WinStaEnumDesktops |
                           WinStaReadAttributes |
                           WinStaAccessClipboard |
                           WinStaCreateDesktop |
                           WinStaWriteAttributes |
                           WinStaAccessGlobalAtoms |
                           WinStaExitWindows |
                           WinStaEnumerate |
                           WinStaReadScreen),
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_ADD_ACCESS_FLAGS_H
