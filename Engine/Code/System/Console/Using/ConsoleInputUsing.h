//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 15:30)

#ifndef SYSTEM_CONSOLE_CONSOLE_INPUT_USING_H
#define SYSTEM_CONSOLE_CONSOLE_INPUT_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ConsoleKeyEventRecord = KEY_EVENT_RECORD;
    using ConsoleKeyEventRecordPtr = PKEY_EVENT_RECORD;
    using ConsoleMouseEventRecord = MOUSE_EVENT_RECORD;
    using ConsoleMouseEventRecordPtr = PMOUSE_EVENT_RECORD;
    using ConsoleBufferSizeRecord = WINDOW_BUFFER_SIZE_RECORD;
    using ConsoleBufferSizeRecordPtr = PWINDOW_BUFFER_SIZE_RECORD;
    using ConsoleMenuEventRecord = MENU_EVENT_RECORD;
    using ConsoleMenuEventRecordPtr = PMENU_EVENT_RECORD;
    using ConsoleFocusEventRecord = FOCUS_EVENT_RECORD;
    using ConsoleFocusEventRecordPtr = PFOCUS_EVENT_RECORD;
    using ConsoleInputRecord = INPUT_RECORD;
    using ConsoleInputRecordPtr = PINPUT_RECORD;

#else  // !SYSTEM_PLATFORM_WIN32

    struct ConsoleKeyEventRecord
    {
        int bKeyDown;
        uint16_t wRepeatCount;
        uint16_t wVirtualKeyCode;
        uint16_t wVirtualScanCode;
        union
        {
            wchar_t UnicodeChar;
            char AsciiChar;
        } uChar;
        uint32_t dwControlKeyState;
    };
    using ConsoleKeyEventRecordPtr = ConsoleKeyEventRecord*;

    struct ConsoleMouseEventRecord
    {
        ConsoleCoord dwMousePosition;
        uint32_t dwButtonState;
        uint32_t dwControlKeyState;
        uint32_t dwEventFlags;
    };
    using ConsoleMouseEventRecordPtr = ConsoleMouseEventRecord*;

    struct ConsoleBufferSizeRecord
    {
        ConsoleCoord dwSize;
    };
    using ConsoleBufferSizeRecordPtr = ConsoleBufferSizeRecord*;

    struct ConsoleMenuEventRecord
    {
        uint32_t dwCommandId;
    };

    using ConsoleMenuEventRecordPtr = ConsoleMenuEventRecord*;

    struct ConsoleFocusEventRecord
    {
        int bSetFocus;
    };
    using ConsoleFocusEventRecordPtr = ConsoleFocusEventRecord*;

    struct ConsoleInputRecord
    {
        uint16_t EventType;
        union
        {
            ConsoleKeyEventRecord KeyEvent;
            ConsoleMouseEventRecord MouseEvent;
            ConsoleBufferSizeRecord WindowBufferSizeEvent;
            ConsoleMenuEventRecord MenuEvent;
            ConsoleFocusEventRecord FocusEvent;
        } Event;
    };
    using ConsoleInputRecordPtr = ConsoleInputRecord*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CONSOLE_CONSOLE_INPUT_USING_H