// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 10:37)

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
		void GameServerTest(TestingType& analysisNetworkConfiguration);
		void GameClientTest(TestingType& analysisNetworkConfiguration);

		virtual void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_CONFIGURATION_SUITE_ANALYSIS_NETWORK_CONFIGURATION_TESTING_H