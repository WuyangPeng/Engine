///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 13:57)

#ifndef FRAMEWORK_HELPER_SUITE_LINUX_FRAME_BUILD_TESTING_H
#define FRAMEWORK_HELPER_SUITE_LINUX_FRAME_BUILD_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class LinuxFrameBuildTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LinuxFrameBuildTesting;
        using ParentType = UnitTest;

    public:
        explicit LinuxFrameBuildTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();
    };
}

#endif  // FRAMEWORK_HELPER_SUITE_LINUX_FRAME_BUILD_TESTING_H