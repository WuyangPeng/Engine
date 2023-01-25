///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/15 19:13)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_ERROR_DESCRIPTION_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_ERROR_DESCRIPTION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLErrorDescriptionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLErrorDescriptionTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLErrorDescriptionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLErrorDescriptionTest();
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_ERROR_DESCRIPTION_TESTING_H