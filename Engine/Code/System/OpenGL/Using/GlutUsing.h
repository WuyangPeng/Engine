/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/03/01 16:59)

#ifndef SYSTEM_OPENGL_GLUT_USING_H
#define SYSTEM_OPENGL_GLUT_USING_H

namespace System
{
    using RenderSceneCallback = void (*)();
    using ChangeSizeCallback = void (*)(int width, int height);
    using TimerFunctionCallback = void (*)(int timer);
    using SpecialKeysDownCallback = void (*)(int key, int xCoordinate, int yCoordinate);
    using KeyboardDownCallback = void (*)(unsigned char key, int xCoordinate, int yCoordinate);
    using SpecialKeysUpCallback = void (*)(int key, int xCoordinate, int yCoordinate);
    using KeyboardUpCallback = void (*)(unsigned char key, int xCoordinate, int yCoordinate);
    using MouseFunctionCallback = void (*)(int button, int state, int xCoordinate, int yCoordinate);
    using MotionFunctionCallback = void (*)(int xCoordinate, int yCoordinate);
    using PassiveMotionFunctionCallback = void (*)(int xCoordinate, int yCoordinate);
    using IdleFunctionCallback = void (*)();
    using ProcessMenuCallback = void (*)(int menuValue);
    using TerminateCallback = void (*)();
}

#endif  // SYSTEM_OPENGL_GLUT_USING_H
