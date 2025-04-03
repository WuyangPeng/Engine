/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 16:20)

#ifndef SYSTEM_WINDOWS_WINDOWS_FLAGS_H
#define SYSTEM_WINDOWS_WINDOWS_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WindowsPointUse
    {
        Default = CW_USEDEFAULT,
    };

    enum class WindowsStyles : uint32_t
    {
        Border = WS_BORDER,
        Caption = WS_CAPTION,
        Child = WS_CHILD,
        ChildWindow = WS_CHILDWINDOW,
        ClipChildren = WS_CLIPCHILDREN,
        ClipSiblings = WS_CLIPSIBLINGS,
        Disabled = WS_DISABLED,
        DlgFrame = WS_DLGFRAME,
        Group = WS_GROUP,
        HScroll = WS_HSCROLL,
        Iconic = WS_ICONIC,
        Maximize = WS_MAXIMIZE,
        MaximizeBox = WS_MAXIMIZEBOX,
        Minimize = WS_MINIMIZE,
        MinimizeBox = WS_MINIMIZEBOX,
        Overlapped = WS_OVERLAPPED,
        OverlappedWindow = WS_OVERLAPPEDWINDOW,
        Popup = WS_POPUP,
        PopupWindow = WS_POPUPWINDOW,
        SizeBox = WS_SIZEBOX,
        SysMenu = WS_SYSMENU,
        TabStop = WS_TABSTOP,
        ThickFrame = WS_THICKFRAME,
        Tiled = WS_TILED,
        TiledWindow = WS_TILEDWINDOW,
        Visible = WS_VISIBLE,
        VScroll = WS_VSCROLL,
        Default = OverlappedWindow | Visible,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class WindowsPointUse
    {
        Default = (int)0x80000000,
    };

    enum class WindowsStyles : uint32_t
    {
        Border = 0x00800000L,
        Caption = 0x00C00000L,
        Child = 0x40000000L,
        ChildWindow = 0x40000000L,
        ClipChildren = 0x02000000L,
        ClipSiblings = 0x04000000L,
        Disabled = 0x08000000L,
        DlgFrame = 0x00400000L,
        Group = 0x00020000L,
        HScroll = 0x00100000L,
        Iconic = 0x20000000L,
        Maximize = 0x01000000L,
        MaximizeBox = 0x00010000L,
        Minimize = 0x20000000L,
        MinimizeBox = 0x00020000L,
        Overlapped = 0x00000000L,
        SysMenu = 0x00080000L,
        ThickFrame = 0x00040000L,
        OverlappedWindow = (Overlapped | Caption | SysMenu | ThickFrame | MinimizeBox | MaximizeBox),
        Popup = 0x80000000L,
        PopupWindow = (Popup | Border | SysMenu),
        SizeBox = 0x00040000L,
        TabStop = 0x00010000L,
        Tiled = 0x00000000L,
        TiledWindow = (Overlapped | Caption | SysMenu | ThickFrame | MinimizeBox | MaximizeBox),
        Visible = 0x10000000L,
        VScroll = 0x00200000L,
        Default = OverlappedWindow | Visible,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOWS_WINDOWS_FLAGS_H
