/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/14 09:13)

#include "GlutMainLoop.h"
#include "System/Console/ConsoleCreate.h"
#include "System/Helper/Tools.h"
#include "System/OpenGL/Flags/GlutFlags.h"
#include "System/OpenGL/OpenGLGlut.h"

#include <iostream>

void GlutMainLoopTesting::Init(int argc, char** argv) noexcept
{
    System::GlutInit(&argc, argv);

    System::GlutInitWindowSize(800, 600);
    System::GlutInitContextVersion(4, 6);
    System::GlutInitWindowPosition(0, 0);
    System::GlutInitDisplayMode(true);
}

void GlutMainLoopTesting::GlutMainLoop() noexcept
{
    System::GlutDisplayFunc(RenderSceneCallback);

    GlutSetOption(System::GlutOption::WindowClose, System::GlutExtension::GlutMainLoopReturns);

    const auto result = System::RemoveConsoleCloseButton();

    System::GlutMainLoop();

    System::UnusedFunction(result);
}

void GlutMainLoopTesting::GlutMainLoop(int argc, char** argv)
{
    Init(argc, argv);

    if (const auto windowId = System::GlutCreateWindow("OpenGL Glut Testing");
        0 < windowId)
    {
        GlutMainLoop();
    }
}

void GlutMainLoopTesting::GlutLeaveMainLoop(int argc, char** argv)
{
    Init(argc, argv);

    if (const auto windowId = System::GlutCreateWindow("OpenGL Glut Testing Automatic Shutdown");
        0 < windowId)
    {
        System::GlutTimerFunc(2000, TimerFunctionCallback, 1);

        GlutMainLoop();
    }
}

void GlutMainLoopTesting::RenderSceneCallback() noexcept
{
    System::GlutSwapBuffers();
}

void GlutMainLoopTesting::TimerFunctionCallback(int timer)
{
    std::cout << "窗口被GlutLeaveMainLoop关闭，timer = " << timer << "\n";

    System::GlutLeaveMainLoop();
}
