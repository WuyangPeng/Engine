///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 15:35)

#ifndef NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_STRATEGY_TESTING_H
#define NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_STRATEGY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class ConfigurationStrategyTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConfigurationStrategyTesting;
        using ParentType = UnitTest;

    public:
        explicit ConfigurationStrategyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void DefaultTest();
        void ServerTest();
        void ClientTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_STRATEGY_TESTING_H