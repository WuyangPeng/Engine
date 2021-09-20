// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/16 18:42)

#ifndef DATABASE_TESTING_CONFIGURATION_SUITE_ANALYSIS_DATABASE_CONFIGURATION_TESTING_H
#define DATABASE_TESTING_CONFIGURATION_SUITE_ANALYSIS_DATABASE_CONFIGURATION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Database
{
	class AnalysisDatabaseConfigurationTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AnalysisDatabaseConfigurationTesting);

	private:
		void MainTest();

		void ConfigurationTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // DATABASE_TESTING_CONFIGURATION_SUITE_ANALYSIS_DATABASE_CONFIGURATION_TESTING_H