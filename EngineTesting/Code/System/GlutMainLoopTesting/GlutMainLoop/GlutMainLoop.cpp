///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/04 23:45)

#include "GlutMainLoop.h"
#include "System/Console/ConsoleCreate.h"
#include "System/OpenGL/Flags/GlutFlags.h"
#include "System/OpenGL/OpenGLGlut.h"

#include <iostream>

using std::cout;

void GlutMainLoopTesting::GlutMainLoop(int argc, char** argv)
{
    System::GlutInit(&argc, argv);

    System::GlutInitWindowSize(800, 600);
    System::GlutInitContextVersion(4, 6);
    System::GlutInitWindowPosition(0, 0);
    System::GlutInitDisplayMode(true);

    MAYBE_UNUSED auto windowID = System::GlutCreateWindow("OpenGL Glut Testing");

    System::GlutDisplayFunc(RenderSceneCallback);

    System::GlutSetOption(System::GlutOption::WindowClose, System::EnumCastUnderlying(System::GlutExtension::GlutMainLoopReturns));

    MAYBE_UNUSED const auto result = System::RemoveConsoleCloseButton();

    System::GlutMainLoop();
}

void GlutMainLoopTesting::GlutLeaveMainLoop(int argc, char** argv)
{
    System::GlutInit(&argc, argv);

    System::GlutInitWindowSize(800, 600);
    System::GlutInitContextVersion(4, 6);
    System::GlutInitWindowPosition(0, 0);
    System::GlutInitDisplayMode(true);

    MAYBE_UNUSED auto windowID = System::GlutCreateWindow("OpenGL Glut Testing");

    System::GlutDisplayFunc(RenderSceneCallback);
    System::GlutTimerFunc(2000, TimerFunctionCallback, 1);

    System::GlutSetOption(System::GlutOption::WindowClose, System::EnumCastUnderlying(System::GlutExtension::GlutMainLoopReturns));

    MAYBE_UNUSED const auto result = System::RemoveConsoleCloseButton();

    System::GlutMainLoop();
}

void GlutMainLoopTesting::RenderSceneCallback() noexcept
{
    System::GlutSwapBuffers();
}

void GlutMainLoopTesting::TimerFunctionCallback(int timer)
{
    cout << "窗口被GlutLeaveMainLoop关闭，timer = " << timer << "\n";

    System::GlutLeaveMainLoop();
}