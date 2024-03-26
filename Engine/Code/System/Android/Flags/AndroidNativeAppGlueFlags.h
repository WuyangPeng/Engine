/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:16)

#ifndef SYSTEM_ANDROID_ANDROID_NATIVE_APP_GLUE_FLAGS_H
#define SYSTEM_ANDROID_ANDROID_NATIVE_APP_GLUE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

#ifdef SYSTEM_PLATFORM_ANDROID

    #include <android_native_app_glue.h>

#elif defined(SYSTEM_PLATFORM_WIN32)

    #include "System/Helper/EnumCast.h"
    #include "System/Windows/Flags/WindowsMessagesFlags.h"

#endif  // SYSTEM_PLATFORM_ANDROID

#ifdef SYSTEM_PLATFORM_ANDROID

namespace System
{
    enum class LooperId
    {
        Main = LOOPER_ID_MAIN,
        Input = LOOPER_ID_INPUT,
        User = LOOPER_ID_USER,
    };
}

#else  // !SYSTEM_PLATFORM_ANDROID

namespace System
{
    enum class LooperId
    {
        Main = 1,
        Input = 2,
        User = 3,
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

#ifdef SYSTEM_PLATFORM_ANDROID

namespace System
{
    enum class AppCommandType
    {
        InputChanged = APP_CMD_INPUT_CHANGED,
        InitWindow = APP_CMD_INIT_WINDOW,
        TermWindow = APP_CMD_TERM_WINDOW,
        WindowResized = APP_CMD_WINDOW_RESIZED,
        WindowRedrawNeeded = APP_CMD_WINDOW_REDRAW_NEEDED,
        ContentRectChanged = APP_CMD_CONTENT_RECT_CHANGED,
        GainedFocus = APP_CMD_GAINED_FOCUS,
        LostFocus = APP_CMD_LOST_FOCUS,
        ConfigChanged = APP_CMD_CONFIG_CHANGED,
        LowMemory = APP_CMD_LOW_MEMORY,
        Start = APP_CMD_START,
        Resume = APP_CMD_RESUME,
        SaveState = APP_CMD_SAVE_STATE,
        Pause = APP_CMD_PAUSE,
        Stop = APP_CMD_STOP,
        Destroy = APP_CMD_DESTROY,
    };
}

#elif defined(SYSTEM_PLATFORM_WIN32)

namespace System
{
    enum class AppCommandType
    {
        InputChanged = 0,
        InitWindow = EnumCastUnderlying(WindowsMessages::Create),
        TermWindow = EnumCastUnderlying(WindowsMessages::Close),
        WindowResized = EnumCastUnderlying(WindowsMessages::Size),
        WindowRedrawNeeded = -4,
        ContentRectChanged = -5,
        GainedFocus = -6,
        LostFocus = -7,
        ConfigChanged = -8,
        LowMemory = -9,
        Start = -10,
        Resume = -11,
        SaveState = -12,
        Pause = -13,
        Stop = -14,
        Destroy = EnumCastUnderlying(WindowsMessages::Destroy),
    };
}

#else  // !SYSTEM_PLATFORM_ANDROID && !SYSTEM_PLATFORM_WIN32

namespace System
{
    enum class AppCommandType
    {
        InputChanged = 0,
        InitWindow = 1,
        TermWindow = 2,
        WindowResized = 3,
        WindowRedrawNeeded = 4,
        ContentRectChanged = 5,
        GainedFocus = 6,
        LostFocus = 7,
        ConfigChanged = 8,
        LowMemory = 9,
        Start = 10,
        Resume = 11,
        SaveState = 12,
        Pause = 13,
        Stop = 14,
        Destroy = 15,
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_NATIVE_APP_GLUE_FLAGS_H
