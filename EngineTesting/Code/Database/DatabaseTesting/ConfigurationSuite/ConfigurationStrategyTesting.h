// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/16 18:43)

#ifndef DATABASE_TESTING_CONFIGURATION_SUITE_CONFIGURATION_STRATEGY_TESTING_H
#define DATABASE_TESTING_CONFIGURATION_SUITE_CONFIGURATION_STRATEGY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Database
{
	class ConfigurationStrategyTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ConfigurationStrategyTesting);

	private:
		void MainTest();

		void ConfigurationTest();
		void FlagsOptionTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // DATABASE_TESTING_CONFIGURATION_SUITE_CONFIGURATION_STRATEGY_TESTING_H