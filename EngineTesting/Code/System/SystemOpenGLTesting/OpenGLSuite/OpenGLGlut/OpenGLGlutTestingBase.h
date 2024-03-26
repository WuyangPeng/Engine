/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/15 14:14)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GLUT_TESTING_BASE_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GLUT_TESTING_BASE_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLGlutTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLGlutTestingBase;
        using ParentType = UnitTest;

    public:
        explicit OpenGLGlutTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto width = 800;
        static constexpr auto height = 600;
        static constexpr auto frame = 17;

    protected:
        void GlutInit(bool multiSample) const noexcept;
        void DoCreateWindowTest(int window, int mainWindow) const noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GLUT_TESTING_BASE_H