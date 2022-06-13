///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 15:35)

#ifndef NETWORK_TESTING_CONFIGURATION_SUITE_ANALYSIS_NETWORK_CONFIGURATION_TESTING_H
#define NETWORK_TESTING_CONFIGURATION_SUITE_ANALYSIS_NETWORK_CONFIGURATION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/Configuration/ConfigurationFwd.h"

namespace Network
{
    class AnalysisNetworkConfigurationTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AnalysisNetworkConfigurationTesting);

        using TestingType = AnalysisNetworkConfiguration;

    private:
        void MainTest();

        void AnalysisNetworkConfigurationTest();
        void GameServerTest(const TestingType& analysisNetworkConfiguration);
        void GameClientTest(const TestingType& analysisNetworkConfiguration);

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_CONFIGURATION_SUITE_ANALYSIS_NETWORK_CONFIGURATION_TESTING_H