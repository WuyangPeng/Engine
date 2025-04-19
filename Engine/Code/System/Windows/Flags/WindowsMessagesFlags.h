/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 16:18)

#ifndef SYSTEM_WINDOWS_WINDOWS_MESSAGES_FLAGS_H
#define SYSTEM_WINDOWS_WINDOWS_MESSAGES_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WindowsMessages
    {
        Null = WM_NULL,
        Create = WM_CREATE,
        Destroy = WM_DESTROY,
        Move = WM_MOVE,
        Size = WM_SIZE,

        Activate = WM_ACTIVATE,
        SetFocus = WM_SETFOCUS,
        KillFocus = WM_KILLFOCUS,
        Enable = WM_ENABLE,
        SetRedraw = WM_SETREDRAW,
        SetText = WM_SETTEXT,
        GetText = WM_GETTEXT,
        GetTextLength = WM_GETTEXTLENGTH,
        Paint = WM_PAINT,
        Close = WM_CLOSE,

        QueryEndSession = WM_QUERYENDSESSION,
        QueryOpen = WM_QUERYOPEN,
        EndSession = WM_ENDSESSION,

        Quit = WM_QUIT,
        EraseBackground = WM_ERASEBKGND,
        ShowWindow = WM_SHOWWINDOW,
        WinIniChange = WM_WININICHANGE,

        SettingChange = WM_SETTINGCHANGE,

        DevModeChange = WM_DEVMODECHANGE,
        ActivateApp = WM_ACTIVATEAPP,
        FontChange = WM_FONTCHANGE,
        TimeChange = WM_TIMECHANGE,
        CancelMode = WM_CANCELMODE,
        SetCursor = WM_SETCURSOR,
        MouseActivate = WM_MOUSEACTIVATE,
        ChildActivate = WM_CHILDACTIVATE,
        QueueSync = WM_QUEUESYNC,

        GetMinMaxInfo = WM_GETMINMAXINFO,
        PaintIcon = WM_PAINTICON,
        IconEraseBackground = WM_ICONERASEBKGND,
        NextDlgCtl = WM_NEXTDLGCTL,
        SpoolerStatus = WM_SPOOLERSTATUS,
        DrawItem = WM_DRAWITEM,
        MeasureItem = WM_MEASUREITEM,
        DeleteItem = WM_DELETEITEM,
        VirtualKeyToItem = WM_VKEYTOITEM,
        CharToItem = WM_CHARTOITEM,
        SetFont = WM_SETFONT,
        GetFont = WM_GETFONT,
        SetHotKey = WM_SETHOTKEY,
        GetHotKey = WM_GETHOTKEY,
        QueryDragIcon = WM_QUERYDRAGICON,
        CompareItem = WM_COMPAREITEM,

        GetObjectMessage = WM_GETOBJECT,

        Compacting = WM_COMPACTING,
        CommNotify = WM_COMMNOTIFY,  // 不再支持
        WindowPosChanging = WM_WINDOWPOSCHANGING,
        WindowPosChanged = WM_WINDOWPOSCHANGED,

        Power = WM_POWER,
        CopyData = WM_COPYDATA,
        CancelJournal = WM_CANCELJOURNAL,
        Notify = WM_NOTIFY,
        InputLangChangeRequest = WM_INPUTLANGCHANGEREQUEST,
        InputLangChange = WM_INPUTLANGCHANGE,
        TaskCard = WM_TCARD,
        Help = WM_HELP,
        UserChanged = WM_USERCHANGED,
        NotifyFormat = WM_NOTIFYFORMAT,
        ContextMenu = WM_CONTEXTMENU,
        StyleChanging = WM_STYLECHANGING,
        StyleChanged = WM_STYLECHANGED,
        DisplayChange = WM_DISPLAYCHANGE,
        GetIcon = WM_GETICON,
        SetIcon = WM_SETICON,

        NcCreate = WM_NCCREATE,
        NcDestroy = WM_NCDESTROY,
        NcCalcSize = WM_NCCALCSIZE,
        NcChitTest = WM_NCHITTEST,
        NcPaint = WM_NCPAINT,
        NcActivate = WM_NCACTIVATE,
        GetDlgCode = WM_GETDLGCODE,

        SyncPaint = WM_SYNCPAINT,

        NcMouseMove = WM_NCMOUSEMOVE,
        NcLButtonDown = WM_NCLBUTTONDOWN,
        NcLButtonUp = WM_NCLBUTTONUP,
        NcLButtonDoubleClick = WM_NCLBUTTONDBLCLK,
        NcRButtonDown = WM_NCRBUTTONDOWN,
        NcRButtonUp = WM_NCRBUTTONUP,
        NcRButtonDoubleClick = WM_NCRBUTTONDBLCLK,
        NcMButtonDown = WM_NCMBUTTONDOWN,
        NcMButtonUp = WM_NCMBUTTONUP,
        NcMButtonDoubleClick = WM_NCMBUTTONDBLCLK,

        NcXButtonDown = WM_NCXBUTTONDOWN,
        NcXButtonUp = WM_NCXBUTTONUP,
        NcXButtonDoubleClick = WM_NCXBUTTONDBLCLK,

        InputDeviceChange = WM_INPUT_DEVICE_CHANGE,
        Input = WM_INPUT,

        KeyFirst = WM_KEYFIRST,
        KeyDown = WM_KEYDOWN,
        KeyUp = WM_KEYUP,
        Char = WM_CHAR,
        DeadChar = WM_DEADCHAR,
        SysKeyDown = WM_SYSKEYDOWN,
        SysKeyUp = WM_SYSKEYUP,
        SysChar = WM_SYSCHAR,
        SysDeadChar = WM_SYSDEADCHAR,

        UniChar = WM_UNICHAR,
        KeyLast = WM_KEYLAST,
        NoChar = UNICODE_NOCHAR,

        StartComPosition = WM_IME_STARTCOMPOSITION,
        EndComPosition = WM_IME_ENDCOMPOSITION,
        ComPosition = WM_IME_COMPOSITION,
        ImeKeyLast = WM_IME_KEYLAST,

        InitDialog = WM_INITDIALOG,
        Command = WM_COMMAND,
        SysCommand = WM_SYSCOMMAND,
        Timer = WM_TIMER,
        HScroll = WM_HSCROLL,
        VScroll = WM_VSCROLL,
        InitMenu = WM_INITMENU,
        InitMenuPopup = WM_INITMENUPOPUP,

        Gesture = WM_GESTURE,
        GestureNotify = WM_GESTURENOTIFY,

        MenuSelect = WM_MENUSELECT,
        MenuChar = WM_MENUCHAR,
        EnterIdle = WM_ENTERIDLE,

        MenuRButtonUp = WM_MENURBUTTONUP,
        MenuDrag = WM_MENUDRAG,
        MenuGetObject = WM_MENUGETOBJECT,
        UnInitMenuPopup = WM_UNINITMENUPOPUP,
        MenuCommand = WM_MENUCOMMAND,

        ChangeUiState = WM_CHANGEUISTATE,
        UpdateUiState = WM_UPDATEUISTATE,
        QueryUiState = WM_QUERYUISTATE,
        CtlColorMsgBox = WM_CTLCOLORMSGBOX,
        CtlColorEdit = WM_CTLCOLOREDIT,
        CtlColorListBox = WM_CTLCOLORLISTBOX,
        CtlColorBtn = WM_CTLCOLORBTN,
        CtlColorDlg = WM_CTLCOLORDLG,
        CtlColorScrollBar = WM_CTLCOLORSCROLLBAR,
        CtlColorStatic = WM_CTLCOLORSTATIC,
        GetHMenu = MN_GETHMENU,

        MouseFirst = WM_MOUSEFIRST,
        MouseMove = WM_MOUSEMOVE,
        LButtonDown = WM_LBUTTONDOWN,
        LButtonUp = WM_LBUTTONUP,
        LButtonDoubleClick = WM_LBUTTONDBLCLK,
        RButtonDown = WM_RBUTTONDOWN,
        RButtonUp = WM_RBUTTONUP,
        RButtonDoubleClick = WM_RBUTTONDBLCLK,
        MButtonDown = WM_MBUTTONDOWN,
        MButtonUp = WM_MBUTTONUP,
        MButtonDoubleClick = WM_MBUTTONDBLCLK,

        MouseWheel = WM_MOUSEWHEEL,

        XButtonDown = WM_XBUTTONDOWN,
        XButtonUp = WM_XBUTTONUP,
        XButtonDoubleClick = WM_XBUTTONDBLCLK,

        MouseHWheel = WM_MOUSEHWHEEL,

        MouseLast = WM_MOUSELAST,
        ParentNotify = WM_PARENTNOTIFY,
        EnterMenuLoop = WM_ENTERMENULOOP,
        ExitMenuLoop = WM_EXITMENULOOP,

        NextMenu = WM_NEXTMENU,
        Sizing = WM_SIZING,
        CaptureChanged = WM_CAPTURECHANGED,
        Moving = WM_MOVING,

        PowerBroadCast = 0x0218,

        DeviceChange = WM_DEVICECHANGE,

        MdiCreate = WM_MDICREATE,
        MdiDestroy = WM_MDIDESTROY,
        MdiActivate = WM_MDIACTIVATE,
        MdiRestore = WM_MDIRESTORE,
        MdiNext = WM_MDINEXT,
        MdiMaximize = WM_MDIMAXIMIZE,
        MdiTile = WM_MDITILE,
        MdiCascade = WM_MDICASCADE,
        MdiIconArrange = WM_MDIICONARRANGE,
        MdiGetActive = WM_MDIGETACTIVE,

        MdiSetMenu = WM_MDISETMENU,
        EnterSizeMove = WM_ENTERSIZEMOVE,
        ExitSizeMove = WM_EXITSIZEMOVE,
        DropFiles = WM_DROPFILES,
        MdiRefreshMenu = WM_MDIREFRESHMENU,

        Touch = WM_TOUCH,

        ImeSetContext = WM_IME_SETCONTEXT,
        ImeNotify = WM_IME_NOTIFY,
        ImeControl = WM_IME_CONTROL,
        ImeCompositionFull = WM_IME_COMPOSITIONFULL,
        ImeSelect = WM_IME_SELECT,
        ImeChar = WM_IME_CHAR,

        ImeRequest = WM_IME_REQUEST,

        ImeKeyDown = WM_IME_KEYDOWN,
        ImeKeyUp = WM_IME_KEYUP,

        MouseHover = WM_MOUSEHOVER,
        MouseLeave = WM_MOUSELEAVE,

        NcMouseHover = WM_NCMOUSEHOVER,
        NcMouseLeave = WM_NCMOUSELEAVE,

        WtsSessionChange = WM_WTSSESSION_CHANGE,

        TabletFirst = WM_TABLET_FIRST,
        TabletLast = WM_TABLET_LAST,

        Cut = WM_CUT,
        Copy = WM_COPY,
        Paste = WM_PASTE,
        Clear = WM_CLEAR,
        Undo = WM_UNDO,
        RenderFormat = WM_RENDERFORMAT,
        RenderAllFormats = WM_RENDERALLFORMATS,
        DestroyClipboard = WM_DESTROYCLIPBOARD,
        DrawClipboard = WM_DRAWCLIPBOARD,
        PaintClipboard = WM_PAINTCLIPBOARD,
        VerticalScrollClipboard = WM_VSCROLLCLIPBOARD,
        SizeClipboard = WM_SIZECLIPBOARD,
        AskCbFormatName = WM_ASKCBFORMATNAME,
        ChangeCbChain = WM_CHANGECBCHAIN,
        HScrollClipboard = WM_HSCROLLCLIPBOARD,
        QueryNewPalette = WM_QUERYNEWPALETTE,
        PaletteIsChanging = WM_PALETTEISCHANGING,
        PaletteChanged = WM_PALETTECHANGED,
        HotKey = WM_HOTKEY,

        Print = WM_PRINT,
        PrintClient = WM_PRINTCLIENT,

        AppCommand = WM_APPCOMMAND,

        ThemeChanged = WM_THEMECHANGED,

        ClipBoardUpdate = WM_CLIPBOARDUPDATE,

        DwmComPositionChanged = WM_DWMCOMPOSITIONCHANGED,
        DwmNcRenderingChanged = WM_DWMNCRENDERINGCHANGED,
        DwmColorizationColorChanged = WM_DWMCOLORIZATIONCOLORCHANGED,
        DwmWindowMaximizedChange = WM_DWMWINDOWMAXIMIZEDCHANGE,

        DwmSendIconicThumbnail = WM_DWMSENDICONICTHUMBNAIL,
        DwmSendIconicLivePreviewBitmap = WM_DWMSENDICONICLIVEPREVIEWBITMAP,

        GetTitleBarInfoExtended = WM_GETTITLEBARINFOEX,

        HandheldFirst = WM_HANDHELDFIRST,
        HandheldLast = WM_HANDHELDLAST,

        AfxFirst = WM_AFXFIRST,
        AfxLast = WM_AFXLAST,

        PenWinFirst = WM_PENWINFIRST,
        PenWinLast = WM_PENWINLAST,

        App = WM_APP,

        User = WM_USER,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class WindowsMessages
    {
        Null = 0x0000,
        Create = 0x0001,
        Destroy = 0x0002,
        Move = 0x0003,
        Size = 0x0005,

        Activate = 0x0006,
        SetFocus = 0x0007,
        KillFocus = 0x0008,
        Enable = 0x000A,
        SetRedraw = 0x000B,
        SetText = 0x000C,
        GetText = 0x000D,
        GetTextLength = 0x000E,
        Paint = 0x000F,
        Close = 0x0010,

        QueryEndSession = 0x0011,
        QueryOpen = 0x0013,
        EndSession = 0x0016,

        Quit = 0x0012,
        EraseBackground = 0x0014,
        ShowWindow = 0x0018,
        WinIniChange = 0x001A,

        SettingChange = WinIniChange,

        DevModeChange = 0x001B,
        ActivateApp = 0x001C,
        FontChange = 0x001D,
        TimeChange = 0x001E,
        CancelMode = 0x001F,
        SetCursor = 0x0020,
        MouseActivate = 0x0021,
        ChildActivate = 0x0022,
        QueueSync = 0x0023,

        GetMinMaxInfo = 0x0024,
        PaintIcon = 0x0026,
        IconEraseBkgnd = 0x0027,
        NextDlgCtl = 0x0028,
        SpoolerStatus = 0x002A,
        DrawItem = 0x002B,
        MeasureItem = 0x002C,
        DeleteItem = 0x002D,
        VirtualKeyToItem = 0x002E,
        CharToItem = 0x002F,
        SetFont = 0x0030,
        GetFont = 0x0031,
        SetHotKey = 0x0032,
        GetHotKey = 0x0033,
        QueryDragIcon = 0x0037,
        CompareItem = 0x0039,

        GetObjectMessage = 0x003D,

        Compacting = 0x0041,
        CommNotify = 0x0044,
        WindowPosChanging = 0x0046,
        WindowPosChanged = 0x0047,

        Power = 0x0048,
        CopyData = 0x004A,
        CancelJournal = 0x004B,
        Notify = 0x004E,
        InputLangChangeRequest = 0x0050,
        InputLangChange = 0x0051,
        TaskCard = 0x0052,
        Help = 0x0053,
        UserChanged = 0x0054,
        NotifyFormat = 0x0055,
        ContextMenu = 0x007B,
        StyleChanging = 0x007C,
        StyleChanged = 0x007D,
        DisplayChange = 0x007E,
        GetIcon = 0x007F,
        SetIcon = 0x0080,

        NcCreate = 0x0081,
        NcDestroy = 0x0082,
        NcCalcSize = 0x0083,
        NcChitTest = 0x0084,
        NcPaint = 0x0085,
        NcActivate = 0x0086,
        GetDlgCode = 0x0087,

        SyncPaint = 0x0088,

        NcMouseMove = 0x00A0,
        NcLButtonDown = 0x00A1,
        NcLButtonUp = 0x00A2,
        NcLButtonDoubleClick = 0x00A3,
        NcRButtonDown = 0x00A4,
        NcRButtonUp = 0x00A5,
        NcRButtonDoubleClick = 0x00A6,
        NcMButtonDown = 0x00A7,
        NcMButtonUp = 0x00A8,
        NcMButtonDoubleClick = 0x00A9,

        NcXButtonDown = 0x00AB,
        NcXButtonUp = 0x00AC,
        NcXButtonDoubleClick = 0x00AD,

        InputDeviceChange = 0x00FE,
        Input = 0x00FF,

        KeyFirst = 0x0100,
        KeyDown = 0x0100,
        KeyUp = 0x0101,
        Char = 0x0102,
        DeadChar = 0x0103,
        SysKeyDown = 0x0104,
        SysKeyUp = 0x0105,
        SysChar = 0x0106,
        SysDeadChar = 0x0107,

        UniChar = 0x0109,
        KeyLast = 0x0109,
        NoChar = 0xFFFF,

        StartComPosition = 0x010D,
        EndComPosition = 0x010E,
        ComPosition = 0x010F,
        ImeKeyLast = 0x010F,

        InitDialog = 0x0110,
        Command = 0x0111,
        SysCommand = 0x0112,
        Timer = 0x0113,
        HScroll = 0x0114,
        VScroll = 0x0115,
        InitMenu = 0x0116,
        InitMenuPopup = 0x0117,

        Gesture = 0x0119,
        GestureNotify = 0x011A,

        MenuSelect = 0x011F,
        MenuChar = 0x0120,
        EnterIdle = 0x0121,

        MenuRButtonUp = 0x0122,
        MenuDrag = 0x0123,
        MenuGetObject = 0x0124,
        UnInitMenuPopup = 0x0125,
        MenuCommand = 0x0126,

        ChangeUiState = 0x0127,
        UpdateUiState = 0x0128,
        QueryUiState = 0x0129,
        CtlColorMsgBox = 0x0132,
        CtlColorEdit = 0x0133,
        CtlColorListBox = 0x0134,
        CtlColorBtn = 0x0135,
        CtlColorDlg = 0x0136,
        CtlColorScrollBar = 0x0137,
        CtlColorStatic = 0x0138,
        GetHMenu = 0x01E1,

        MouseFirst = 0x0200,
        MouseMove = 0x0200,
        LButtonDown = 0x0201,
        LButtonUp = 0x0202,
        LButtonDoubleClick = 0x0203,
        RButtonDown = 0x0204,
        RButtonUp = 0x0205,
        RButtonDoubleClick = 0x0206,
        MButtonDown = 0x0207,
        MButtonUp = 0x0208,
        MButtonDoubleClick = 0x0209,

        MouseWheel = 0x020A,

        XButtonDown = 0x020B,
        XButtonUp = 0x020C,
        XButtonDoubleClick = 0x020D,

        MouseHWheel = 0x020E,

        MouseLast = 0x020E,
        ParentNotify = 0x0210,
        EnterMenuLoop = 0x0211,
        ExitMenuLoop = 0x0212,

        NextMenu = 0x0213,
        Sizing = 0x0214,
        CaptureChanged = 0x0215,
        Moving = 0x0216,

        PowerBroadCast = 0x0218,

        DeviceChange = 0x0219,

        MdiCreate = 0x0220,
        MdiDestroy = 0x0221,
        MdiActivate = 0x0222,
        MdiRestore = 0x0223,
        MdiNext = 0x0224,
        MdiMaximize = 0x0225,
        MdiTile = 0x0226,
        MdiCascade = 0x0227,
        MdiIconArrange = 0x0228,
        MdiGetActive = 0x0229,

        MdiSetMenu = 0x0230,
        EnterSizeMove = 0x0231,
        ExitSizeMove = 0x0232,
        DropFiles = 0x0233,
        MdiRefreshMenu = 0x0234,

        Touch = 0x0240,

        ImeSetContext = 0x0281,
        ImeNotify = 0x0282,
        ImeControl = 0x0283,
        ImeCompositionFull = 0x0284,
        ImeSelect = 0x0285,
        ImeChar = 0x0286,

        ImeRequest = 0x0288,

        ImeKeyDown = 0x0290,
        ImeKeyUp = 0x0291,

        MouseHover = 0x02A1,
        MouseLeave = 0x02A3,

        NcMouseHover = 0x02A0,
        NcMouseLeave = 0x02A2,

        WtsSessionChange = 0x02B1,

        TabletFirst = 0x02c0,
        TabletLast = 0x02df,

        Cut = 0x0300,
        Copy = 0x0301,
        Paste = 0x0302,
        Clear = 0x0303,
        Undo = 0x0304,
        RenderFormat = 0x0305,
        RenderAllFormats = 0x0306,
        DestroyClipboard = 0x0307,
        DrawClipboard = 0x0308,
        PaintClipboard = 0x0309,
        VerticalScrollClipboard = 0x030A,
        SizeClipboard = 0x030B,
        AskCbFormatName = 0x030C,
        ChangeCbChain = 0x030D,
        HScrollClipboard = 0x030E,
        QueryNewPalette = 0x030F,
        PaletteIsChanging = 0x0310,
        PaletteChanged = 0x0311,
        HotKey = 0x0312,

        Print = 0x0317,
        PrintClient = 0x0318,

        AppCommand = 0x0319,

        ThemeChanged = 0x031A,

        ClipBoardUpdate = 0x031D,

        DwmComPositionChanged = 0x031E,
        DwmNcRenderingChanged = 0x031F,
        DwmColorizationColorChanged = 0x0320,
        DwmWindowMaximizedChange = 0x0321,

        DwmSendIconicThumbnail = 0x0323,
        DwmSendIconicLivePreviewBitmap = 0x0326,

        GetTitleBarInfoExtended = 0x033F,

        HandheldFirst = 0x0358,
        HandheldLast = 0x035F,

        AfxFirst = 0x0360,
        AfxLast = 0x037F,

        PenWinFirst = 0x0380,
        PenWinLast = 0x038F,

        App = 0x8000,

        User = 0x0400,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOWS_WINDOWS_MESSAGES_FLAGS_H
