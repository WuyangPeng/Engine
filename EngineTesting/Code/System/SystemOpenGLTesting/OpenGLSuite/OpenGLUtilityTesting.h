///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/06/29 19:37)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_UTILITY_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_UTILITY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLUtilityTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLUtilityTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLUtilityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void VersionTest();
        void OpenGLSupportsExtensionTest();
        void WglSupportsExtensionTest();
        void OpenGLErrorDescriptionTest();
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_UTILITY_TESTING_H