///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 16:53)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_FRAME_BUILD_TESTING_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_FRAME_BUILD_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class OpenGLGlutFrameBuildTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLGlutFrameBuildTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLGlutFrameBuildTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_FRAME_BUILD_TESTING_H