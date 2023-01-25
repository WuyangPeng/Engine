///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/12 23:24)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GLUT_DESTROY_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GLUT_DESTROY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLGlutDestroyTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLGlutDestroyTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLGlutDestroyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DestroyWindowTest();

        static void RenderSceneCallback() noexcept;

    private:
        static int destroyWindowID;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GLUT_DESTROY_TESTING_H