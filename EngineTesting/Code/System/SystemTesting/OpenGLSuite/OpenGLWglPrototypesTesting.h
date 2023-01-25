///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/12 23:12)

#ifndef SYSTEM_OPENGL_SUITE_OPENGL_WGL_PROTOTYPES_TESTING_H
#define SYSTEM_OPENGL_SUITE_OPENGL_WGL_PROTOTYPES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLWglPrototypesTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLWglPrototypesTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLWglPrototypesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_OPENGL_SUITE_OPENGL_WGL_PROTOTYPES_TESTING_H