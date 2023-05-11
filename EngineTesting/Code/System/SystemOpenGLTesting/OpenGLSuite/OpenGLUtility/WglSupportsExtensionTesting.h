///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/15 19:14)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_WGL_SUPPORTS_EXTENSION_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_WGL_SUPPORTS_EXTENSION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WglSupportsExtensionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WglSupportsExtensionTesting;
        using ParentType = UnitTest;

    public:
        explicit WglSupportsExtensionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WglSupportsExtensionTest();
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_WGL_SUPPORTS_EXTENSION_TESTING_H