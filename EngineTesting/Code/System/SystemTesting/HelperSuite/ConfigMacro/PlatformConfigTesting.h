///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/14 14:49)

#ifndef SYSTEM_TESTING_HELPER_SUITE_PLATFORM_CONFIG_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_PLATFORM_CONFIG_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class PlatformConfigTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = PlatformConfigTesting;
        using ParentType = UnitTest;

    public:
        explicit PlatformConfigTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void PlatformTest();
        void Win32Test() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_PLATFORM_CONFIG_TESTING_H
