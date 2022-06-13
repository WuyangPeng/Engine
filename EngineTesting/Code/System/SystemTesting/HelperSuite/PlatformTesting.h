///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 0:49)

#ifndef SYSTEM_TESTING_HELPER_SUITE_PLATFORM_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_PLATFORM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class PlatformTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = PlatformTesting;
        using ParentType = UnitTest;

    public:
        explicit PlatformTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_PLATFORM_TESTING_H
