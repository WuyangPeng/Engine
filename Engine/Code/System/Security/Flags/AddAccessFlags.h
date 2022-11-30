///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:50)

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

        WinstaEnumDesktops = WINSTA_ENUMDESKTOPS,
        WinstaReadAttributes = WINSTA_READATTRIBUTES,
        WinstaAccessClipboard = WINSTA_ACCESSCLIPBOARD,
        WinstaCreateDesktop = WINSTA_CREATEDESKTOP,
        WinstaWriteAttributes = WINSTA_WRITEATTRIBUTES,
        WinstaAccessGlobatoms = WINSTA_ACCESSGLOBALATOMS,
        WinstaExitWindows = WINSTA_EXITWINDOWS,
        WinstaEnumerate = WINSTA_ENUMERATE,
        WinstaReadScreen = WINSTA_READSCREEN,
        WinstaAllAccess = WINSTA_ALL_ACCESS,
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

        WinstaEnumDesktops = 0x0001L,
        WinstaReadAttributes = 0x0002L,
        WinstaAccessClipboard = 0x0004L,
        WinstaCreateDesktop = 0x0008L,
        WinstaWriteAttributes = 0x0010L,
        WinstaAccessGlobatoms = 0x0020L,
        WinstaExitWindows = 0x0040L,
        WinstaEnumerate = 0x0100L,
        WinstaReadScreen = 0x0200L,

        WinstaAllAccess = (WinstaEnumDesktops |
                           WinstaReadAttributes |
                           WinstaAccessClipboard |
                           WinstaCreateDesktop |
                           WinstaWriteAttributes |
                           WinstaAccessGlobatoms |
                           WinstaExitWindows |
                           WinstaEnumerate |
                           WinstaReadScreen),
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_ADD_ACCESS_FLAGS_H
