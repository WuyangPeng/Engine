///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/12 23:22)

#ifndef GLUT_MAIN_LOOP_TESTING_GLUT_MAIN_LOOP_H
#define GLUT_MAIN_LOOP_TESTING_GLUT_MAIN_LOOP_H

namespace GlutMainLoopTesting
{
    void GlutMainLoop(int argc, char** argv);
    void GlutLeaveMainLoop(int argc, char** argv);

    void RenderSceneCallback() noexcept;
    void TimerFunctionCallback(int timer);
}

#endif  // GLUT_MAIN_LOOP_TESTING_GLUT_MAIN_LOOP_H