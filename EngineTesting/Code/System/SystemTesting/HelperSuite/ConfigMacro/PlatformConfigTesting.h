///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/19 14:44)

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
