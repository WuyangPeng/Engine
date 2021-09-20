///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/19 14:45)

#ifndef SYSTEM_TESTING_HELPER_SUITE_STD_LIB_CONFIG_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_STD_LIB_CONFIG_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class StdLibConfigTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = StdLibConfigTesting;
        using ParentType = UnitTest;

    public:
        explicit StdLibConfigTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void StdLibTest();
        void DinkumwareTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_STD_LIB_CONFIG_TESTING_H
