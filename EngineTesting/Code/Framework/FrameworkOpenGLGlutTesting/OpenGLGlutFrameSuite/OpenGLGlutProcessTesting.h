///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 15:47)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_TESTING_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
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
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OpenGLGlutProcessTesting);

    private:
        void MainTest();
        void SetWindowIDSucceedTest();
        void CallbackSucceedTest();
        void SetMillisecondSucceedTest();

        void DoRunUnitTest() final;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_TESTING_H