///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/11 10:52)

#ifndef NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_SUB_STRATEGY_TESTING_H
#define NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_SUB_STRATEGY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class ConfigurationSubStrategyTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConfigurationSubStrategyTesting;
        using ParentType = UnitTest;

    public:
        explicit ConfigurationSubStrategyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void SubStrategyTest();
    };
}

#endif  // NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_SUB_STRATEGY_TESTING_H