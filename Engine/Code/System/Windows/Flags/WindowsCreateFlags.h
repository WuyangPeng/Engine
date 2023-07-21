///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/20 11:37)

#ifndef SYSTEM_WINDOWS_WINDOWS_CREATE_FLAGS_H
#define SYSTEM_WINDOWS_WINDOWS_CREATE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class SystemMenuCommand
    {
        Size = SC_SIZE,
        Move = SC_MOVE,
        Minimize = SC_MINIMIZE,
        Maximize = SC_MAXIMIZE,
        NextWindow = SC_NEXTWINDOW,
        PrevWindow = SC_PREVWINDOW,
        Close = SC_CLOSE,
        VScroll = SC_VSCROLL,
        HScroll = SC_HSCROLL,
        MouseMenu = SC_MOUSEMENU,
        KeyMenu = SC_KEYMENU,
        Arrange = SC_ARRANGE,
        Restore = SC_RESTORE,
        TaskList = SC_TASKLIST,
        ScreenSave = SC_SCREENSAVE,
        Hotkey = SC_HOTKEY,

        Default = SC_DEFAULT,
        MonitorPower = SC_MONITORPOWER,
        ContextHelp = SC_CONTEXTHELP,
        Separator = SC_SEPARATOR,

        Issecure = SCF_ISSECURE,
    };

    enum class MenuItem
    {
        Insert = MF_INSERT,
        Change = MF_CHANGE,
        Append = MF_APPEND,
        Delete = MF_DELETE,
        Remove = MF_REMOVE,

        ByCommand = MF_BYCOMMAND,
        ByPosition = MF_BYPOSITION,

        Separator = MF_SEPARATOR,

        Enabled = MF_ENABLED,
        Grayed = MF_GRAYED,
        Disabled = MF_DISABLED,

        UnChecked = MF_UNCHECKED,
        Checked = MF_CHECKED,
        UseCheckBitmaps = MF_USECHECKBITMAPS,

        String = MF_STRING,
        Bitmap = MF_BITMAP,
        Ownerdraw = MF_OWNERDRAW,

        Popup = MF_POPUP,
        MenuBarBreak = MF_MENUBARBREAK,
        MenuBreak = MF_MENUBREAK,

        UnHilite = MF_UNHILITE,
        Hilite = MF_HILITE,

        Default = MF_DEFAULT,

        SysMenu = MF_SYSMENU,
        Help = MF_HELP,

        RightJustify = MF_RIGHTJUSTIFY,

        MouseSelect = MF_MOUSESELECT,

        End = MF_END,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class SystemMenuCommand
    {
        Size = 0xF000,
        Move = 0xF010,
        Minimize = 0xF020,
        Maximize = 0xF030,
        NextWindow = 0xF040,
        PrevWindow = 0xF050,
        Close = 0xF060,
        VScroll = 0xF070,
        HScroll = 0xF080,
        MouseMenu = 0xF090,
        KeyMenu = 0xF100,
        Arrange = 0xF110,
        Restore = 0xF120,
        TaskList = 0xF130,
        ScreenSave = 0xF140,
        Hotkey = 0xF150,

        Default = 0xF160,
        MonitorPower = 0xF170,
        ContextHelp = 0xF180,
        Separator = 0xF00F,

        Issecure = 0x00000001,
    };

    enum class MenuItem
    {
        Insert = 0x00000000L,
        Change = 0x00000080L,
        Append = 0x00000100L,
        Delete = 0x00000200L,
        Remove = 0x00001000L,

        ByCommand = 0x00000000L,
        ByPosition = 0x00000400L,

        Separator = 0x00000800L,

        Enabled = 0x00000000L,
        Grayed = 0x00000001L,
        Disabled = 0x00000002L,

        UnChecked = 0x00000000L,
        Checked = 0x00000008L,
        UseCheckBitmaps = 0x00000200L,

        String = 0x00000000L,
        Bitmap = 0x00000004L,
        Ownerdraw = 0x00000100L,

        Popup = 0x00000010L,
        MenuBarBreak = 0x00000020L,
        MenuBreak = 0x00000040L,

        UnHilite = 0x00000000L,
        Hilite = 0x00000080L,

        Default = 0x00001000L,

        SysMenu = 0x00002000L,
        Help = 0x00004000L,

        RightJustify = 0x00004000L,

        MouseSelect = 0x00008000L,

        End = 0x00000080L,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOWS_WINDOWS_CREATE_FLAGS_H
