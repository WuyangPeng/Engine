///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/13 12:40)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_INIT_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_INIT_TESTING_H

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
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLInitTest();
        void InfoTest();
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_INIT_TESTING_H