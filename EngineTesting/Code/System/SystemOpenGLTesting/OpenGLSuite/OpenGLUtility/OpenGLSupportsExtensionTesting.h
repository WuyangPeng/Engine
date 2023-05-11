///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/15 19:13)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SUPPORTS_EXTENSION_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SUPPORTS_EXTENSION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLSupportsExtensionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLSupportsExtensionTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLSupportsExtensionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLSupportsExtensionTest();
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SUPPORTS_EXTENSION_TESTING_H