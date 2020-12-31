//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 10:51)

#ifndef SYSTEM_WINDOW_WINDOWS_CODES_FLAGS_H
#define SYSTEM_WINDOW_WINDOWS_CODES_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WindowsKeyCodes
    {
        LButton = VK_LBUTTON,
        RButton = VK_RBUTTON,
        Cancel = VK_CANCEL,
        MButton = VK_MBUTTON,

        XButton1 = VK_XBUTTON1,
        XButton2 = VK_XBUTTON2,

        Back = VK_BACK,
        Tab = VK_TAB,

        Clear = VK_CLEAR,
        Return = VK_RETURN,

        Shift = VK_SHIFT,
        Control = VK_CONTROL,
        Menu = VK_MENU,
        Pause = VK_PAUSE,
        Capital = VK_CAPITAL,

        Kana = VK_KANA,
        Hangeul = VK_HANGEUL,
        Hangul = VK_HANGUL,
        Junja = VK_JUNJA,
        Final = VK_FINAL,
        Hanja = VK_HANJA,
        Kanji = VK_KANJI,

        Escape = VK_ESCAPE,

        Convert = VK_CONVERT,
        NonConvert = VK_NONCONVERT,
        Accept = VK_ACCEPT,
        ModeChance = VK_MODECHANGE,

        Space = VK_SPACE,
        Prior = VK_PRIOR,
        Next = VK_NEXT,
        End = VK_END,
        Home = VK_HOME,
        Left = VK_LEFT,
        Up = VK_UP,
        Right = VK_RIGHT,
        Down = VK_DOWN,
        Select = VK_SELECT,
        Print = VK_PRINT,
        Execute = VK_EXECUTE,
        Snapshot = VK_SNAPSHOT,
        Insert = VK_INSERT,
        Delete = VK_DELETE,
        Help = VK_HELP,

        WindowsKeyCode0 = 0x30,
        WindowsKeyCode1 = 0x31,
        WindowsKeyCode2 = 0x32,
        WindowsKeyCode3 = 0x33,
        WindowsKeyCode4 = 0x34,
        WindowsKeyCode5 = 0x35,
        WindowsKeyCode6 = 0x36,
        WindowsKeyCode7 = 0x37,
        WindowsKeyCode8 = 0x38,
        WindowsKeyCode9 = 0x39,

        A = 0x41,
        B = 0x42,
        C = 0x43,
        D = 0x44,
        E = 0x45,
        F = 0x46,
        G = 0x47,
        H = 0x48,
        I = 0x49,
        J = 0x4A,
        K = 0x4B,
        M = 0x4C,
        N = 0x4D,
        O = 0x4E,
        P = 0x50,
        Q = 0x51,
        R = 0x52,
        S = 0x53,
        T = 0x54,
        U = 0x55,
        V = 0x56,
        W = 0x57,
        X = 0x58,
        Y = 0x59,
        Z = 0x5A,

        LWin = VK_LWIN,
        RWin = VK_RWIN,
        Apps = VK_APPS,

        Sleep = VK_SLEEP,

        Numpad0 = VK_NUMPAD0,
        Numpad1 = VK_NUMPAD1,
        Numpad2 = VK_NUMPAD2,
        Numpad3 = VK_NUMPAD3,
        Numpad4 = VK_NUMPAD4,
        Numpad5 = VK_NUMPAD5,
        Numpad6 = VK_NUMPAD6,
        Numpad7 = VK_NUMPAD7,
        Numpad8 = VK_NUMPAD8,
        Numpad9 = VK_NUMPAD9,
        Multiply = VK_MULTIPLY,
        Add = VK_ADD,
        Separator = VK_SEPARATOR,
        Subtract = VK_SUBTRACT,
        Decimal = VK_DECIMAL,
        Divide = VK_DIVIDE,
        F1 = VK_F1,
        F2 = VK_F2,
        F3 = VK_F3,
        F4 = VK_F4,
        F5 = VK_F5,
        F6 = VK_F6,
        F7 = VK_F7,
        F8 = VK_F8,
        F9 = VK_F9,
        F10 = VK_F10,
        F11 = VK_F11,
        F12 = VK_F12,
        F13 = VK_F13,
        F14 = VK_F14,
        F15 = VK_F15,
        F16 = VK_F16,
        F17 = VK_F17,
        F18 = VK_F18,
        F19 = VK_F19,
        F20 = VK_F20,
        F21 = VK_F21,
        F22 = VK_F22,
        F23 = VK_F23,
        F24 = VK_F24,

        Numlock = VK_NUMLOCK,
        Scroll = VK_SCROLL,

        OemNecEqual = VK_OEM_NEC_EQUAL,

        OemFjJisho = VK_OEM_FJ_JISHO,
        OemFjMasshou = VK_OEM_FJ_MASSHOU,
        OemFjTouroku = VK_OEM_FJ_TOUROKU,
        OemFjLoya = VK_OEM_FJ_LOYA,
        OemFjRoya = VK_OEM_FJ_ROYA,

        LShift = VK_LSHIFT,
        RShift = VK_RSHIFT,
        LControl = VK_LCONTROL,
        RControl = VK_RCONTROL,
        LMenu = VK_LMENU,
        RMenu = VK_RMENU,

        BrowserBack = VK_BROWSER_BACK,
        BrowserForward = VK_BROWSER_FORWARD,
        BrowserRefresh = VK_BROWSER_REFRESH,
        BrowserStop = VK_BROWSER_STOP,
        BrowserSearch = VK_BROWSER_SEARCH,
        BrowserFavorites = VK_BROWSER_FAVORITES,
        BrowserHome = VK_BROWSER_HOME,

        VolumeMute = VK_VOLUME_MUTE,
        VolumeDown = VK_VOLUME_DOWN,
        VolumeUp = VK_VOLUME_UP,
        MediaNextTrack = VK_MEDIA_NEXT_TRACK,
        MediaPrevTrack = VK_MEDIA_PREV_TRACK,
        MediaStop = VK_MEDIA_STOP,
        MediaPlayPause = VK_MEDIA_PLAY_PAUSE,
        LaunchMail = VK_LAUNCH_MAIL,
        LaunchMediaSelect = VK_LAUNCH_MEDIA_SELECT,
        LaunchApp1 = VK_LAUNCH_APP1,
        LaunchApp2 = VK_LAUNCH_APP2,

        Oem1 = VK_OEM_1,
        OemPlus = VK_OEM_PLUS,
        OemComma = VK_OEM_COMMA,
        OemMinus = VK_OEM_MINUS,
        OemPeriod = VK_OEM_PERIOD,
        Oem2 = VK_OEM_2,
        Oem3 = VK_OEM_3,

        Oem4 = VK_OEM_4,
        Oem5 = VK_OEM_5,
        Oem6 = VK_OEM_6,
        Oem7 = VK_OEM_7,
        Oem8 = VK_OEM_8,

        OemAx = VK_OEM_AX,
        Oem102 = VK_OEM_102,
        IcoHelp = VK_ICO_HELP,
        Ico00 = VK_ICO_00,

        ProcessKey = VK_PROCESSKEY,

        IcoClear = VK_ICO_CLEAR,

        Packet = VK_PACKET,

        OemReset = VK_OEM_RESET,
        OemJump = VK_OEM_JUMP,
        OemPa1 = VK_OEM_PA1,
        OemPa2 = VK_OEM_PA2,
        OemPa3 = VK_OEM_PA3,
        OemWsctrl = VK_OEM_WSCTRL,
        OemCusel = VK_OEM_CUSEL,
        OemAttn = VK_OEM_ATTN,
        OemFinish = VK_OEM_FINISH,
        OemCopy = VK_OEM_COPY,
        OemAuto = VK_OEM_AUTO,
        OemEnlw = VK_OEM_ENLW,
        OemBackTab = VK_OEM_BACKTAB,

        Attn = VK_ATTN,
        Crsel = VK_CRSEL,
        Exsel = VK_EXSEL,
        Ereof = VK_EREOF,
        Play = VK_PLAY,
        Zoom = VK_ZOOM,
        Noname = VK_NONAME,
        Pa1 = VK_PA1,
        OemClear = VK_OEM_CLEAR,
    };

    enum class WindowsModifiersCodes
    {
        Control = MK_CONTROL,
        LeftButton = MK_LBUTTON,
        MiddleButton = MK_MBUTTON,
        RightButton = MK_RBUTTON,
        Shift = MK_SHIFT,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class WindowsKeyCodes
    {
        LButton = 0x01,
        RButton = 0x02,
        Cancel = 0x03,
        MButton = 0x04,

        XButton1 = 0x05,
        XButton2 = 0x06,

        Back = 0x08,
        Tab = 0x09,

        Clear = 0x0C,
        Return = 0x0D,

        Shift = 0x10,
        Control = 0x11,
        Menu = 0x12,
        Pause = 0x13,
        Capital = 0x14,

        Kana = 0x15,
        Hangeul = 0x15,
        Hangul = 0x15,
        Junja = 0x17,
        Final = 0x18,
        Hanja = 0x19,
        Kanji = 0x19,

        Escape = 0x1B,

        Convert = 0x1C,
        NonConvert = 0x1D,
        Accept = 0x1E,
        ModeChance = 0x1F,

        Space = 0x20,
        Prior = 0x21,
        Next = 0x22,
        End = 0x23,
        Home = 0x24,
        Left = 0x25,
        Up = 0x26,
        Right = 0x27,
        Down = 0x28,
        Select = 0x29,
        Print = 0x2A,
        Execute = 0x2B,
        Snapshot = 0x2C,
        Insert = 0x2D,
        Delete = 0x2E,
        Help = 0x2F,

        WindowsKeyCode0 = 0x30,
        WindowsKeyCode1 = 0x31,
        WindowsKeyCode2 = 0x32,
        WindowsKeyCode3 = 0x33,
        WindowsKeyCode4 = 0x34,
        WindowsKeyCode5 = 0x35,
        WindowsKeyCode6 = 0x36,
        WindowsKeyCode7 = 0x37,
        WindowsKeyCode8 = 0x38,
        WindowsKeyCode9 = 0x39,

        A = 0x41,
        B = 0x42,
        C = 0x43,
        D = 0x44,
        E = 0x45,
        F = 0x46,
        G = 0x47,
        H = 0x48,
        I = 0x49,
        J = 0x4A,
        K = 0x4B,
        M = 0x4C,
        N = 0x4D,
        O = 0x4E,
        P = 0x50,
        Q = 0x51,
        R = 0x52,
        S = 0x53,
        T = 0x54,
        U = 0x55,
        V = 0x56,
        W = 0x57,
        X = 0x58,
        Y = 0x59,
        Z = 0x5A,

        LWin = 0x5B,
        RWin = 0x5C,
        Apps = 0x5D,

        Sleep = 0x5F,

        Numpad0 = 0x60,
        Numpad1 = 0x61,
        Numpad2 = 0x62,
        Numpad3 = 0x63,
        Numpad4 = 0x64,
        Numpad5 = 0x65,
        Numpad6 = 0x66,
        Numpad7 = 0x67,
        Numpad8 = 0x68,
        Numpad9 = 0x69,
        Multiply = 0x6A,
        Add = 0x6B,
        Separator = 0x6C,
        Subtract = 0x6D,
        Decimal = 0x6E,
        Divide = 0x6F,
        F1 = 0x70,
        F2 = 0x71,
        F3 = 0x72,
        F4 = 0x73,
        F5 = 0x74,
        F6 = 0x75,
        F7 = 0x76,
        F8 = 0x77,
        F9 = 0x78,
        F10 = 0x79,
        F11 = 0x7A,
        F12 = 0x7B,
        F13 = 0x7C,
        F14 = 0x7D,
        F15 = 0x7E,
        F16 = 0x7F,
        F17 = 0x80,
        F18 = 0x81,
        F19 = 0x82,
        F20 = 0x83,
        F21 = 0x84,
        F22 = 0x85,
        F23 = 0x86,
        F24 = 0x87,

        Numlock = 0x90,
        Scroll = 0x91,

        OemNecEqual = 0x92,

        OemFjJisho = 0x92,
        OemFjMasshou = 0x93,
        OemFjTouroku = 0x94,
        OemFjLoya = 0x95,
        OemFjRoya = 0x96,

        LShift = 0xA0,
        RShift = 0xA1,
        LControl = 0xA2,
        RControl = 0xA3,
        LMenu = 0xA4,
        RMenu = 0xA5,

        BrowserBack = 0xA6,
        BrowserForward = 0xA7,
        BrowserRefresh = 0xA8,
        BrowserStop = 0xA9,
        BrowserSearch = 0xAA,
        BrowserFavorites = 0xAB,
        BrowserHome = 0xAC,

        VolumeMute = 0xAD,
        VolumeDown = 0xAE,
        VolumeUp = 0xAF,
        MediaNextTrack = 0xB0,
        MediaPrevTrack = 0xB1,
        MediaStop = 0xB2,
        MediaPlayPause = 0xB3,
        LaunchMail = 0xB4,
        LaunchMediaSelect = 0xB5,
        LaunchApp1 = 0xB6,
        LaunchApp2 = 0xB7,

        Oem1 = 0xBA,
        OemPlus = 0xBB,
        OemComma = 0xBC,
        OemMinus = 0xBD,
        OemPeriod = 0xBE,
        Oem2 = 0xBF,
        Oem3 = 0xC0,

        Oem4 = 0xDB,
        Oem5 = 0xDC,
        Oem6 = 0xDD,
        Oem7 = 0xDE,
        Oem8 = 0xDF,

        OemAx = 0xE1,
        Oem102 = 0xE2,
        IcoHelp = 0xE3,
        Ico00 = 0xE4,

        ProcessKey = 0xE5,

        IcoClear = 0xE6,

        Packet = 0xE7,

        OemReset = 0xE9,
        OemJump = 0xEA,
        OemPa1 = 0xEB,
        OemPa2 = 0xEC,
        OemPa3 = 0xED,
        OemWsctrl = 0xEE,
        OemCusel = 0xEF,
        OemAttn = 0xF0,
        OemFinish = 0xF1,
        OemCopy = 0xF2,
        OemAuto = 0xF3,
        OemEnlw = 0xF4,
        OemBackTab = 0xF5,

        Attn = 0xF6,
        Crsel = 0xF7,
        Exsel = 0xF8,
        Ereof = 0xF9,
        Play = 0xFA,
        Zoom = 0xFB,
        Noname = 0xFC,
        Pa1 = 0xFD,
        OemClear = 0xFE,
    };

    enum class WindowsModifiersCodes
    {
        Control = 0x0008,
        LeftButton = 0x0001,
        MiddleButton = 0x0010,
        RightButton = 0x0002,
        Shift = 0x0004,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOW_WINDOWS_CODES_FLAGS_H
