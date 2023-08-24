///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 14:06)

#ifndef FRAMEWORK_HELPER_SUITE_MACINTOSH_FRAME_BUILD_TESTING_H
#define FRAMEWORK_HELPER_SUITE_MACINTOSH_FRAME_BUILD_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class MacintoshFrameBuildTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MacintoshFrameBuildTesting;
        using ParentType = UnitTest;

    public:
        explicit MacintoshFrameBuildTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest() noexcept;
    };
}

#endif  // FRAMEWORK_HELPER_SUITE_MACINTOSH_FRAME_BUILD_TESTING_H