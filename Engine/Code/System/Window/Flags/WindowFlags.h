// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:35)

#ifndef SYSTEM_WINDOW_WINDOW_FLAGS_H
#define SYSTEM_WINDOW_WINDOW_FLAGS_H

#include "System/Helper/Platform.h"
#include "System/Helper/EnumMacro.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	enum class WindowPointUse 
	{
		Default = CW_USEDEFAULT,
	};		

	enum class WindowStyles : uint32_t 
    {
       Border = WS_BORDER,
	   Caption = WS_CAPTION,
       Child = WS_CHILD,
       ChildWindow = WS_CHILDWINDOW,
       ClipChildren = WS_CLIPCHILDREN,
       Clipsiblings = WS_CLIPSIBLINGS,
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
		
#else // !SYSTEM_PLATFORM_WIN32

	enum class WindowPointUse 
	{
		Default = 0x80000000,
	};	

	enum class WindowStyles : uint32_t 
    {
       Border = 0x00800000L,
       Caption = 0x00C00000L,
       Child = 0x40000000L,
       ChildWindow = 0x40000000L,
       ClipChildren = 0x02000000L,
       Clipsiblings = 0x04000000L,
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
       OverlappedWindow = (Overlapped | Caption | SysMenu | ThickFrame | MinimizeBox | MaximizeBox),
       Popup = 0x80000000L,
       PopupWindow = (Popup | Border | SysMenu),
       WindowStyleSizeBox = 0x00040000L,
       WindowStyleSysMenu = 0x00080000L,
       WindowStyleTabStop = 0x00010000L,
       WindowStyleThickFrame = 0x00040000L,
       WindowStyleTiled = 0x00000000L,
       WindowStyleTiledWindow = (Overlapped | Caption | SysMenu | ThickFrame | MinimizeBox | MaximizeBox),
       WindowStyleVisible = 0x10000000L,
       WindowStyleVScroll = 0x00200000L,
	   WindowStyleDefault = OverlappedWindow | Visible,
    };  
	
#endif // SYSTEM_PLATFORM_WIN32

	ENUM_ORABLE_OPERATOR_DEFINE(WindowStyles)
}

#endif // SYSTEM_WINDOW_WINDOW_FLAGS_H
