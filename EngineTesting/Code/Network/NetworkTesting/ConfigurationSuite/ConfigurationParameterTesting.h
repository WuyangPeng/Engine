// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 10:38)

#ifndef NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_PARAMETER_TESTING_H
#define NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_PARAMETER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class ConfigurationParameterTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ConfigurationParameterTesting);

	private:
		void MainTest();

		void ParameterTest();

		void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_PARAMETER_TESTING_H