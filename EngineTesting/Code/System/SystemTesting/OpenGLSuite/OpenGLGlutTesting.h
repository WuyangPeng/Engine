/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:26)

#ifndef SYSTEM_OPENGL_SUITE_OPENGL_GLUT_TESTING_H
#define SYSTEM_OPENGL_SUITE_OPENGL_GLUT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// SystemOpenGLTesting有OpenGL函数的测试。
    /// GlutMainLoopTesting有函数GlutMainLoop的测试。
    /// 这里只测试GlutInit。
    class OpenGLGlutTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLGlutTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLGlutTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GlutInitTest() noexcept;
    };
}

#endif  // SYSTEM_OPENGL_SUITE_OPENGL_GLUT_TESTING_H