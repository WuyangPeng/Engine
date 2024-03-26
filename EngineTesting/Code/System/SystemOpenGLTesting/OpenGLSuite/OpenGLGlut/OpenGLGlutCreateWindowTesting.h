/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:36)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GLUT_CREATE_WINDOW_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GLUT_CREATE_WINDOW_TESTING_H

#include "OpenGLGlutTestingBase.h"

namespace System
{
    /// GlutMainLoop和GlutLeaveMainLoop在GlutMainLoopTesting中进行测试。
    class OpenGLGlutCreateWindowTesting final : public OpenGLGlutTestingBase
    {
    public:
        using ClassType = OpenGLGlutCreateWindowTesting;
        using ParentType = OpenGLGlutTestingBase;

    public:
        explicit OpenGLGlutCreateWindowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateWindowTest();
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GLUT_CREATE_WINDOW_TESTING_H