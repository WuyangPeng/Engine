///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:12)

#ifndef NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_PARAMETER_TESTING_H
#define NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_PARAMETER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class ConfigurationParameterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConfigurationParameterTesting;
        using ParentType = UnitTest;

    public:
        explicit ConfigurationParameterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void ParameterTest();
    };
}

#endif  // NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_PARAMETER_TESTING_H