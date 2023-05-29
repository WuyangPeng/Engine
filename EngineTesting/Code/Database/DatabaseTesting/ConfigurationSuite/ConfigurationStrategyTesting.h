///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.10 (2023/05/25 15:10)

#ifndef DATABASE_TESTING_CONFIGURATION_SUITE_CONFIGURATION_STRATEGY_TESTING_H
#define DATABASE_TESTING_CONFIGURATION_SUITE_CONFIGURATION_STRATEGY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Database
{
    class ConfigurationStrategyTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConfigurationStrategyTesting;
        using ParentType = UnitTest;

    public:
        explicit ConfigurationStrategyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void ConfigurationTest();
        void FlagsOptionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // DATABASE_TESTING_CONFIGURATION_SUITE_CONFIGURATION_STRATEGY_TESTING_H