/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:41)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_INIT_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_INIT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLInitTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLInitTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLInitTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void OpenGLInitTest();
        void PrintInfoTest() const;
        void OpenGLInfoTest();
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_INIT_TESTING_H