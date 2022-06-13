///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/14 15:49)

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