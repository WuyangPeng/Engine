///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 10:12)

#ifndef NETWORK_TESTING_CONFIGURATION_SUITE_ANALYSIS_NETWORK_CONFIGURATION_TESTING_H
#define NETWORK_TESTING_CONFIGURATION_SUITE_ANALYSIS_NETWORK_CONFIGURATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/Configuration/ConfigurationFwd.h"

namespace Network
{
    class AnalysisNetworkConfigurationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AnalysisNetworkConfigurationTesting;
        using ParentType = UnitTest;

        using TestingType = AnalysisNetworkConfiguration;

    public:
        explicit AnalysisNetworkConfigurationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void AnalysisNetworkConfigurationTest();
        void GameServerTest(const TestingType& analysisNetworkConfiguration);
        void GameClientTest(const TestingType& analysisNetworkConfiguration);

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_CONFIGURATION_SUITE_ANALYSIS_NETWORK_CONFIGURATION_TESTING_H