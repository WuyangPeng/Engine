///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 19:23)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_TESTING_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackInterface.h"

namespace Framework
{
    class OpenGLGlutProcessOpenGLGlutCallBack : public OpenGLGlutCallBackInterface
    {
    public:
        using ClassType = OpenGLGlutProcessOpenGLGlutCallBack;
        using ParentType = OpenGLGlutCallBackInterface;

    public:
        OpenGLGlutProcessOpenGLGlutCallBack() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };

    class OpenGLGlutProcessTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLGlutProcessTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLGlutProcessTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void SetWindowIDSucceedTest();
        void CallbackSucceedTest();
        void SetMillisecondSucceedTest();

        void DoRunUnitTest() final;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_TESTING_H