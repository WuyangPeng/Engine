///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.5 (2021/06/24 13:06)

#ifndef SYSTEM_OPENGL_GLUT_KEY_CODES_FLAGS_H
#define SYSTEM_OPENGL_GLUT_KEY_CODES_FLAGS_H

#include "System/Helper/ConfigMacro.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/Helper/Platform.h"
#include "System/OpenGL/Using/OpenGLUsing.h"

#if defined(SYSTEM_USE_GLUT) && defined(WIN32)

    #include "System/Helper/PragmaWarning/Freeglut.h"

namespace System
{
    enum class GlutKeyCodes
    {
        F1 = GLUT_KEY_F1,
        F2 = GLUT_KEY_F2,
        F3 = GLUT_KEY_F3,
        F4 = GLUT_KEY_F4,
        F5 = GLUT_KEY_F5,
        F6 = GLUT_KEY_F6,
        F7 = GLUT_KEY_F7,
        F8 = GLUT_KEY_F8,
        F9 = GLUT_KEY_F9,
        F10 = GLUT_KEY_F10,
        F11 = GLUT_KEY_F11,
        F12 = GLUT_KEY_F12,
        Left = GLUT_KEY_LEFT,
        Up = GLUT_KEY_UP,
        Right = GLUT_KEY_RIGHT,
        Down = GLUT_KEY_DOWN,
        PageUp = GLUT_KEY_PAGE_UP,
        PageDown = GLUT_KEY_PAGE_DOWN,
        Home = GLUT_KEY_HOME,
        End = GLUT_KEY_END,
        Insert = GLUT_KEY_INSERT,
        Escape = 0x1B,
        Delete = 0x2E,
        Backspace = 0x08,
        Tab = 0x09,
        Enter = 0x0D,
        Return = 0x0D,
    };

    enum class GlutModifiersCodes
    {
        Shift = GLUT_ACTIVE_SHIFT,
        Control = GLUT_ACTIVE_CTRL,
        Alt = GLUT_ACTIVE_ALT,
        LeftButton = GLUT_LEFT_BUTTON,
        MiddleButton = GLUT_MIDDLE_BUTTON,
        RightButton = GLUT_RIGHT_BUTTON,
        Up = GLUT_UP,
        Down = GLUT_DOWN,
    };
}

#else  // !defined(SYSTEM_USE_GLUT) || !defined(WIN32)

namespace System
{
    enum class GlutKeyCodes
    {
        F1 = 0x0001,
        F2 = 0x0002,
        F3 = 0x0003,
        F4 = 0x0004,
        F5 = 0x0005,
        F6 = 0x0006,
        F7 = 0x0007,
        F8 = 0x0008,
        F9 = 0x0009,
        F10 = 0x000A,
        F11 = 0x000B,
        F12 = 0x000C,
        Left = 0x0064,
        Up = 0x0065,
        Right = 0x0066,
        Down = 0x0067,
        PageUp = 0x0068,
        PageDown = 0x0069,
        Home = 0x006A,
        End = 0x006B,
        Insert = 0x006C,
        Escape = 0x1B,
        Delete = 0x2E,
        Backspace = 0x08,
        Tab = 0x09,
        Enter = 0x0D,
        Return = 0x0D,
    };

    enum class GlutModifiersCodes
    {
        Shift = 0x0001,
        Control = 0x0002,
        LeftButton = 0x0000,
        MiddleButton = 0x0001,
        RightButton = 0x0002,
        Up = 0x0001,
        Down = 0x0000,
    };

}

#endif  // defined(SYSTEM_USE_GLUT) && defined(WIN32)

#endif  // SYSTEM_OPENGL_GLUT_KEY_CODES_FLAGS_H
