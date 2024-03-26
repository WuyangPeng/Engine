/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:30)

#ifndef GLUT_MAIN_LOOP_TESTING_GLUT_MAIN_LOOP_H
#define GLUT_MAIN_LOOP_TESTING_GLUT_MAIN_LOOP_H

/// 测试GlutMainLoop和GlutLeaveMainLoop。
namespace GlutMainLoopTesting
{
    void GlutMainLoop(int argc, char** argv);
    void GlutLeaveMainLoop(int argc, char** argv);

    void RenderSceneCallback() noexcept;
    void TimerFunctionCallback(int timer);

    void Init(int argc, char** argv) noexcept;
    void GlutMainLoop() noexcept;
}

#endif  // GLUT_MAIN_LOOP_TESTING_GLUT_MAIN_LOOP_H