///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.5 (2021/06/24 13:17)

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
